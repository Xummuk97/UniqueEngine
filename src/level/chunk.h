#ifndef CHUNK_H
#define CHUNK_H

#include "level/entity.h"

class Chunk;

using ChunkMap = QMap<QString, Chunk*>;
using ChunkData = QVector<Entity*>;

class Chunk
{
public:
    Chunk(int size);
    ~Chunk();

    void update();
    void draw();

private:
    int size;
    ChunkData data;
};

#endif // CHUNK_H
