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

ILayer *Level::getLayerFromName(const QString &name)
{
    // Проверяем, может текущий слой должен быть возвращён
    if (current_layer->getName() == name)
    {
        return current_layer;
    }

    // Ищем нужный слой, если нашли - возвращаем
    for (ILayer* layer : layer_data)
    {
        if (layer->getName() == name)
        {
            return layer;
        }
    }

    // Если ничего не было найдено
    return nullptr;
}

QString Level::getNameFromLayer(ILayer *layer)
{
    // Проверяем, может должно возвратится имя текущего слоя
    if (current_layer == layer)
    {
        return current_layer->getName();
    }

    // Ищем нужный слой, если нашли - возвращаем его имя
    for (ILayer* _layer : layer_data)
    {
        if (_layer == layer)
        {
            return _layer->getName();
        }
    }

    // Если ничего не было найдено
    return "";
}

void Level::setCurrentLayer(const QString &name)
{
    // Получаем слой по имени
    ILayer* layer = getLayerFromName(name);

    // Проверяем, не является ли слой текущим
    if (layer == current_layer)
    {
        return;
    }

    // TODO: СДЕЛАТЬ СОБЫТИЕ СМЕНЫ СЛОЯ

    // Устанавливаем текущий слой
    current_layer = layer;
}

ILayer *Level::getCurrentLayer()
{
    return current_layer;
}
