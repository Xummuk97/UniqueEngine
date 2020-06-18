#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "widgets/canvas.h"

/**
 * @brief Класс окна
 *
 * @note Экземпляр данного объекта инициализирует глобальные поля класса Globals.
*/
class Window : public QFrame
{
    Q_OBJECT

public:
    /**
     * @brief Конструктор
     *
     * @param parent        Родитель
    */
    Window(QWidget *parent = nullptr);

    /**
     * @brief Деструктор
    */
    ~Window();

    /**
     * @brief Возвращает объект рисования объектов SFML
     *
     * @return Объект рисования объектов SFML
    */
    SFMLCanvas* getCanvas();

private:
    SFMLCanvas* canvas; /* Рисование объектов SFML */
};
#endif // MAINWINDOW_H
