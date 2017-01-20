#ifndef PLAYER_H
#define PLAYER_H

#include <defines.h>
#include <CharacterController.h>
#include <Firearm.h>
#include "EntityPhysics.h"



class Player : public CharacterController, public EntityPhysics
{
    public:
        Player();
        virtual ~Player();

        void update();
        void render();
        void shoot();
        void throwGrenade();

        virtual void readEvents();


        // Getters & Setters
        virtual void setNode(dwe::Node* n);   // Necesario para EntityPhysics
        int getAmmo(int numWeapon);
        void setAmmo(int numWeapon, int ammount);
        int getGrenades();
        void setGrenades(int n);
        int getLife();
        void setLife(int n);
        void setMKeys(int id);
        bool getMKey(int n);
        int getMedkits();
        void setMedkits(int ammount);
        void giveMedkits(int ammount);
        void consumeMedkit();

        virtual const char* getNetObjectID() const;
        virtual void setPosition(dwe::vec3f p);

        virtual void onBeginContact(EntityPhysics* otherObject);

    protected:

    private:
        int         m_ammo[NUM_WEAPONS];
        Firearm*    m_weapons[NUM_WEAPONS];
        int         m_grenades;
        int         m_life;
        bool        m_mKeys[1];
        int         m_medkits;
        float       m_timeMedkit;
};

#endif // PLAYER_H
