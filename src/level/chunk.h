#ifndef CHUNK_H
#define CHUNK_H

#include "level/entity.h"

class Chunk;

/**
 * @brief Класс Чанков
 *
 * Используется для оптимизации отрисовки обычных объектов (Не требующие обработки, просто спрайты).
 * Состоит из блока объектов соотвествующего типа, область чанка проверяется на пересечение с областью экрана игрока.
*/
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
