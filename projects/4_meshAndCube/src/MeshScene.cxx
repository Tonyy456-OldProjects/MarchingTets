#include "MeshScene.h"
#include <vtkNew.h>
#include <vtkCubeSource.h>
#include <vtkNamedColors.h>
#include <vtkCamera.h>
#include <vtkElevationFilter.h>
#include <vtkGenericOpenGLRenderWindow.h>
#include <vtkDataObjectToTable.h>
#include <vtkPolyDataMapper.h>
#include <vtkQtTableView.h>
#include <vtkRenderWindow.h>
#include <vtkSphereSource.h>
#include <vtkVersion.h>
MeshScene::MeshScene()
{
    //something
}

MeshScene::~MeshScene()
{
    //do nothing so far
}

vtkSmartPointer<vtkRenderer> MeshScene::GetScene()
{
    // Sphere
    vtkNew<vtkSphereSource> sphereSource;
    sphereSource->SetPhiResolution(30);
    sphereSource->SetThetaResolution(30);
    vtkNew<vtkElevationFilter> sphereElev;
    sphereElev->SetInputConnection(sphereSource->GetOutputPort());
    sphereElev->SetLowPoint(0, -1.0, 0);
    sphereElev->SetHighPoint(0, 1.0, 0);
    vtkNew<vtkPolyDataMapper> sphereMapper;
    sphereMapper->SetInputConnection(sphereElev->GetOutputPort());
    vtkNew<vtkActor> sphereActor;
    sphereActor->SetMapper(sphereMapper);
    vtkNew<vtkNamedColors> colors;
    vtkSmartPointer<vtkRenderer> renderer = vtkSmartPointer<vtkRenderer>::New();
    renderer->AddActor(sphereActor);
    renderer->SetBackground(colors->GetColor3d("LightSteelBlue").GetData());
    return renderer;
}
