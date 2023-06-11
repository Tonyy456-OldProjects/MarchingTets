#ifndef MTWINDOW_SCENE_H
#define MTWINDOW_SCENE_H

#include <vtkRenderer.h>
#include <vtkSmartPointer.h>

class MTWindowScene
{
    public:
        virtual vtkSmartPointer<vtkRenderer> GetScene() = 0;
};

#endif
