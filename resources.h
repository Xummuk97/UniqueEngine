#ifndef RESOURCES_H
#define RESOURCES_H

#include <QtCore>

#include <SFML/Graphics.hpp>

class Resources
{
public:
    Resources();
    ~Resources();

    void setTexture(const QString& name, const QString& path);
    sf::Texture* getTexture(const QString& name);

private:
    QMap<QString, sf::Texture*> textures;
};

#endif // RESOURCES_H
