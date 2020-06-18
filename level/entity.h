#ifndef ENTITY_H
#define ENTITY_H

#include <QtCore>
#include <SFML/Graphics.hpp>

class EntityAbstrart;

using EntityData = QList<EntityAbstrart*>;

/**
 * @brief Абстрактный класс Объекта
*/
class EntityAbstrart
{
public:
    EntityAbstrart();
    ~EntityAbstrart();

    virtual void draw();
    virtual void update() = 0;

    virtual QString getType() = 0;

    virtual void setPosition(float x, float y);
    virtual void move(float x, float y);
    virtual void setTexture(const sf::Texture& texture);
    virtual void setTextureRect(const sf::IntRect& rect);

protected:
    sf::Sprite sprite;
};



/**
 * @brief Класс Обычного объекта (Объект с обработкой событий)
*/
class EntityNormal : public EntityAbstrart
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
class EntityElement : public EntityAbstrart
{
public:
    EntityElement();
    ~EntityElement();

    void update() override;

    QString getType() override;

private:
};

#endif // ENTITY_H
