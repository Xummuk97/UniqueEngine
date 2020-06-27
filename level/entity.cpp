#include "entity.h"

#include "macros.h"
#include "globals.h"



EntityAbstract::EntityAbstract()
    : QObject()
{

}

EntityAbstract::~EntityAbstract()
{

}

void EntityAbstract::draw()
{
    Globals::window->getCanvas()->draw(sprite);
}

void EntityAbstract::setPosition(float x, float y)
{
    sf::Vector2f prevPosition = sprite.getPosition();
    sf::Vector2f currentPosition = emit onChangePosition(prevPosition, sf::Vector2f(x, y));

    sprite.setPosition(currentPosition);
}

void EntityAbstract::move(float x, float y)
{
    sf::Vector2f prevPosition = sprite.getPosition();

    sf::Vector2f currentPosition = prevPosition;
    currentPosition.x += x;
    currentPosition.y += y;

    currentPosition = emit onChangePosition(prevPosition, currentPosition);

    sprite.move(currentPosition);
}

void EntityAbstract::setTexture(const sf::Texture &texture)
{
    sprite.setTexture(texture);
}

void EntityAbstract::setTextureRect(const sf::IntRect &rect)
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
