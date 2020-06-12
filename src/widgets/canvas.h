#ifndef SFMLCANVAS_H
#define SFMLCANVAS_H

#include <QtCore>
#include <QtWidgets>

#include <SFML/Graphics.hpp>

class QSFMLCanvas : public QWidget, public sf::RenderWindow
{
public:
    QSFMLCanvas(QWidget* parent, const QPoint& position, const QSize& size, unsigned int frameTime = 0);
    virtual ~QSFMLCanvas();

private:
    virtual void onInit();
    virtual void onUpdate();
    virtual QPaintEngine* paintEngine() const;
    virtual void showEvent(QShowEvent*);
    virtual void paintEvent(QPaintEvent*);

    QTimer timer;
    bool   isInitialized;
};

class MyCanvas : public QSFMLCanvas
{
public:
    MyCanvas(QWidget* parent, const QPoint& position, const QSize& size);
    virtual ~MyCanvas() = default;

private:
    void onInit();
    void onUpdate();
};

#endif // SFMLCANVAS_H
