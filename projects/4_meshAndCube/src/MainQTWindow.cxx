
#include "MainQTWindow.h"
#include "LWindow.h"
#include "RWindow.h"

#include <iostream>
#include <vtkNamedColors.h>
#include <vtkNew.h>
#include <vtkGenericOpenGLRenderWindow.h>
#include <vtkCamera.h>
#include <vtkCubeSource.h>
#include <vtkDataObjectToTable.h>
#include <vtkElevationFilter.h>
#include <vtkPolyDataMapper.h>
#include <vtkQtTableView.h>
#include <vtkRenderWindow.h>
#include <vtkRenderer.h>
#include <vtkSphereSource.h>
#include <vtkVersion.h>


MainQTWindow::MainQTWindow( QWidget* parent)
    :QMainWindow(parent) 
{

}

void MainQTWindow::Initialize(Ui::TonyMainWindow *ui){
    vtkNew<vtkNamedColors> colors;

    vtkNew<LWindow> leftWindow;
    vtkNew<RWindow> rightWindow;

    ui->TonyLeftWindow->setRenderWindow(leftWindow);
    ui->TonyRightWindow->setRenderWindow(rightWindow);

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

  // Cube
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

  // VTK Renderer
  vtkNew<vtkRenderer> leftRenderer;
  leftRenderer->AddActor(sphereActor);
  leftRenderer->SetBackground(colors->GetColor3d("LightSteelBlue").GetData());

  vtkNew<vtkRenderer> rightRenderer;

  // Add Actor to renderer
  rightRenderer->AddActor(cubeActor);
  rightRenderer->GetActiveCamera()->Azimuth(60);
  rightRenderer->ResetCamera();
  rightRenderer->GetActiveCamera()->Zoom(0.8);
  rightRenderer->SetBackground(colors->GetColor3d("LightSteelBlue").GetData());

  ui->TonyLeftWindow->renderWindow()->AddRenderer(leftRenderer);
  ui->TonyRightWindow->renderWindow()->AddRenderer(rightRenderer);

}
