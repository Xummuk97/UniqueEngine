#ifndef LAYER_H
#define LAYER_H

#include "level/chunk.h"

class Layer;

using LayerData = QList<Layer*>;

class Layer
{
public:
    Layer();
    ~Layer();

    void update();
    void draw();

private:
    ChunkData chunk_data;
};

#endif // LAYER_H
