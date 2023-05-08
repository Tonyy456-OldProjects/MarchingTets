#ifndef WINDOW_H
#define WINDOW_H

#include "vtkRenderWindow.h"
#include "vtkRenderer.h"
#include "vtkRenderWindowInteractor.h"
#include "vtkMapper.h"
#include "vtkProp.h"

class ApplicationWindow
{
    public:
        ApplicationWindow();
        ~ApplicationWindow();
        void Start();
        void AddActor(vtkActor *actor);
    private:
        vtkRenderWindow *renWin;
        vtkRenderer *renderer;
        vtkRenderWindowInteractor *iren;
};

#endif