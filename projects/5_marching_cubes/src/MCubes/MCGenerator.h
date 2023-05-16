#ifndef M_MY_ITEM_H
#define M_MY_ITEM_H

#include "../Data/Mesh.h"

class MCGenerator
{
    public:
        MCGenerator();
        ~MCGenerator();
        Mesh * GetMesh();
    private:
        Mesh *mesh;

};

#endif
