#ifndef GAME_H
#define GAME_H

#include <vector>
#include "GraphicsEngine.h"

class Projectile;

class Scene
{
    public:
        Scene();
        virtual ~Scene();

        void createProjectile(dwe::vec3f origin, float angle);
        void deleteProjectile(unsigned int i);
        void updateProjectiles();

    protected:

    private:
        std::vector<Projectile*> m_projectiles;
};

#endif // GAME_H
