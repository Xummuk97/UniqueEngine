#include "entity.h"

#include "globals.h"

Entity::Entity()
{

}

Entity::~Entity()
{

}

void Entity::draw()
{
    Globals::window->getCanvas()->draw(sprite);
}

void Entity::onUpdate()
{

}
