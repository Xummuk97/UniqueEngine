#include "chunk.h"

#include "level/level.h"

Chunk::Chunk(const sf::Vector2i& id_pos)
    : id_pos(sf::Vector2i(id_pos.x * Level::getChunkSize().x, id_pos.y * Level::getChunkSize().y)),
      size(Level::getChunkSize()),
      tile_size(Level::getTileSize()),

      // Инициализируем область чанка на карте, она и проверяется на пересечение с игроком и является частью оптимизации
      bounds(sf::IntRect(id_pos.x * tile_size.x, id_pos.y * tile_size.y, size.x * tile_size.x, size.y * tile_size.y))
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
            auto entity = chunk_lines[QString("%1:%2").arg(x).arg(y)];

            // Элемент чанка может быть пуст
            if (entity)
            {
                // TODO: ЗДЕСЬ НЕОБХОДИМО СДЕЛАТЬ ПРОВЕРКУ НА ПЕРЕСЕЧЕНИЕ С ЭКРАНОМ ПОЛЬЗОВАТЕЛЯ
                entity->draw();
            }
        }
    }
}

sf::Vector2i Chunk::getIdPos() const
{
    return id_pos;
}

sf::Vector2i Chunk::getPos() const
{
    return { id_pos.x * tile_size.x, id_pos.y * tile_size.y };
}

sf::Vector2i Chunk::getSize() const
{
    return size;
}

sf::Vector2i Chunk::getTileSize() const
{
    return tile_size;
}

sf::IntRect Chunk::getBounds() const
{
    return bounds;
}

void Chunk::setObject(EntityElement *entity, int idX, int idY)
{
    // Проверяем, не вышла ли x за пределы возможных значений
    if (idX < 0 || idX >= size.x)
    {
        return;
    }

    // Проверяем, не вышла ли y за пределы возможных значений
    if (idY < 0 || idY >= size.y)
    {
        return;
    }

    // Устанавливаем соответствующую позицию
    auto pos = getPos();
    entity->setPosition(pos.x + idX * tile_size.x, pos.y + idY * tile_size.y);

    // Добавляем объект в Чанк
    chunk_lines[QString("%1:%2").arg(idX).arg(idY)] = entity;
}
