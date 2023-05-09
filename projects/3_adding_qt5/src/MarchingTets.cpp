
#include "MarchingTets.h"

#include "vtkProp.h"
#include <iostream>
MarchingTets::MarchingTets()
{
    // Similar to Examples/Tutorial/Step1/Cxx/Cone.cxx
    // We create the basic parts of a pipeline and connect them

    // setup the parent window
    this->window = new ApplicationWindow();
    this->mesh = mtMesh::New();
    mesh->SetDivisionsX(10);
    mesh->SetDivisionsY(10);
    mesh->SetLengthX(10.0);
    mesh->SetLengthY(10.0);

    this->meshMapper = vtkPolyDataMapper::New();

    this->meshMapper->SetInputConnection(this->mesh->GetOutputPort());
    this->meshActor = vtkActor::New();
    this->meshActor->SetMapper(this->meshMapper);
    this->window->AddActor(this->meshActor);
}

MarchingTets::~MarchingTets()
{
    delete this->window;
    mesh->Delete();
    meshMapper->Delete();
    meshActor->Delete();
}

void MarchingTets::Start()
{
    this->window->Start();
}

int main(int, char*[])
{
    MarchingTets *tets = new MarchingTets();
    tets->Start();
    return EXIT_SUCCESS;
}
