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
    Chunk(const sf::Vector2i& id_pos);
    ~Chunk();

    void draw();

    sf::Vector2i getIdPos() const;
    sf::Vector2i getPos() const;
    sf::Vector2i getSize() const;
    sf::Vector2i getTileSize() const;
    sf::IntRect getBounds() const;

    void setObject(EntityElement* entity, int idX = 0, int idY = 0);

private:
    sf::Vector2i id_pos;
    sf::Vector2i size;
    sf::Vector2i tile_size;
    sf::IntRect bounds;

    sf::Vector2i id;

    ChunkLines chunk_lines;
};

#endif // CHUNK_H
