#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "widgets/canvas.h"

class MainWindow : public QFrame
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    MyCanvas* canvas;
};
#endif // MAINWINDOW_H
