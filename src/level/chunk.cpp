#include "chunk.h"

Chunk::Chunk(sf::Vector2f pos, sf::Vector2i size, sf::Vector2i tile_size)
    : pos(pos),
      size(size),
      tile_size(tile_size),

      // Инициализируем область чанка на карте, она и проверяется на пересечение с игроком и является частью оптимизации
      bounds(sf::IntRect(pos.x, pos.y, size.x * tile_size.x, size.y * tile_size.y))
{
}

Chunk::~Chunk()
{
}

void Chunk::draw()
{
    // Проходимся по всем элементам чанка по x:y
    for (int y = 0; y < size.y; y++)
    {
        for (int x = 0; x < size.x; x++)
        {
            EntityElement* entity = chunk_lines[QString("%1:%2").arg(x).arg(y)];

            // Элемент чанка может быть пуст
            if (entity)
            {
                // TODO: ЗДЕСЬ НЕОБХОДИМО СДЕЛАТЬ ПРОВЕРКУ НА ПЕРЕСЕЧЕНИЕ С ЭКРАНОМ ПОЛЬЗОВАТЕЛЯ
                entity->draw();
            }
        }
    }
}

sf::IntRect Chunk::getBounds() const
{
    return bounds;
}
