
#include "ApplicationWindow.h"
#include <vtkNamedColors.h>

ApplicationWindow::ApplicationWindow()
{
    this->renderer = vtkRenderer::New();
    this->renWin = vtkRenderWindow::New();
    this->renWin->AddRenderer(this->renderer);
    this->iren = vtkRenderWindowInteractor::New();
    this->iren->SetRenderWindow(this->renWin);

    this->renderer->SetBackground(0.2,0.4,0.3);
    this->renWin->SetSize(400,400);
    this->renWin->SetWindowName("Marching Tetrahedrons");
    vtkNew<vtkNamedColors> namedColors;
    this->renderer->SetBackground(namedColors->GetColor3d("DarkSlateGray").GetData());
}

ApplicationWindow::~ApplicationWindow()
{
    this->renWin->Delete();
    this->renderer->Delete();
    this->iren->Delete();
}

void ApplicationWindow::AddActor(vtkActor *actor)
{
    this->renderer->AddActor(actor);
}

void ApplicationWindow::Start()
{
    renWin->Render();
    renWin->SetSize(renWin->GetScreenSize());
    iren->Initialize();
    iren->Start();
}
