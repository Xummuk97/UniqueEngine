#ifndef SFMLCANVAS_H
#define SFMLCANVAS_H

#include <QtCore>
#include <QtWidgets>

#include <SFML/Graphics.hpp>

/**
 * @brief Класс создания объектов SFML, представляющий из себя Qt виджет
*/
class QSFMLCanvas : public QWidget, public sf::RenderWindow
{
public:
    /**
     * @brief Конструктор
     *
     * @param parent        Родитель
     * @param position      Позиция
     * @param size          Размер
     * @param frameTime     Время смены кадра
    */
    QSFMLCanvas(QWidget* parent, const QPoint& position, const QSize& size, unsigned int frameTime = 0);

    /**
     * @brief Деструктор
    */
    virtual ~QSFMLCanvas();

    /**
     * @brief Загружает текстуру, используя файл ресурсов Qt
     *
     * @param path      Путь до файла ресурсов (писать без ":/")
     *
     * @return Текстура
    */
    static sf::Texture loadTextureFromQtRes(const QString& path);

private:
    /**
     * @brief Первоначальная инициализация
    */
    virtual void onInit();

    /**
     * @brief Обновление
    */
    virtual void onUpdate();

    /**
     * @brief Возвращает движок отрисовки Qt
     *
     * @return Движок отрисовки Qt
    */
    virtual QPaintEngine* paintEngine() const;

    /**
     * @brief Открытие и закрытие виджета
    */
    virtual void showEvent(QShowEvent*);

    /**
     * @brief Рисование
    */
    virtual void paintEvent(QPaintEvent*);

    /**
     * @brief Прекращение обновления объекта
    */
    virtual void onTimeout();

    QTimer timer; /* Таймер */
    bool   isInitialized; /* Совершена ли инициализация */
};

/**
 * @brief Класс создания объектов SFML, представляющий из себя Qt виджет
*/
class SFMLCanvas : public QSFMLCanvas
{
public:
    /**
     * @brief Конструктор
     *
     * @param parent        Родитель
     * @param position      Позиция
     * @param size          Размер
    */
    SFMLCanvas(QWidget* parent, const QPoint& position, const QSize& size);

    /**
     * @brief Деструктор
    */
    virtual ~SFMLCanvas() = default;

private:
    /**
     * @brief Первоначальная инициализация
    */
    void onInit();

    /**
     * @brief Обновление
    */
    void onUpdate();
};

#endif // SFMLCANVAS_H
