#ifndef RESOURCES_H
#define RESOURCES_H

#include <QtCore>

#include <SFML/Graphics.hpp>

class ResourceTexture;

class ResourceAbstract
{
public:
    ResourceAbstract();
    ~ResourceAbstract();

    virtual QString getType() const = 0;

    ResourceTexture* toTexture();
};

class ResourceTexture : public ResourceAbstract
{
public:
    ResourceTexture(const QString& path);
    ~ResourceTexture();

    QString getType() const override;

    sf::Texture* getTexture();

private:
    sf::Texture* texture;
};

class Resources
{
public:
    Resources();
    ~Resources();

    void load(const QString& name, ResourceAbstract* res);

    ResourceAbstract* get(const QString& name);

private:
    QMap<QString, ResourceAbstract*> data;
};

#endif // RESOURCES_H
