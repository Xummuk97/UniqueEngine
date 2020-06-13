#include "level.h"

Level::Level()
    : current_layer(nullptr)
{

}

Level::~Level()
{

}

void Level::loadFromFile(const QString &path)
{

}

void Level::draw()
{
    if (current_layer)
    {
        current_layer->draw();
    }
}

void Level::update()
{
    if (current_layer)
    {
        current_layer->update();
    }
}
