#include "level.h"

sf::Vector2i            Level::tile_size;
sf::Vector2i            Level::chunk_size;

Level::Level()
{
    // Инициализация чанков
    Level::setTileSize({ 32, 32 });
    Level::setChunkSize({ 3, 3 });
}

Level::~Level()
{

}

void Level::loadFromFile(const QString &path)
{

}

void Level::draw()
{
    for (LayerAbstract* layer : layer_data)
    {
        layer->draw();
    }
}

void Level::update()
{
    for (LayerAbstract* layer : layer_data)
    {
        layer->update();
    }
}

LayerAbstract *Level::getLayerFromName(const QString &name)
{
    // Ищем нужный слой, если нашли - возвращаем
    for (LayerAbstract* layer : layer_data)
    {
        if (layer->getName() == name)
        {
            return layer;
        }
    }

    // Если ничего не было найдено
    return nullptr;
}

QString Level::getNameFromLayer(LayerAbstract *layer)
{
    // Ищем нужный слой, если нашли - возвращаем его имя
    for (LayerAbstract* _layer : layer_data)
    {
        if (_layer == layer)
        {
            return _layer->getName();
        }
    }

    // Если ничего не было найдено
    return "";
}

void Level::addLayer(LayerAbstract *layer)
{
    // Добавляем слой
    layer_data.push_back(layer);
}

void Level::removeLayer(const QString &name)
{
    // Получаем слой по имени
    LayerAbstract* layer = getLayerFromName(name);

    // Проверяем, пуст ли слой
    if (layer)
    {
        return;
    }

    // Очистка всех данных на слое
    layer->clear();

    // Удаляем слой с карты
    for (auto it = layer_data.begin(); it != layer_data.end(); it++)
    {
        LayerAbstract* _layer = *it;

        if (_layer == layer)
        {
            it = layer_data.erase(it);
            return;
        }
    }
}

void Level::setTileSize(const sf::Vector2i &tile_size)
{
    Level::tile_size = tile_size;
}

sf::Vector2i Level::getTileSize()
{
    return Level::tile_size;
}

void Level::setChunkSize(const sf::Vector2i &chunk_size)
{
    Level::chunk_size = chunk_size;
}

sf::Vector2i Level::getChunkSize()
{
    return Level::chunk_size;
}
