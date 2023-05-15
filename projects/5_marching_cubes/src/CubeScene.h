

#include "UI/MTWindowScene.h"

class CubeScene : public MTWindowScene
{
    public:
        CubeScene();
        ~CubeScene();
        vtkSmartPointer<vtkRenderer> GetScene();
};
