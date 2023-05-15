#ifndef M_MY_ITEM_H
#define M_MY_ITEM_H

#include "data/Mesh.h"

class MyItem
{
    public:
        MyItem();
        ~MyItem();
        Mesh * GetMesh();
    private:
        Mesh *mesh;

};

#endif
