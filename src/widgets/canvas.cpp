#include "canvas.h"

#include "macros.h"

QSFMLCanvas::QSFMLCanvas(QWidget* parent, const QPoint& position, const QSize& size, unsigned int frameTime) :
    QWidget       (parent),
    isInitialized (false)
{
    setAttribute(Qt::WA_PaintOnScreen);
    setAttribute(Qt::WA_OpaquePaintEvent);
    setAttribute(Qt::WA_NoSystemBackground);

    setFocusPolicy(Qt::StrongFocus);

    move(position);
    resize(size);

    timer.setInterval(frameTime);
}

QSFMLCanvas::~QSFMLCanvas()
{

}

void QSFMLCanvas::onInit()
{
}

void QSFMLCanvas::onUpdate()
{
}

QPaintEngine *QSFMLCanvas::paintEngine() const
{
    return 0;
}

void QSFMLCanvas::showEvent(QShowEvent *)
{
    if (!isInitialized)
    {
        sf::Window::create(sf::WindowHandle(winId()));

        onInit();

        connect(&timer, SIGNAL(timeout()), this, SLOT(repaint()));
        timer.start();

        isInitialized = true;
    }
}

void QSFMLCanvas::paintEvent(QPaintEvent *)
{
    onUpdate();

    display();
}

MyCanvas::MyCanvas(QWidget* parent, const QPoint& position, const QSize& size)
    : QSFMLCanvas(parent, position, size)
{

}

void MyCanvas::onInit()
{
}

void MyCanvas::onUpdate()
{
    clear(sf::Color(255, 255, 255));
}
