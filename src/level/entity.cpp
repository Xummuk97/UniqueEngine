#include "entity.h"

#include "macros.h"
#include "globals.h"

IEntity::IEntity()
{

}

IEntity::~IEntity()
{

}

void IEntity::draw()
{
    Globals::window->getCanvas()->draw(sprite);
}



EntityNormal::EntityNormal()
{

}

EntityNormal::~EntityNormal()
{

}

void EntityNormal::update()
{

}

QString EntityNormal::getType()
{
    return OBJECT_NORMAL;
}



EntityElement::EntityElement()
{

}

EntityElement::~EntityElement()
{

}

void EntityElement::update()
{

}

QString EntityElement::getType()
{
    return OBJECT_ELEMENT;
}
