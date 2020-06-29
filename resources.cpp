#include "resources.h"

#include "widgets/canvas.h"

Resources::Resources()
{

}

Resources::~Resources()
{

}

void Resources::setTexture(const QString &name, const QString &path)
{
    sf::Texture* texture;

    if (!path.contains(":/"))
    {
        texture = new sf::Texture();
        texture->loadFromFile(path.toStdString());
    }
    else
    {
        texture = QSFMLCanvas::loadTextureFromQtRes(path);
    }

    textures[name] = texture;
}

sf::Texture* Resources::getTexture(const QString &name)
{
    return textures[name];
}
