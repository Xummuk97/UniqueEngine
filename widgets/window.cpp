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

    Globals::resources.setTexture("new1", ":/textures/tex_1.png");
    LayerObjects* l = new LayerObjects("l1");

    EntityNormal* o = new EntityNormal("player");
    o->setTexture(Globals::resources.getTexture("new1"));
    o->setTextureRect(sf::IntRect(0, 0, 32, 32));
    l->addEntity(o);

    Globals::level->addLayer(l);
}

Window::~Window()
{
    delete canvas;
}

SFMLCanvas *Window::getCanvas()
{
    return canvas;
}

