#ifndef MARCHING_TETS_H
#define MARCHING_TETS_H

#include "mtMesh.h"
#include "ApplicationWindow.h"
#include "vtkPolyDataMapper.h"
#include "vtkActor.h"

class MarchingTets
{
    public:
        MarchingTets(); //HWND is handle window
        ~MarchingTets();
        void Start();
    private:
        ApplicationWindow *window;
        mtMesh *mesh;
        vtkPolyDataMapper *meshMapper;
        vtkActor *meshActor;
};

#endif
