//#include "windows.h"
#ifndef MARCHING_TETS_H
#define MARCHING_TETS_H

#include "windows.h"
#include "vtkConeSource.h"
#include "vtkPolyDataMapper.h"
#include "vtkRenderWindow.h"
#include "vtkRenderWindowInteractor.h"
#include "vtkRenderer.h"

class MarchingTets
{
    public:
        MarchingTets(HWND parent); //HWND is handle window
        ~MarchingTets();
    private:
        vtkRenderingWindow *renWin;
        vtkRenderer *renderer;
        vtkRenderWindowInteractor *iren;
        vtkConeSource *cone;
        vtkPolyDataMapper *coneMapper;
        vtkActor *coneActor;
}

#endif
