#include "Perception.h"
#include "Enemy.h"
#include "NetGame.h"
#include "PlayerMate.h"
#include "WorldInstance.h"

#include "dwVectors.h"

Perception::Perception(Enemy *owner)
{
    m_owner = owner;
    m_hearing = false;
}

Perception::~Perception()
{
    //dtor
}

void Perception::Hear(dwe::vec3f pos)
{
    m_hearing = true;
    m_soundPosition = dwe::vec2f(pos.x, pos.z);
}

bool Perception::Sense()
{
    Drawable* player = World->getMainPlayer();

    if(m_hearing)
        m_owner->SetTargetPosition(m_soundPosition);

    float distance = GetDistanceClosestPlayer(player);

    if(player->getAnimation() == dwe::eAnimPlayerRun)//en caso de estar en velocidad normal, la percepcion del npc sera mayor
    {
        if(distance<=81633){ //10 metros
            m_owner->SetTargetPosition(dwe::vec2f(player->getPosition().x, player->getPosition().z));
            return true;
        }
    }
    else if(player->getAnimation() == dwe::eAnimPlayerStealth)//si estamos en sigilo, el radio sera menor
    {
        if(distance<=40000){ //7 metros
            m_owner->SetTargetPosition(dwe::vec2f(player->getPosition().x, player->getPosition().z));
            return true;
        }
    }
    else if(player->getAnimation() == dwe::eAnimPlayerStand)
    {
        if(distance<=7347){ //3 metros
            m_owner->SetTargetPosition(dwe::vec2f(player->getPosition().x, player->getPosition().z));
            return true;
        }
    }

    return m_hearing;
}

float Perception::GetDistanceClosestPlayer(Drawable*& pl)
{
    dwe::vec3f enemyPos(m_owner->getPosition());                    dwe::vec2f ePos(enemyPos.x, enemyPos.y);
    dwe::vec3f playerPos(World->getMainPlayer()->getPosition());    dwe::vec2f pPos(playerPos.x, playerPos.y);

    float distance = dwu::calculateSquaredDistance(ePos, pPos);
    float distanceAux;

    for(int i=0; i<NetInstance->getNumPlayerMates(); i++){
        Drawable *playerMate = NetInstance->getPlayerMate(i);
        if (playerMate != 0)
        {
            dwe::vec3f playerPos(playerMate->getPosition());     dwe::vec2f pPos(playerPos.x, playerPos.y);
            distanceAux = dwu::calculateSquaredDistance(ePos, pPos);
            if (distanceAux < distance)
            {
                pl = playerMate;
                distance = distanceAux;
            }
        }
    }
    return distance;
}
