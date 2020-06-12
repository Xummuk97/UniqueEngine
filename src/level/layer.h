#ifndef LAYER_H
#define LAYER_H

#include "level/chunk.h"

class ILayer;

using LayerData = QList<ILayer*>;



class ILayer
{
public:
    ILayer();
    ~ILayer();

    virtual void update() = 0;
    virtual void draw() = 0;

    virtual QString getType() = 0;
};



using ChunkMap = QMap<QString, Chunk*>;

class LayerNormal : public ILayer
{
public:
    LayerNormal();
    ~LayerNormal();

    void update() override;
    void draw() override;

    QString getType() override;

private:
    ChunkMap chunk_data;
};



class LayerObjects : public ILayer
{
public:
    LayerObjects();
    ~LayerObjects();

    void update() override;
    void draw() override;

    QString getType() override;

private:

};

#endif // LAYER_H
