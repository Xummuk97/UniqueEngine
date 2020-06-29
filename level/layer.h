#ifndef LAYER_H
#define LAYER_H

#include "level/chunk.h"

class LayerAbstract;

using LayerData = QList<LayerAbstract*>;

/**
 * @brief Абстрактный класс Слоя
*/
class LayerAbstract
{
public:
    LayerAbstract(const QString& name);
    ~LayerAbstract();

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
class LayerNormal : public LayerAbstract
{
public:
    LayerNormal(const QString& name);
    ~LayerNormal();

    void update() override;
    void draw() override;
    void clear() override;

    QString getType() override;

    void addChunk(Chunk* chunk);

protected:
    ChunkData chunk_data;
};


using EntityData = QList<EntityNormal*>;

/**
 * @brief Класс Слой объектов
*/
class LayerObjects : public LayerAbstract
{
public:
    LayerObjects(const QString& name);
    ~LayerObjects();

    void update() override;
    void draw() override;
    void clear() override;

    QString getType() override;

    void addEntity(EntityNormal* entity);

private:
    EntityData entity_data;
};

#endif // LAYER_H
