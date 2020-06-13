#include "layer.h"

#include "macros.h"

ILayer::ILayer(const QString& name)
    : name(name)
{
}

ILayer::~ILayer()
{
}

QString ILayer::getName() const
{
    return name;
}



LayerNormal::LayerNormal(const QString& name)
    : ILayer(name)
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
    for (Chunk* chunk : chunk_data)
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
    sf::Vector2i id_pos = chunk->getIdPos();

    // Добавляем Чанк в ассоциативый массив
    chunk_data[QString("%1:%2").arg(id_pos.x).arg(id_pos.y)] = chunk;
}



LayerObjects::LayerObjects(const QString& name)
    : ILayer(name)
{

}

LayerObjects::~LayerObjects()
{

}

void LayerObjects::update()
{
    for (IEntity* entity : entity_data)
    {
        if (entity->getType() == OBJECT_NORMAL)
        {
            entity->update();
        }
    }
}

void LayerObjects::draw()
{
    for (IEntity* entity : entity_data)
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
