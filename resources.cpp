#include "resources.h"

#include "macros.h"
#include "widgets/canvas.h"

ResourceAbstract::ResourceAbstract()
{

}

ResourceAbstract::~ResourceAbstract()
{

}

ResourceTexture *ResourceAbstract::toTexture()
{
    return (ResourceTexture*)this;
}

ResourceTexture::ResourceTexture(const QString &path)
{
    if (!path.contains(":/"))
    {
        texture = new sf::Texture();
        texture->loadFromFile(path.toStdString());
    }
    else
    {
        texture = QSFMLCanvas::loadTextureFromQtRes(path);
    }

}

ResourceTexture::~ResourceTexture()
{

}

QString ResourceTexture::getType() const
{
    return RESOURCE_TEXTURE;
}

sf::Texture *ResourceTexture::getTexture()
{
    return texture;
}

Resources::Resources()
{

}

Resources::~Resources()
{

}

void Resources::load(const QString &name, ResourceAbstract *res)
{
    data[name] = res;
}

ResourceAbstract *Resources::get(const QString &name)
{
    return data[name];
}
