#ifndef CHUNK_H
#define CHUNK_H

#include "level/entity.h"

class Chunk;

class Chunk
{
public:
    Chunk(int size);
    ~Chunk();

    void update();
    void draw();

private:
    int size;
};

#endif // CHUNK_H
