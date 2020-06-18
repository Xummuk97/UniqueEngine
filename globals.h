#ifndef GLOBALS_H
#define GLOBALS_H

#include <QtCore>
#include <SFML/Graphics.hpp>

#include "widgets/window.h"
#include "level/level.h"

/**
 * @brief Класс глобальных переменных
*/
class Globals
{
public:
    static Window*      window; /* Главное окно */
    static Level*       level;  /* Уровень */

    static sf::View     view;   /* Камера */
};

#endif // GLOBALS_H
