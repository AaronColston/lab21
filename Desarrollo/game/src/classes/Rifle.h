#ifndef RIFLE_H
#define RIFLE_H

#include <Firearm.h>

class Player;

class Rifle : public Firearm
{
    public:
        Rifle();
        virtual ~Rifle();

        void shoot();
        void reload();
        void onTake(Player* mainPlayer);

        //void update();
        void render(){};

    protected:

    private:
};

#endif // RIFLE_H
