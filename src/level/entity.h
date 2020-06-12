#ifndef ENTITY_H
#define ENTITY_H

#include <QtCore>
#include <SFML/Graphics.hpp>

class IEntity
{
public:
    IEntity();
    ~IEntity();

    virtual void draw() = 0;

    virtual QString getType() = 0;

private:
    virtual void onUpdate() = 0;

    sf::Sprite sprite;
};



class EntityNormal : public IEntity
{
public:
    EntityNormal();
    ~EntityNormal();

    void draw() override;

    QString getType() override;

private:
    void onUpdate() override;
};



class EntityElement : public IEntity
{
public:
    EntityElement();
    ~EntityElement();

    void draw() override;

    QString getType() override;

private:
    void onUpdate() override;
};

#endif // ENTITY_H
