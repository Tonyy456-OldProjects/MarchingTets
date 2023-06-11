#ifndef M_MY_ITEM_H
#define M_MY_ITEM_H

#include "../Data/Mesh.h"
#include "./../UI/UIManager.h"
#include "./../Scene/MeshScene.h"
class MCGenerator
{
    public:
        MCGenerator(UIManager &manager, MeshScene &scene);
        ~MCGenerator();
        void Start();
        void SetFrequency(float value);
        void SetIsolevel(float value);
        
        Mesh * GetMesh();
    private:
        int ind(int x, int y, int z)
        {
            return x + y * x_slices + z * (x_slices * y_slices); 
        };
        MeshScene *scene;
        UIManager *manager;
        int x_slices;
        int y_slices;
        int z_slices;
        float isolevel;
        float frequency;
        double seperation;
        Mesh *mesh;

};

#endif
