#ifndef M_MY_ITEM_H
#define M_MY_ITEM_H

#include "../Data/Mesh.h"

class MCGenerator
{
    public:
        MCGenerator(int xn, int yn, int zn, double seperation);
        ~MCGenerator();
        void SetFrequency(float value);
        void SetIsolevel(float value);
        Mesh * GetMesh();
    private:
        int ind(int x, int y, int z)
        {
            return x + y * x_slices + z * (x_slices * y_slices); 
        };
        int x_slices;
        int y_slices;
        int z_slices;
        float isolevel;
        float frequency;
        double seperation;
        Mesh *mesh;

};

#endif
