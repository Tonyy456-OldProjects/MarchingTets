#include "mtMesh.h"

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

#include "debug/log.h"

#include <cmath>
#include <iomanip>
#include <iostream>

#ifdef vtkGenericDataArray_h
#define InsertNextTupleValue InsertNextTypedTuple
#endif

vtkStandardNewMacro(mtMesh);

//------------------------------------------------------------------------------
// Construct with default resolution 6, height 1.0, radius 0.5, and capping
// on.
mtMesh::mtMesh(int res)
{
  res = (res < 0 ? 0 : res);
  this->DivisionsX = res;
  this->DivisionsY = res;

  this->HeightMult = 1;

  this->LengthX = 10;
  this->LengthY = 10;

  this->Center[0] = 0.0;
  this->Center[1] = 0.0;
  this->Center[2] = 0.0;

  this->SetNumberOfInputPorts(0);
}

//------------------------------------------------------------------------------
int mtMesh::RequestData(vtkInformation* vtkNotUsed(request),
    vtkInformationVector** vtkNotUsed(inputVector), vtkInformationVector* outputVector)
{
    // get the info objects
    vtkInformation* outInfo = outputVector->GetInformationObject(0);
    vtkPolyData* output = vtkPolyData::SafeDownCast(outInfo->Get(vtkDataObject::DATA_OBJECT()));

    // Create a grid of points (height/terrian map)
    vtkNew<vtkPoints> points;
    int gridWidth = this->DivisionsX;
    int gridHeight = this->DivisionsY;
    int heightMult = this->HeightMult;
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
    std::cout << "grid width: " << gridWidth << std::endl;

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

    std::cout.precision(3);
    std::cout << "minz: " << std::right << std::setw(6) << minz << std::endl;
    std::cout << "maxz: " << std::right << std::setw(6) << maxz << std::endl;
    std::cout.precision(0);

    // Create the color map
    vtkNew<vtkLookupTable> colorLookupTable;
    colorLookupTable->SetTableRange(minz, maxz);
    colorLookupTable->Build();

    // Generate the colors for each point based on the color map
    vtkNew<vtkUnsignedCharArray> colors;
    colors->SetNumberOfComponents(3);
    colors->SetName("Colors");

    std::cout << "There are " << output->GetNumberOfPoints() << " points."
                << std::endl;
    std::cout.precision(6);
    std::cout << std::fixed;
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
    std::cout.precision(0);
    output->GetPointData()->SetScalars(colors);

    return 1;
}

//------------------------------------------------------------------------------
int mtMesh::RequestInformation(vtkInformation* vtkNotUsed(request),
    vtkInformationVector** vtkNotUsed(inputVector), vtkInformationVector* outputVector)
{
    vtkInformation* outInfo = outputVector->GetInformationObject(0);
    outInfo->Set(CAN_HANDLE_PIECE_REQUEST(), 1);
    return 1;
}

//------------------------------------------------------------------------------
void mtMesh::PrintSelf(ostream& os, vtkIndent indent)
{
    this->Superclass::PrintSelf(os, indent);

    /*
    os << indent << "Resolution: " << this->Resolution << "\n";
    os << indent << "Height: " << this->Height << "\n";
    os << indent << "Radius: " << this->Radius << "\n";
    os << indent << "Capping: " << (this->Capping ? "On\n" : "Off\n");
    os << indent << "Center: (" << this->Center[0] << ", " << this->Center[1] << ", "
        << this->Center[2] << ")\n";
    os << indent << "Direction: (" << this->Direction[0] << ", " << this->Direction[1] << ", "
        << this->Direction[2] << ")\n";
    os << indent << "Output Points Precision: " << this->OutputPointsPrecision << "\n";
    */
}
