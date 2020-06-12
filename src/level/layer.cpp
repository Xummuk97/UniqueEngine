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

}

void LayerNormal::draw()
{

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

}

void LayerObjects::draw()
{

}

QString LayerObjects::getType()
{
    return LAYER_OBJECTS;
}
