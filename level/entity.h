#ifndef ENTITY_H
#define ENTITY_H

#include <QtCore>
#include <SFML/Graphics.hpp>

class EntityAbstract;

using EntityData = QList<EntityAbstract*>;

/**
 * @brief Абстрактный класс Объекта
*/
class EntityAbstract : public QObject
{
    Q_OBJECT

public:
    EntityAbstract();
    ~EntityAbstract();

    virtual void draw();
    virtual void update() = 0;

    virtual QString getType() = 0;

    void setPosition(float x, float y);
    void move(float x, float y);
    void setTexture(const sf::Texture& texture);
    void setTextureRect(const sf::IntRect& rect);

signals:
    sf::Vector2f onChangePosition(const sf::Vector2f& prevPosition, const sf::Vector2f& currentPosition);

protected:
    sf::Sprite sprite;
};



/**
 * @brief Класс Обычного объекта (Объект с обработкой событий)
*/
class EntityNormal : public EntityAbstract
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
class EntityElement : public EntityAbstract
{
public:
    EntityElement();
    ~EntityElement();

    void update() override;

    QString getType() override;

private:
};

#endif // ENTITY_H
