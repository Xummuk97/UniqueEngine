#ifndef LAYER_H
#define LAYER_H

#include "level/chunk.h"

class ILayer;

using LayerData = QList<ILayer*>;



/**
 * @brief Класс Слоя
*/
class ILayer
{
public:
    ILayer(const QString& name);
    ~ILayer();

    virtual void update() = 0;
    virtual void draw() = 0;
    virtual void clear() = 0;

    virtual QString getType() = 0;

    QString getName() const;

protected:
    QString name;
};



/**
 * @brief Класс Обычного слоя (Содержит чанки, т.е. слой только рисует объекты)
*/
class LayerNormal : public ILayer
{
public:
    LayerNormal(const QString& name);
    ~LayerNormal();

    void update() override;
    void draw() override;
    void clear() override;

    QString getType() override;

protected:
    ChunkData chunk_data;
};



/**
 * @brief Класс Слой объектов
*/
class LayerObjects : public ILayer
{
public:
    LayerObjects(const QString& name);
    ~LayerObjects();

    void update() override;
    void draw() override;
    void clear() override;

    QString getType() override;

private:
    EntityData entity_data;
};

#endif // LAYER_H
