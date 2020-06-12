#include "canvas.h"

#include "macros.h"

QSFMLCanvas::QSFMLCanvas(QWidget* parent, const QPoint& position, const QSize& size, unsigned int frameTime) :
    QWidget       (parent),
    isInitialized (false)
{
    // Произведём настройку для непосредственной отрисовки изображения в виджет
    setAttribute(Qt::WA_PaintOnScreen);
    setAttribute(Qt::WA_OpaquePaintEvent);
    setAttribute(Qt::WA_NoSystemBackground);

    // Установим строгую фокусировку для включения событий клавиатуры
    setFocusPolicy(Qt::StrongFocus);

    // Инициализируем виджет
    move(position);
    resize(size);

    // Настроим период сработки таймера перерисовки
    timer.setInterval(frameTime);
}

QSFMLCanvas::~QSFMLCanvas()
{
}

sf::Texture QSFMLCanvas::loadTextureFromQtRes(const QString &path)
{
    // Загрузка изображения из файла ресурсов и занесение его данных в буфер
    QPixmap pixmap(QString(":/%1").arg(path));
    QByteArray bArray;
    QBuffer buffer(&bArray);
    buffer.open(QIODevice::WriteOnly);
    pixmap.save(&buffer, "PNG");

    // Текстуру загружаем с помощью содержимого буфера
    sf::Texture texture;
    texture.loadFromMemory(buffer.data().data(), buffer.data().size());
    return texture;
}

void QSFMLCanvas::onInit()
{
}

void QSFMLCanvas::onUpdate()
{
}

QPaintEngine *QSFMLCanvas::paintEngine() const
{
    // Блокируем рисование чего либо Qt
    return nullptr;
}

void QSFMLCanvas::showEvent(QShowEvent *)
{
    // Первичная инициализация виджета SFML
    if (!isInitialized)
    {
        // Создаём SFML окно для отрисовки с указанием Id окна, в котором будет производиться отрисовка
        sf::Window::create(sf::WindowHandle(winId()));

        // Инициализация объектов отрисовки
        onInit();

        // Настройка таймера для перезапуска отрисовки виджета
        connect(&timer, &QTimer::timeout, this, &QSFMLCanvas::onTimeout);
        timer.start();

        isInitialized = true;
    }
}

void QSFMLCanvas::paintEvent(QPaintEvent *)
{
    // Обновление отрисовки объектов
    onUpdate();

    // Отображение отрисованного окна
    display();
}

void QSFMLCanvas::onTimeout()
{
    // Запуск перерисовки
    repaint();
}

SFMLCanvas::SFMLCanvas(QWidget* parent, const QPoint& position, const QSize& size)
    : QSFMLCanvas(parent, position, size)
{
}

void SFMLCanvas::onInit()
{
}

void SFMLCanvas::onUpdate()
{
    // Очищаем экран с заданием цвета заднего фона
    clear(sf::Color(255, 255, 255));
}
