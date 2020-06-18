#include "widgets/window.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // Создаём виджет окна приложения
    Window w;

    return a.exec();
}
