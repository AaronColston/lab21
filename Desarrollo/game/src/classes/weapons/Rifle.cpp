#include "Rifle.h"
#include "Player.h"
#include "WorldInstance.h"

Rifle::Rifle()
{
    //ctor
    id=2;
    this->Weapon::setAmmo(1000);
    m_cadence = 0.04;
}

Rifle::~Rifle()
{
    //dtor
}

////////////
void Rifle::shoot()
{   //cout<<"disparo difre"<<endl;
    Scene::Instance()->createProjectile(World->getMainPlayer()->getPosition(), World->getMainPlayer()->getRotation().y, "rifleBullet");
    NetInstance->sendBroadcast(ID_PROJECTILE_CREATE, World->getMainPlayer()->getPosition(),World->getMainPlayer()->getRotation().y, "rifleBullet"); // Enviamos mensaje para crear projectil
}

////////////
void Rifle::reload()
{
    // TODO
}
