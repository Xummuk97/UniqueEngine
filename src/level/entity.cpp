#include "entity.h"

#include "macros.h"
#include "globals.h"

IEntity::IEntity()
{

}

IEntity::~IEntity()
{

}



EntityNormal::EntityNormal()
{

}

EntityNormal::~EntityNormal()
{

}

void EntityNormal::draw()
{

}

QString EntityNormal::getType()
{
    return OBJECT_NORMAL;
}

void EntityNormal::onUpdate()
{

}



EntityElement::EntityElement()
{

}

EntityElement::~EntityElement()
{

}

void EntityElement::draw()
{

}

QString EntityElement::getType()
{
    return OBJECT_ELEMENT;
}

void EntityElement::onUpdate()
{

}
