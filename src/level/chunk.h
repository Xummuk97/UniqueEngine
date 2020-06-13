#ifndef CHUNK_H
#define CHUNK_H

#include <SFML/Graphics.hpp>

#include "level/entity.h"

class Chunk;

/**
 * @brief Тип данных хранения Чанков
 *
 * Ключ - индекс чанка "idX:idY" (Индексы высчитываются путем pos / tile_size)
*/
using ChunkData = QMap<QString, Chunk*>;

/**
 * @brief Линии чанков по x:y
 *
 * Ключ ассоциативного массива - его индекс по x:y в строковом представлении относительно позиции всего чанка
*/
using ChunkLines = QMap<QString, EntityElement*>;

/**
 * @brief Класс Чанков
 *
 * Используется для оптимизации отрисовки обычных объектов (Не требующие обработки, просто спрайты).
 * Состоит из блока объектов соотвествующего типа, область чанка проверяется на пересечение с областью экрана игрока.
*/
class Chunk
{
public:
    Chunk(sf::Vector2f pos, sf::Vector2i size, sf::Vector2i tile_size);
    ~Chunk();

    void draw();

    sf::IntRect getBounds() const;

private:
    sf::Vector2f pos;
    sf::Vector2i size;
    sf::Vector2i tile_size;
    sf::IntRect bounds;

    ChunkLines chunk_lines;
};

#endif // CHUNK_H
