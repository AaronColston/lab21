#include "Scene.h"
#include "WorldInstance.h"
#include "Projectile.h"
#include "SpeedBoost.h"
#include "Medkit.h"
#include "Consumable.h"
#include "AmmoGun.h"
#include "CShotgun.h"
#include "CRifle.h"

Scene* Scene::Instance()
{
  static Scene instance;

  return &instance;
}

Scene::Scene()
{
    //ctor

}

void Scene::Init()
{
    /**********************************/
    if (NetInstance->isMultiplayer())
    {
        if (NetInstance->isServer())
            GEInstance->addMessageLine(L"Pulsa intro cuando esten todos los jugadores");
        else
            GEInstance->addMessageLine(L"Esperando a que el servidor de la partida inicie el juego");
        // En startGame solo se inicia si es el servidor
        while (!NetInstance->getGameStarted() && GEInstance->isRunning())
        {
            GEInstance->draw();
            NetInstance->update();
            if (GEInstance->receiver.isKeyDown(KEY_RETURN))
                NetInstance->startGame();
        }
    }
    GEInstance->addMessageLine(L"Partida iniciada");
    /**********************************/

    // Creacion de Mundo
    entities[0]=GEInstance->createDoor(0, true, 43.5, 0, 135.9);
    entities[1]=GEInstance->createDoor(3, false, 170, 0, 0); // false
    sector[0]=entities[1];


    // Generadores
    entities[2]=GEInstance->createGenerator(0, false, -50, 0, -50); // false
    ((Generator*)entities[2])->setSector(sector, 1);

    // Llaves
    llave=GEInstance->createMagnetKey(0, 50, 0, 350);
    llaveCogida=false;

    // Gun
    gun = createGun(0,0,0); // Creo el arma inicial del player
    createAmmoGun(80, 10, 100);

    // Shotgun
    shotgun = createShotgun(0,0,0);

    // Rifle
    rifle = createRifle(0,0,0);

    // Creaci�n de jugador

    mainPlayer = GEInstance->createMainPlayer(gun);
    mainPlayer->setPosition(dwe::vec3f(0-((NetInstance->getParticipantOrder()-1)*30),24,-250));
    mainPlayer->setLife(100);
    World->setMainPlayer(mainPlayer);
    cout << "Barra de vida: " << mainPlayer->getLife() << endl;

    ////////////////////////////////
    //         Enemigos           //
    ////////////////////////////////

    // Creaci�n de enemigo Humanoide
    enemyHumanoid = GEInstance->createEnemyHumanoid();
    //enemyHumanoid->setPosition(dwe::vec3f(43.5,24,-100));
    enemyHumanoid->setPosition(dwe::vec3f(400,24,100));
    enemyHumanoid->setRotation(dwe::vec3f(0, 90.f, 0));

    // Creaci�n de enemigo Dog
    enemyDog = GEInstance->createEnemyDog();
    enemyDog->setPosition(dwe::vec3f(-50,-170,100));

    //Creaci�n fov
    fovnode = GEInstance->createNode("media/fov");
    //fovnode->setMaterialFlag(EMF_WIREFRAME, true);
    fovnode->setPosition(enemyHumanoid->getPosition());
    fovnode->setRotation(enemyHumanoid->getRotation());

    //Creaci�n de objeto perception
    percep = new Perception();
    pathp = new Pathplanning();
    /**** Special nodes ****/
    selector1 = new Selector;
    sequence1 = new Sequence;
    /**** Tasks ****/
    path = new PathplanningTask(pathp, mainPlayer, enemyHumanoid, fovnode);
    perc = new PerceptionTask(percep, mainPlayer, enemyHumanoid, fovnode, path);
    patrol = new PatrolTask(enemyHumanoid, fovnode);
    /**** Creating the tree ****/

    selector1->addChild(sequence1);
    selector1->addChild(patrol);

    sequence1->addChild(perc);
    sequence1->addChild(path);

    //Joint try
    joint_try = GEInstance->createNode("media/the101010box");   //ESTAS SON LAS BUENAS
    joint_try->setPosition(dwe::vec3f(0,10,120));
    bjoint = new EntityPhysics();
    bjoint->createJointBody(dwe::vec3f(0,10,120)); // createJointBody(dwe::vec3f(0,10,120));

    //CAMERA (nodo padre, posici�n, directi�n)
    camera1 = GEInstance->getSMGR()->addCameraSceneNode(0,  vector3df(0,0,0), vector3df(mainPlayer->getPosition().x,mainPlayer->getPosition().y,mainPlayer->getPosition().z));
    GEInstance->getSMGR()->setActiveCamera(camera1); //Activar c�mara

    // Triggers -> 0 Door, 1 Generator
    triggers[0]=GEInstance->createTrigger(0, 43.5, 0, 135.9);
    triggers[1]=GEInstance->createTrigger(0, 170, 0, 0);
    triggers[2]=GEInstance->createTrigger(1, -50, 0, -50);

    //rmm Cheat: la primera vez que creo el projectile va muy lento, no se pq
    createProjectile(dwe::vec3f(1.0, 1.0, 1.0), 0.5);
    deleteProjectile(0);
    timeLastProjectil = 0;
}

