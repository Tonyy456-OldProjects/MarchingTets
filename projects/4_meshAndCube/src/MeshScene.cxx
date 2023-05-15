#include "MeshScene.h"

#include <vtkNamedColors.h>
#include <vtkCamera.h>
#include <iostream>
#include <vtkSmartPointer.h>
#include <vtkPoints.h>
#include <vtkCellArray.h>
#include <vtkTriangle.h>
#include <vtkPolyData.h>
#include <vtkPolyDataMapper.h>
#include <vtkActor.h>
#include <vtkRenderer.h>
#include <vtkRenderWindow.h>
#include <vtkRenderWindowInteractor.h>


MeshScene::MeshScene()
{
    renderer = vtkSmartPointer<vtkRenderer>::New();
    // Do something
}

MeshScene::~MeshScene()
{
    // Do nothing for now
}

void MeshScene::AddMesh(Mesh &mesh)
{

    std::vector<double> vs = mesh.GetVertices();
    std::vector<int> tr = mesh.GetTriangles();

    // Create a VTK points object and populate it with the vertices
    vtkSmartPointer<vtkPoints> points = vtkSmartPointer<vtkPoints>::New();
    for (int i = 0; i < vs.size() / 3; i++)
    {
        double* vertex = &vs[i * 3];
        points->InsertNextPoint(vertex);
    }

    vtkSmartPointer<vtkCellArray> triangles = vtkSmartPointer<vtkCellArray>::New();
    for (int i = 0; i < tr.size() / 3; i++)
    {
        vtkSmartPointer<vtkTriangle> triangle = vtkSmartPointer<vtkTriangle>::New();
        vtkIdType i1 = tr[3*i + 0];
        vtkIdType i2 = tr[3*i + 1];
        vtkIdType i3 = tr[3*i + 2];
        triangle->GetPointIds()->SetId(0,i1);
        triangle->GetPointIds()->SetId(1,i2);
        triangle->GetPointIds()->SetId(2,i3);
        triangles->InsertNextCell(triangle);
    }

    // Create a VTK polydata object and set its points and triangles
    vtkSmartPointer<vtkPolyData> polyData = vtkSmartPointer<vtkPolyData>::New();
    polyData->SetPoints(points);
    polyData->SetPolys(triangles);

    // Create a VTK mapper and actor
    vtkSmartPointer<vtkPolyDataMapper> mapper = vtkSmartPointer<vtkPolyDataMapper>::New();
    mapper->SetInputData(polyData);

    vtkSmartPointer<vtkActor> actor = vtkSmartPointer<vtkActor>::New();
    actor->SetMapper(mapper);

    renderer->AddActor(actor);
}

vtkSmartPointer<vtkRenderer> MeshScene::GetScene()
{    
    vtkNew<vtkNamedColors> colors;
    renderer->GetActiveCamera()->Azimuth(60);
    renderer->ResetCamera();
    renderer->GetActiveCamera()->Zoom(0.8);
    renderer->SetBackground(colors->GetColor3d("LightSteelBlue").GetData());
    return renderer;
}
