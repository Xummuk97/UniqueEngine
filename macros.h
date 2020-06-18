#ifndef MACROS_H
#define MACROS_H

#include <QtCore>

const QString   PROG_VERSION = "0.0.1_alpha"; /* Версия проекта */



const QString   WINDOW_TITLE    = QString("UniqueEngine - %1").arg(PROG_VERSION);   /* Заголовок окна */
const QSize     WINDOW_SIZE     = QSize(800, 600);                                  /* Размер окна */



const QString   LAYER_NORMAL    = "normal";                                         /* Нормальный слой */
const QString   LAYER_OBJECTS   = "objects";                                        /* Слой объектов */



const QString   OBJECT_NORMAL   = "normal";                                         /* Нормальный объект */
const QString   OBJECT_ELEMENT  = "element";                                        /* Элемент карты */

#endif // MACROS_H
