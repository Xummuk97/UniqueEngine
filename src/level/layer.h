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
    ILayer();
    ~ILayer();

    virtual void update() = 0;
    virtual void draw() = 0;

    virtual QString getType() = 0;
};



using ChunkMap = QMap<QString, Chunk*>;

/**
 * @brief Класс Обычного слоя (Содержит чанки, т.е. слой только рисует объекты)
*/
class LayerNormal : public ILayer
{
public:
    LayerNormal();
    ~LayerNormal();

    void update() override;
    void draw() override;

    QString getType() override;

protected:
    ChunkMap chunk_data;
};



/**
 * @brief Класс Слой объектов
*/
class LayerObjects : public ILayer
{
public:
    LayerObjects();
    ~LayerObjects();

    void update() override;
    void draw() override;

    QString getType() override;

private:
    EntityData entity_data;
};

#endif // LAYER_H
