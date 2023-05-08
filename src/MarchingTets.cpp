
#include "MarchingTets.h"

MarchingTets::MarchingTets()
{
    // Similar to Examples/Tutorial/Step1/Cxx/Cone.cxx
    // We create the basic parts of a pipeline and connect them
    this->renderer = vtkRenderer::New();
    this->renWin = vtkRenderWindow::New();
    this->renWin->AddRenderer(this->renderer);
    // setup the parent window
    //this->renWin->SetParentId(hwnd);
    this->iren = vtkRenderWindowInteractor::New();
    this->iren->SetRenderWindow(this->renWin);
    this->cone = vtkConeSource::New();
    this->cone->SetHeight( 3.0 );
    this->cone->SetRadius( 1.0 );
    this->cone->SetResolution( 10 );
    this->coneMapper = vtkPolyDataMapper::New();
    this->coneMapper->SetInputConnection(this->cone->GetOutputPort());
    this->coneActor = vtkActor::New();
    this->coneActor->SetMapper(this->coneMapper);
    this->renderer->AddActor(this->coneActor);
    this->renderer->SetBackground(0.2,0.4,0.3);
    this->renWin->SetSize(400,400);
}

MarchingTets::~MarchingTets()
{

}
