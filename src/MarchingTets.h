
#include "windows.h"
#include "vtkConeSource.h"
#include "vtkPolyDataMapper.h"
#include "vtkRenderWindow.h"
#include "vtkRenderWindowInteractor.h"
#include "vtkRenderer.h"

class MarchingTets {
    public:
        MarchingTets(HWND parent);
        ~MarchingTets();
    private:
        vtkRenderWindow *renWin;
        vtkRenderer *renderer;
        vtkRenderWindowInteractor *iren;
        vtkConeSource *cone;
        vtkPolyDataMapper *coneMapper;
        vtkActor *coneActor;
};
