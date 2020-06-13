#ifndef ENTITY_H
#define ENTITY_H

#include <QtCore>
#include <SFML/Graphics.hpp>

class IEntity;

using EntityData = QList<IEntity*>;

/**
 * @brief Интерфейс Объекта
*/
class IEntity
{
public:
    IEntity();
    ~IEntity();

    virtual void draw();
    virtual void update() = 0;

    virtual QString getType() = 0;

    sf::Sprite* getSprite();

private:
    sf::Sprite sprite;
};



/**
 * @brief Класс Обычного объекта (Объект с обработкой событий)
*/
class EntityNormal : public IEntity
{
public:
    EntityNormal();
    ~EntityNormal();

    void update() override;

    QString getType() override;

private:
};



/**
 * @brief Класс Элемента карты (обычный спрайт, используется в чанках)
*/
class EntityElement : public IEntity
{
public:
    EntityElement();
    ~EntityElement();

    void update() override;

    QString getType() override;

private:
};

#endif // ENTITY_H