Scene::~Scene()
{
    //dtor
}

void Scene::Update()
{
    for(int cont=0; cont<NUM_ENTITIES; cont++)
        entities[cont]->update();
    GEInstance->updateCamera(mainPlayer->getPosition());
    mainPlayer->readEvents(); // Read keyboard and mouse inputs for de player
    selector1->run();  // Run Behavior Tree

    // comprobamos si dispara
    if((World->getTimeElapsed() - timeLastProjectil)> 200 && GEInstance->receiver.isLeftButtonPressed()){
        NetInstance->sendBroadcast(ID_PROJECTILE_CREATE, mainPlayer->getPosition(), mainPlayer->getRotation().y); // Enviamos mensaje para crear projectil
        if (mainPlayer->getCurrentWeaponType() == eGun && mainPlayer->getAmmo(0) > 0) //
        {
            NetInstance->sendBroadcast(ID_PROJECTILE_CREATE, mainPlayer->getPosition(), mainPlayer->getRotation().y); // Enviamos mensaje para crear projectil

            createProjectile(mainPlayer->getPosition(), mainPlayer->getRotation().y);
            timeLastProjectil = World->getTimeElapsed();

            mainPlayer->setAmmo(0, mainPlayer->getAmmo(0)-1); //
        }//
    }
    mainPlayer->update(shotgun, rifle); //Posici�n actualizada de Irrlicht Player
    updateProjectiles();
    updateConsumables(mainPlayer);
    updatePlayerWeapons(mainPlayer, mainPlayer->getPlayerWeapons());

    //update box of box2d
    joint_try->setPosition(dwe::vec3f(bjoint->getPosEntity().x,bjoint->getPosEntity().y,bjoint->getPosEntity().z));
    // Coger la llave
    if(!llaveCogida)
    {
        if(mainPlayer->getNode()->intersects(llave->getNode()->getNode()))
        {
            llaveCogida=true;
            mainPlayer->setMKeys(llave->getId());
            delete llave;
            llave = 0;
        }
    }

    // TriggerSystem
    for(int i=0; i<3; i++){
        if(mainPlayer->getNode()->intersects(triggers[i]->getNode()->getNode()))
        {
            if(GEInstance->receiver.isKeyDown(KEY_SPACE))
            {
                if(i==2)
                {
                    if(mainPlayer->getMKey(((Generator*)entities[i])->getNum()))
                        triggers[i]->triggered(entities[i]);
                }
                else if(i==0 || i==1)
                    triggers[i]->triggered(entities[i]);
            }
        }
    }
    //rmm:cheat, cojo todo
    if (GEInstance->receiver.isKeyDown(KEY_KEY_C))
    {
        // Cojo llave
        if(llave!=0)
        {
            llaveCogida=true;
            mainPlayer->setMKeys(llave->getId());
        }

        //Activo todo
        for(int i=0; i<3; i++)
        {
            if(i==2)
            {
                if(mainPlayer->getMKey(((Generator*)entities[i])->getNum()))
                    triggers[i]->triggered(entities[i]);
            }
            else if(i==0 || i==1)
                triggers[i]->triggered(entities[i]);
        }
    }
}


