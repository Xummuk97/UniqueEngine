#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "widgets/canvas.h"

class Window : public QFrame
{
    Q_OBJECT

public:
    Window(QWidget *parent = nullptr);
    ~Window();

private:
    MyCanvas* canvas;
};
#endif // MAINWINDOW_H
