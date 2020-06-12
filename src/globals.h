#ifndef GLOBALS_H
#define GLOBALS_H

#include <QtCore>

#include "widgets/window.h"
#include "level/level.h"

/**
 * @brief Класс глобальных переменных с использованием паттерна Singleton
*/
class Globals
{
public:
    static Window* window; /* Главное окно */
    static Level*  level;  /* Уровень */
};

#endif // GLOBALS_H
