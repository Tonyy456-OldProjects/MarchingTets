#ifndef MESH_SCENE_H
#define MESH_SCENE_H

#include "UI/MTWindowScene.h"

class MeshScene : public MTWindowScene
{
    public:
        MeshScene();
        ~MeshScene();
        vtkSmartPointer<vtkRenderer> GetScene();
};

#endif
