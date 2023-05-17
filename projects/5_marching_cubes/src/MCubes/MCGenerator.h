#ifndef M_MY_ITEM_H
#define M_MY_ITEM_H

#include "../Data/Mesh.h"

class MCGenerator
{
    public:
        MCGenerator(int xn, int yn, int zn, double seperation);
        ~MCGenerator();
        Mesh * GetMesh();
    private:
        int x_slices;
        int y_slices;
        int z_slices;
        float isolevel;
        double seperation;
        Mesh *mesh;

};

#endif
