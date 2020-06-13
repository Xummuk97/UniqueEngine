#include "layer.h"

#include "macros.h"

ILayer::ILayer()
{
}

ILayer::~ILayer()
{
}



LayerNormal::LayerNormal()
{

}

LayerNormal::~LayerNormal()
{

}

void LayerNormal::update()
{
    for (Chunk* chunk : chunk_data)
    {
        chunk->update();
    }
}

void LayerNormal::draw()
{
    for (Chunk* chunk : chunk_data)
    {
        chunk->draw();
    }
}

QString LayerNormal::getType()
{
    return LAYER_NORMAL;
}



LayerObjects::LayerObjects()
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

QString LayerObjects::getType()
{
    return LAYER_OBJECTS;
}
