#include "Mesh.h"
#include <iostream>

Mesh::Mesh()
{

}

Mesh::~Mesh()
{

}

void Mesh::Print()
{
    std::cout << "Size: " << vertices.size() << std::endl;
    std::cout << "Vertices: ";
    for (double value : vertices) {
        std::cout << value << " ";
    }
    std::cout << std::endl;
    std::cout << "Triangle: ";
    for (double value : triangles) {
        std::cout << value << " ";
    }
    std::cout << std::endl;
}

int Mesh::AddVertex(const double vs[3])
{
    vertices.push_back(vs[0]);
    vertices.push_back(vs[1]);
    vertices.push_back(vs[2]);
    return 1;
}

int Mesh::AddVertex(double v1, double v2, double v3)
{
    vertices.push_back(v1);
    vertices.push_back(v2);
    vertices.push_back(v3);
    return 1;
}

int Mesh::AddTriangle(int v1, int v2, int v3)
{
    triangles.push_back(v1);
    triangles.push_back(v2);
    triangles.push_back(v3);
    return 1; 
}

int Mesh::AddCube(const int vs[4])
{
    triangles.push_back(vs[0]);
    triangles.push_back(vs[1]);
    triangles.push_back(vs[2]);

    triangles.push_back(vs[0]);
    triangles.push_back(vs[2]);
    triangles.push_back(vs[3]);
    return 1;
}

std::vector<double> Mesh::GetVertices()
{
    return vertices;
}

std::vector<int> Mesh::GetTriangles()
{
    return triangles;
}
