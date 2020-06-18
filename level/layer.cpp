#include "layer.h"

#include "macros.h"

LayerAbstract::LayerAbstract(const QString& name)
    : name(name)
{
}

LayerAbstract::~LayerAbstract()
{
}

QString LayerAbstract::getName() const
{
    return name;
}



LayerNormal::LayerNormal(const QString& name)
    : LayerAbstract(name)
{

}

LayerNormal::~LayerNormal()
{

}

void LayerNormal::update()
{
}

void LayerNormal::draw()
{
    for (auto chunk : chunk_data)
    {
        chunk->draw();
    }
}

void LayerNormal::clear()
{

}

QString LayerNormal::getType()
{
    return LAYER_NORMAL;
}

void LayerNormal::addChunk(Chunk *chunk)
{
    // Получаем идентификатор Чанка
    auto id_pos = chunk->getIdPos();

    // Добавляем Чанк в ассоциативый массив
    chunk_data[QString("%1:%2").arg(id_pos.x).arg(id_pos.y)] = chunk;
}



LayerObjects::LayerObjects(const QString& name)
    : LayerAbstract(name)
{

}

LayerObjects::~LayerObjects()
{

}

void LayerObjects::update()
{
    for (auto entity : entity_data)
    {
        if (entity->getType() == OBJECT_NORMAL)
        {
            entity->update();
        }
    }
}

void LayerObjects::draw()
{
    for (auto entity : entity_data)
    {
        if (entity->getType() == OBJECT_NORMAL)
        {
            entity->draw();
        }
    }
}

void LayerObjects::clear()
{

}

QString LayerObjects::getType()
{
    return LAYER_OBJECTS;
}
