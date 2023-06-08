#include "CubeScene.h"
#include <vtkNew.h>
#include <vtkSmartPointer.h>
#include <vtkCubeSource.h>
#include <vtkNamedColors.h>
#include <vtkCamera.h>
#include <vtkElevationFilter.h>
#include <vtkPolyDataMapper.h>
CubeScene::CubeScene()
{
    //something
}

CubeScene::~CubeScene()
{
    //do nothing so far
}

vtkSmartPointer<vtkRenderer> CubeScene::GetScene()
{
    vtkNew<vtkNamedColors> colors;
    vtkNew<vtkCubeSource> cubeSource;
    cubeSource->SetXLength(0.8);
    cubeSource->SetYLength(0.8);
    cubeSource->SetZLength(0.8);
    vtkNew<vtkElevationFilter> cubeElev;
    cubeElev->SetInputConnection(cubeSource->GetOutputPort());
    cubeElev->SetLowPoint(0, -1.0, 0);
    cubeElev->SetHighPoint(0, 1.0, 0);
    vtkNew<vtkPolyDataMapper> cubeMapper;
    cubeMapper->SetInputConnection(cubeElev->GetOutputPort());
    vtkNew<vtkActor> cubeActor;
    cubeActor->SetMapper(cubeMapper);

    vtkSmartPointer<vtkRenderer> renderer = vtkSmartPointer<vtkRenderer>::New();
    renderer->AddActor(cubeActor);
    renderer->GetActiveCamera()->Azimuth(60);
    renderer->ResetCamera();
    renderer->GetActiveCamera()->Zoom(0.8);
    renderer->SetBackground(colors->GetColor3d("LightSteelBlue").GetData());
    return renderer;
}
