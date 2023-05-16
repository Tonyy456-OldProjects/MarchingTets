#include "MCGenerator.h"
#include <iostream>
#include <vtkMath.h>

MCGenerator::MCGenerator()
{
    mesh = new Mesh();
}

MCGenerator::~MCGenerator()
{

}

Mesh * MCGenerator::GetMesh()
{
    int width = 100;
    int height = 100;
    double maxHeight = 3.0;
    double minHeight = -3.0;

    // add the vertices in a grid
    for(int z = 0; z < height; z++)
    {
        for(int x = 0; x < width; x++)
        {
            double xx = static_cast<double>(x);
            double zz = static_cast<double>(z);
            double yy = vtkMath::Random(minHeight, maxHeight);
            double v[] = {xx,yy,zz};
            mesh->AddVertex(v);
        }
    }

    // add the triangles, iterate over each cube
    for(int z = 0; z < height - 1; z++)
    {
        for(int x = 0; x < width - 1; x++)
        {
            int v1 = width * z + x; //top left
            int v2 = width * (z + 1) + x; //bottom left
            int v3 = width * (z + 1) + x + 1; // bottom right
            int v4 = width * z + x + 1; //top right
            int cube[] = {v1,v2,v3,v4};
            mesh->AddCube(cube);
        }
    }

    return mesh;
}
