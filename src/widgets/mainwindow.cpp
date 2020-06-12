#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QFrame(parent)
{
    this->setWindowTitle("Qt SFML");
    this->resize(400, 400);
    this->show();

    canvas = new MyCanvas(this, QPoint(0, 0), size());
    canvas->show();
}

MainWindow::~MainWindow()
{
    delete canvas;
}

