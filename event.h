#ifndef EVENT_H
#define EVENT_H

#include <QtCore>

template<class T>
class Events
{
public:
    using F = std::function<void (T* obj)>;

    Events(T* obj)
        : obj(obj)
    {
    }

    ~Events()
    {
    }

    void setEvent(const QString& name, F func)
    {
        data[name] = func;
    }

    void callEvent(const QString& name)
    {
        if (data.find(name) != data.end())
        {
            data[name](obj);
        }
    }

private:
    QMap<QString, F> data;
    T* obj;
};

#endif // EVENT_H