////////////
void Scene::updateProjectiles()
{
    unsigned int i=0;
    while(i<m_projectiles.size())
    {
        m_projectiles[i]->update();
        if (m_projectiles[i]->getCollides())
        {
            delete m_projectiles[i];
            m_projectiles.erase(m_projectiles.begin()+i);
        }
        else
            i++;
    }
}

////////////
void Scene::deleteProjectile(unsigned int i)
{
    if (i<m_projectiles.size())
    {
        delete m_projectiles[i];
        m_projectiles.erase(m_projectiles.begin()+i);
    }
}


////////////
void Scene::createProjectile(dwe::vec3f origin, float angle)
{
    m_projectiles.push_back(GEInstance->createProjectile(origin, angle));
}

////////////
void Scene::updateConsumables(Player* mainPlayer)
{
    unsigned int i=0;
    while(i<m_consumables.size())
    {
        m_consumables[i]->update(mainPlayer);
        if (m_consumables[i]->getIsTaken())
        {
            delete m_consumables[i];
            m_consumables.erase(m_consumables.begin()+i);
        }
        else
            i++;
    }
}

void Scene::updatePlayerWeapons(Player* mainplayer, Firearm** weapons)
{
    if  (mainplayer->getCurrentWeaponType() == eGun)
    {
        weapons[0]->setPosition(dwe::vec3f(mainplayer->getPosition().x - 20, 20, mainplayer->getPosition().z));

    }
    else if (mainplayer->getCurrentWeaponType() == eShotgun)
    {
        weapons[1]->setPosition(dwe::vec3f(mainplayer->getPosition().x - 20, 20, mainplayer->getPosition().z));
    }
    else if (mainplayer->getCurrentWeaponType() == eRifle)
    {
        weapons[2]->setPosition(dwe::vec3f(mainplayer->getPosition().x - 20, 20, mainplayer->getPosition().z));
    }
}

////////////
void Scene::createSpeedBoost(float px, float py, float pz)
{
    m_consumables.push_back(GEInstance->createSpeedBoost(px, py, pz));

    //GEInstance->createSpeedBoost(px, py, pz);

}

////////////
void Scene::createMedkit(float px, float py, float pz)
{
    m_consumables.push_back(GEInstance->createMedkit(px, py, pz));
    //GEInstance->createMedkit(px, py, pz);
}

////////////
void Scene::createCShotgun(float px, float py, float pz)
{
    m_consumables.push_back(GEInstance->createCShotgun(px, py, pz));
    //GEInstance->createCShotgun(px, py, pz);
}

////////////
void Scene::createCRifle(float px, float py, float pz)
{
    m_consumables.push_back(GEInstance->createCRifle(px, py, pz));
    //GEInstance->createCShotgun(px, py, pz);
}

////////////
void Scene::createAmmoGun(float px, float py, float pz)
{
    m_consumables.push_back(GEInstance->createAmmoGun(px, py, pz));
    //GEInstance->createAmmoGun(px, py, pz);
}

////////////
Gun* Scene::createGun(float px, float py, float pz)
{
    return GEInstance->createGun(px, py, pz);
}

////////////
Shotgun* Scene::createShotgun(float px, float py, float pz)
{
    GEInstance->createShotgun(px, py, pz);
}

////////////
Rifle* Scene::createRifle(float px, float py, float pz)
{
    GEInstance->createRifle(px, py, pz);
}

