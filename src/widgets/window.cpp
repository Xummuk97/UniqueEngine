#include "window.h"
#include "ui_mainwindow.h"

#include "macros.h"
#include "globals.h"

Window::Window(QWidget *parent)
    : QFrame(parent)
{
    // Sigletor для объекта текущего класса
    if (Globals::window)
    {
        QMessageBox::critical(nullptr, "Ошибка", "Нельзя создавать более 1 экземпляра объекта класса Window.");
        exit(0);
    }

    Globals::window = this;

    // Инициализация текущего объекта
    setWindowTitle(WINDOW_TITLE);
    setWindowFlags(Qt::Dialog | Qt::MSWindowsFixedSizeDialogHint);
    setFixedSize(WINDOW_SIZE);
    show();

    // Инициализация поля объекта рисования объектов SFML
    // Внимание! Метод show надо вызывать у всех объектов, которые создаются с использованием родителя как экземпляра текущего класса!
    canvas = new SFMLCanvas(this, QPoint(0, 0), size());
    canvas->show();

    // Инициализация карты
    Globals::level = new Level();

    // ИСПОЛЬЗОВАНИЕ ЧАНКОВ
    Level::setTileSize({ 32, 32 });
    Level::setChunkSize({ 3, 3 });


    LayerNormal* layer = new LayerNormal("1");

    {
        Chunk* chunk = new Chunk({0, 0});

        {
            EntityElement* entity = new EntityElement();
            sf::Texture texture;
            texture.loadFromFile("");
            entity->getSprite()->setTexture(texture);
            entity->getSprite()->setTextureRect({0, 0, 32, 32});
            chunk->setObject(entity, 0, 0);
        }

        {
            EntityElement* entity = new EntityElement();
            sf::Texture texture;
            texture.loadFromFile("");
            entity->getSprite()->setTexture(texture);
            entity->getSprite()->setTextureRect({0, 0, 32, 32});
            chunk->setObject(entity, 2, 2);
        }

        layer->addChunk(chunk);

        sf::IntRect rect = chunk->getBounds();
        QMessageBox::about(nullptr, "", QString("%1 %2 %3 %4").arg(rect.left).arg(rect.top).arg(rect.width).arg(rect.height));

        Globals::level->addLayer(layer);
    }

    {
        Chunk* chunk = new Chunk({1, 1});

        {
            EntityElement* entity = new EntityElement();
            sf::Texture texture;
            texture.loadFromFile("");
            entity->getSprite()->setTexture(texture);
            entity->getSprite()->setTextureRect({0, 0, 32, 32});
            chunk->setObject(entity, 0, 0);
        }

        layer->addChunk(chunk);

        sf::IntRect rect = chunk->getBounds();
        QMessageBox::about(nullptr, "", QString("%1 %2 %3 %4").arg(rect.left).arg(rect.top).arg(rect.width).arg(rect.height));

        Globals::level->addLayer(layer);
    }
}

Window::~Window()
{
    delete canvas;
}

SFMLCanvas *Window::getCanvas()
{
    return canvas;
}

