#include "entity.h"

#include "macros.h"
#include "globals.h"

EntityAbstrart::EntityAbstrart()
{

}

EntityAbstrart::~EntityAbstrart()
{

}

void EntityAbstrart::draw()
{
    Globals::window->getCanvas()->draw(sprite);
}

void EntityAbstrart::setPosition(float x, float y)
{
    sprite.setPosition(x, y);
}

void EntityAbstrart::move(float x, float y)
{
    sprite.move(x, y);
}

void EntityAbstrart::setTexture(const sf::Texture &texture)
{
    sprite.setTexture(texture);
}

void EntityAbstrart::setTextureRect(const sf::IntRect &rect)
{
    sprite.setTextureRect(rect);
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
