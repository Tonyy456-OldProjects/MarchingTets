#ifndef MESH_SCENE_H
#define MESH_SCENE_H

#include "UI/MTWindowScene.h"
#include "data/Mesh.h"

class MeshScene : public MTWindowScene
{
    public:
        MeshScene();
        ~MeshScene();
        vtkSmartPointer<vtkRenderer> GetScene();
        void AddMesh(Mesh &mesh);

    private:
        vtkSmartPointer<vtkRenderer> renderer;
};

#endif
