#ifndef ENTITY_H
#define ENTITY_H

#include <QtCore>
#include <SFML/Graphics.hpp>

class Entity
{
public:
    Entity();
    ~Entity();

    void draw();

private:
    virtual void onUpdate();

    sf::Sprite sprite;
};

#endif // ENTITY_H
