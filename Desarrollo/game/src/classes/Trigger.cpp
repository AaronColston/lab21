#include "Trigger.h"
#include "WorldInstance.h"


Trigger::Trigger():
    m_touchingMainPlayer(false)
{

}

Trigger::~Trigger()
{

}

void Trigger::triggered(Entity* e)
{

}

void Trigger::render()
{

}

void Trigger::update()
{

}

//////////////
void Trigger::setNode(dwe::Node* n)
{
    Drawable::setNode(n);

    dwe::vec3f s = n->getBoundingBox();
    createSensorBody(getPosition(), s.x, s.z, getRotation().y);
}

//////////////
void Trigger::setPosition(dwe::vec3f p)
{
    setPosEntity(p, getRotation().y);
    Drawable::setPosition(p);
}

//////////////
void Trigger::onBeginContact(EntityPhysics* otherObject)
{
    if (otherObject && otherObject->getClassID() == CLASS_PLAYER_ID)
    {
        m_touchingMainPlayer = true;
    }
}

//////////////
void Trigger::onEndContact(EntityPhysics* otherObject)
{
    if (otherObject && otherObject->getClassID() == CLASS_PLAYER_ID)
    {
        m_touchingMainPlayer = false;
    }
}
