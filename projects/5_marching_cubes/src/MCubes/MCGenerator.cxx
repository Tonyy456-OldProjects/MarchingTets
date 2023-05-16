#include "MCGenerator.h"
#include <iostream>
#include <vtkMath.h>
#include "LookUpTable.h"
#include "../Debug.h"
MCGenerator::MCGenerator(int xn, int yn, int zn, double seperation)
{
    x_slices = xn;
    y_slices = yn;
    z_slices = zn;
    this->seperation = seperation;
    mesh = new Mesh();
    mesh->AddVertex(0,0,0);
    mesh->AddVertex(0,1,0);
    mesh->AddVertex(2,0,0);
    mesh->AddTriangle(0,1,2);
}

MCGenerator::~MCGenerator()
{

}

struct Point {
    double x;
    double y;
    double z;

    // Constructor
    Point(double xVal = 0.0f, double yVal = 0.0f, double zVal = 0.0f)
        : x(xVal), y(yVal), z(zVal) {
    }
    // Constructor that takes integers
    Point(int xVal, int yVal, int zVal)
        : x(static_cast<double>(xVal)), y(static_cast<double>(yVal)), z(static_cast<double>(zVal)) {
    }
};


Mesh * MCGenerator::GetMesh()
{
    Point cvs[x_slices][y_slices][z_slices];
    std::cout<<"wtf"<<std::endl;
    debug(cubeIndex[13]);
    debug(triangleIndex[cubeIndex[0]]);
    return mesh;
}
