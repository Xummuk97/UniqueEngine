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

private:
    LayerData layer_data;
    ILayer* current_layer;
};

#endif // LEVEL_H
