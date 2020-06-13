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

    void setCurrentLayer(const QString& name);
    ILayer* getCurrentLayer();

private:
    LayerData layer_data;
    ILayer* current_layer;
};

#endif // LEVEL_H
