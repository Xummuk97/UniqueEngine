#ifndef LEVEL_H
#define LEVEL_H

#include <QtCore>

#include "level/layer.h"

class Level
{
public:
    Level();
    ~Level();

    void loadFromFile(const QString& path);

    void draw();
    void update();

    ILayer* getLayerFromName(const QString& name);
    QString getNameFromLayer(ILayer* layer);

    void addLayer(ILayer* layer);
    void removeLayer(const QString& name);

    static void setTileSize(const sf::Vector2i& tile_size);
    static sf::Vector2i getTileSize();

    static void setChunkSize(const sf::Vector2i& chunk_size);
    static sf::Vector2i getChunkSize();

private:
    LayerData layer_data;

    static sf::Vector2i tile_size;
    static sf::Vector2i chunk_size;
};

#endif // LEVEL_H
