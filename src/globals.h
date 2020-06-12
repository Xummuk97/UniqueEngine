#ifndef GLOBALS_H
#define GLOBALS_H

#include <QtCore>

#include "widgets/window.h"

/**
 * @brief Класс глобальных переменных с использованием паттерна Singleton
*/
class Globals
{
public:
    static Window* window; /* Главное окно */
};

Window*             Globals::window;

#endif // GLOBALS_H
