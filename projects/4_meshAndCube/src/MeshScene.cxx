#include "MeshScene.h"
#include <vtkNew.h>
#include <vtkNamedColors.h>
#include <vtkCamera.h>
#include <vtkElevationFilter.h>
#include <vtkPolyDataMapper.h>
#include <vtkRenderWindow.h>
#include <vtkSphereSource.h>
#include <vtkActor.h>
#include <vtkDelaunay2D.h>
#include <vtkLookupTable.h>
#include <vtkMath.h>
#include <vtkPoints.h>
#include <vtkPolyData.h>
#include <vtkProperty.h>
#include <vtkRenderer.h>
#include <vtkVertexGlyphFilter.h>
#include <vtkMinimalStandardRandomSequence.h>
#include <vtkActor.h>
#include <vtkDelaunay2D.h>
#include <vtkLookupTable.h>
#include <vtkMath.h>
#include <vtkInformationVector.h>
#include <vtkInformation.h>
#include <vtkMinimalStandardRandomSequence.h>
#include <vtkNamedColors.h>
#include <vtkNew.h>
#include <vtkPointData.h>
#include <vtkPoints.h>
#include <vtkPolyData.h>
#include <vtkPolyDataMapper.h>
#include <vtkProperty.h>
#include <vtkRenderWindow.h>
#include <vtkRenderWindowInteractor.h>
#include <vtkRenderer.h>
#include <vtkVertexGlyphFilter.h>
#include <vtkXMLPolyDataWriter.h>


#ifdef vtkGenericDataArray_h
#define InsertNextTupleValue InsertNextTypedTuple
#endif

MeshScene::MeshScene()
{
    // Do something
}

MeshScene::~MeshScene()
{
    // Do nothing for now
}

void getMesh(vtkPolyData* output)
{
    // Create a grid of points (height/terrain map)
    vtkNew<vtkPoints> points;
    int gridWidth = 10;
    int gridHeight = 10;
    int heightMult = 1.0;
    double xx, yy, zz;
    vtkNew<vtkMinimalStandardRandomSequence> rng;
    rng->SetSeed(8775586); // For testing
    for (unsigned int x = 0; x < gridWidth; x++)
    {
        for (unsigned int y = 0; y < gridHeight; y++)
        {
            rng->Next();
            xx = x;
            rng->Next();
            yy = y;
            rng->Next();
            zz = rng->GetRangeValue(-heightMult, heightMult);
            points->InsertNextPoint(xx, yy, zz);
        }
    }

    vtkNew<vtkPolyData> inputPolyData;
    inputPolyData->SetPoints(points);

    // Triangulate the grid points
    vtkNew<vtkDelaunay2D> delaunay;
    delaunay->SetInputData(inputPolyData);
    delaunay->Update();
    output->DeepCopy(delaunay->GetOutput());

    double bounds[6];
    output->GetBounds(bounds);

    // Find min and max z
    double minz = bounds[4];
    double maxz = bounds[5];

    // Create the color map
    vtkNew<vtkLookupTable> colorLookupTable;
    colorLookupTable->SetTableRange(minz, maxz);
    colorLookupTable->Build();

    // Generate the colors for each point based on the color map
    vtkNew<vtkUnsignedCharArray> colors;
    colors->SetNumberOfComponents(3);
    colors->SetName("Colors");

    for (int i = 0; i < output->GetNumberOfPoints(); i++)
    {
        double p[3];
        output->GetPoint(i, p);

        double dcolor[3];
        colorLookupTable->GetColor(p[2], dcolor);
        unsigned char color[3];
        for (unsigned int j = 0; j < 3; j++)
        {
            color[j] = static_cast<unsigned char>(255.0 * dcolor[j]);
        }

        colors->InsertNextTupleValue(color);
    }
    output->GetPointData()->SetScalars(colors);
}

vtkSmartPointer<vtkRenderer> MeshScene::GetScene()
{
    // Sphere
    vtkSmartPointer<vtkPolyData> sphereSource;
    getMesh(sphereSource);

    vtkSmartPointer<vtkElevationFilter> sphereElev = vtkSmartPointer<vtkElevationFilter>::New();
    sphereElev->SetInputData(sphereSource);
    sphereElev->SetLowPoint(0, -1.0, 0);
    sphereElev->SetHighPoint(0, 1.0, 0);

    vtkSmartPointer<vtkPolyDataMapper> sphereMapper = vtkSmartPointer<vtkPolyDataMapper>::New();
    sphereMapper->SetInputConnection(sphereElev->GetOutputPort());

    vtkSmartPointer<vtkActor> sphereActor = vtkSmartPointer<vtkActor>::New();
    sphereActor->SetMapper(sphereMapper);

    vtkSmartPointer<vtkNamedColors> colors = vtkSmartPointer<vtkNamedColors>::New();
    vtkSmartPointer<vtkRenderer> renderer = vtkSmartPointer<vtkRenderer>::New();
    renderer->AddActor(sphereActor);
    renderer->SetBackground(colors->GetColor3d("LightSteelBlue").GetData());
    
    return renderer;
}
