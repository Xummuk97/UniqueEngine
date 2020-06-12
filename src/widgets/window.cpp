#include "window.h"
#include "ui_mainwindow.h"

#include "macros.h"

Window::Window(QWidget *parent)
    : QFrame(parent)
{
    this->setWindowTitle(WINDOW_TITLE);
    setWindowFlags(Qt::Dialog | Qt::MSWindowsFixedSizeDialogHint);
    this->setFixedSize(WINDOW_SIZE);
    this->show();

    canvas = new MyCanvas(this, QPoint(0, 0), size());
    canvas->show();
}

Window::~Window()
{
    delete canvas;
}

