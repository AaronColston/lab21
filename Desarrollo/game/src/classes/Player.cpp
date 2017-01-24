#include "Player.h"
#include "WorldInstance.h"

Player::Player(Gun* gun)
{

    setClassID(CLASS_PLAYER_ID);
    m_mKeys[0]=false;
    m_medkits = 0;
    m_timeMedkit = 2000;
    m_timeGivingStuff = 1000;
    m_timeWeaponSwap = 1000;
    m_hasGun = true;
    m_weapons[0] = gun;
    m_weapons[1] = 0;
    m_weapons[2] = 0;
    m_hasShotgun = false;
    m_hasRifle = false;
    m_currentWeaponType = eGun;
    m_currentWeapon = m_weapons[0];

}

Player::~Player()
{
    //dtor
}

/////////////
void Player::update(Shotgun* shotgun, Rifle* rifle)
{
    Drawable::setPosition(dwe::vec3f(getPosEntity().x, getPosition().y, getPosEntity().z));

    if (m_hasShotgun)
    {
        m_weapons[1] = shotgun;

    }
    else if (m_hasRifle)
    {
        m_weapons[2] = rifle;
    }

}

/////////////
void Player::setNode(dwe::Node* n)
{
    Drawable::setNode(n);
    createDynamicBody(getPosition());
}

/////////////
void Player::setPosition(dwe::vec3f p)
{
    setPosEntity(p, getRotation().y);
    Drawable::setPosition(p);
}

////////////////////
const char* Player::getNetObjectID() const
{
    return "Player";
}

/////////////
void Player::render()
{
    // TODO
}

/////////////
void Player::shoot()
{
    //TODO
}

/////////////
FirearmKind Player::getCurrentWeaponType() { return m_currentWeaponType; }
Firearm* Player::getCurrentWeapon() { return m_currentWeapon; }
Firearm** Player::getPlayerWeapons() { return m_weapons; }
bool Player::getHasShotgun() { return m_hasShotgun; }
bool Player::getHasRifle() { return m_hasRifle; }

/////////////
void Player::addWeapon(Consumable* weapon, FirearmKind type)
{

    if (!m_hasShotgun && type == eShotgun)
    {
        m_hasShotgun = true;
        cout << "temgo shotgun" << endl;
    }

    if (!m_hasRifle && type == eRifle)
    {

        m_hasRifle = true;
        cout << "tengo rifle" << endl;
    }


}

/////////////
void Player::swapCurrentWeapon()
{
    if (m_currentWeaponType == eGun)
    {

        if (m_hasShotgun)
        {
            m_currentWeapon = m_weapons[1];

            m_currentWeaponType = eShotgun;
        }


        else if (m_hasRifle)
        {
            m_currentWeapon = m_weapons[2];
            m_currentWeaponType = eRifle;
        }

    }
    else if (m_currentWeaponType == eShotgun)
    {
        if (m_hasRifle)
        {
            m_currentWeapon = m_weapons[2];
            m_currentWeaponType = eRifle;
        }


        else
        {
            m_currentWeapon = m_weapons[0];
            m_currentWeaponType = eGun;
        }

    }
    else
    {
        m_currentWeapon = m_weapons[0];
        m_currentWeaponType = eGun;
    }

    //cout << "tengo el arma " << m_currentWeaponType << endl;
}

/////////////
void Player::throwGrenade()
{
    // TODO
}

/////////////
void Player::readEvents()
{
    CharacterController::readEvents();

    //Animacion del player
    if(getSpeedX()!=0 || getSpeedZ()!=0)
    {
        if(GEInstance->receiver.isKeyDown(KEY_LSHIFT))
            setAnimation(dwe::eAnimWalk);
        else
            setAnimation(dwe::eAnimRun);
    }
    else
    {
        setAnimation(dwe::eAnimStand);
    }

    setVelocity(dwe::vec3f(getSpeedX(), 0, getSpeedZ()));


    //Calcular rotacion player - con MOUSE
    if(GEInstance->receiver.getCursorX()>=0 && GEInstance->receiver.getCursorY()>=0){
        setRotation(
            World->from2Dto3D(GEInstance->receiver.getCursorX(),
                              GEInstance->receiver.getCursorY(),
                              getRotation()));
    }


    /*********/
     // consumir botiquin
    if(GEInstance->receiver.isKeyDown(KEY_KEY_3) && (World->getTimeElapsed() - m_timeMedkit)> 200)
    {
        this->consumeMedkit();
        m_timeMedkit = World->getTimeElapsed();
    }

    /*********/
    PlayerMate* playermate = NetInstance->getPlayerMate(1);
    if (GEInstance->receiver.isKeyDown(KEY_KEY_4)&& (World->getTimeElapsed() - m_timeGivingStuff) > 200)
    {
         this->giveMedkits(1,playermate);
         m_timeGivingStuff = World->getTimeElapsed();
    }


    if(GEInstance->receiver.isKeyDown(KEY_KEY_5) && World->getTimeElapsed() - m_timeWeaponSwap > 200)
    {
        this->swapCurrentWeapon();
        m_timeWeaponSwap = World->getTimeElapsed();
    }


}


////////////
int Player::getAmmo(int numWeapon) { return m_ammo[numWeapon]; }
void Player::setAmmo(int numWeapon, int ammount) { m_ammo[numWeapon] = ammount; }
void Player::addAmmo(int numWeapon, int ammount) { m_ammo[numWeapon] += ammount; }

////////////
int Player::getGrenades() { return m_grenades; }
void Player::setGrenades(int n) { m_grenades = n; }
void Player::setMKeys(int id){  m_mKeys[id]=true; }
bool Player::getMKey(int n){ return m_mKeys[n]; }

////////////
int Player::getLife() { return m_life; }
void Player::setLife(int n) { m_life = n; }


/////////////
void Player::onBeginContact(EntityPhysics* otherObject)
{
}

/////////////
int Player::getNumMedkits()
{
    return m_medkits;
}

/////////////
void Player::setNumMedkits(int ammount)
{
    m_medkits = ammount;

}

/////////////
void Player::addMedkits(int ammount)
{
    m_medkits += ammount;
    cout << "\nPlayer.cpp------------Obtengo " << ammount << " medkits---------\n";

}

/////////////
void Player::giveMedkits(int ammount, PlayerMate* playermate)
{
    NetInstance->sendBroadcast(ID_SEND_MEDKIT, playermate->creatingSystemGUID.ToString());
    m_medkits -= ammount;

    cout << "\nPlayer.cpp------------le doy al otro jugador "<< ammount << " botiquines--------------\n";
}

/////////////
void Player::receiveMedkits(int ammount)
{
    this->addMedkits(ammount);

}

/////////////
void Player::consumeMedkit()
{

    if (this->getNumMedkits() > 0)
    {
        m_medkits -= 1;
        this->setHealth(100);
        cout << "Vida recuperada: " << this->getLife() << endl;
    }

    cout << m_medkits << endl;
}
