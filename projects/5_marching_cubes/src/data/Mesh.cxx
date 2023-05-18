#include "Mesh.h"
#include "Vector.h"
#include <iostream>
#include <unordered_map>

Mesh::Mesh()
{

}

Mesh::~Mesh()
{

}

struct VertexHash {
    std::size_t operator()(const Vertex& vertex) const {
        std::size_t h1 = std::hash<double>()(vertex.x);
        std::size_t h2 = std::hash<double>()(vertex.y);
        std::size_t h3 = std::hash<double>()(vertex.z);
        return h1 ^ (h2 << 1) ^ (h3 << 2);
    }
};

void Mesh::Clean()
{
    int numVertices = vertices.size();
    int numTriangles = triangles.size();
    std::unordered_map<Vertex, int, VertexHash> vertexMap;
    std::vector<double> uniqueVertices;
    std::vector<int> newTriangles;

    int uniqueVertexCount = 0;

    for (int i = 0; i < numVertices; i += 3) {
        Vertex vertex;
        vertex.x = vertices[i];
        vertex.y = vertices[i + 1];
        vertex.z = vertices[i + 2];

        int uniqueIndex = -1;

        // Check if the vertex already exists in the map
        auto it = vertexMap.find(vertex);
        if (it != vertexMap.end()) {
            // Vertex already exists, use the existing index
            uniqueIndex = it->second;
        } else {
            // Vertex is unique, add it to the unique vertices array and map
            uniqueIndex = uniqueVertexCount;
            vertexMap[vertex] = uniqueIndex;
            uniqueVertices.push_back(vertex.x);
            uniqueVertices.push_back(vertex.y);
            uniqueVertices.push_back(vertex.z);
            uniqueVertexCount++;
        }

        // Update the index for the current vertex
        newTriangles.push_back(uniqueIndex);
    }

    // Update the original vertices vector with the unique vertices
    vertices.assign(uniqueVertices.begin(), uniqueVertices.end());

    // Update the original triangles vector with the new indices
    triangles.assign(newTriangles.begin(), newTriangles.end());
}

void Mesh::Print()
{
    std::cout << "======MESH======" << std::endl;
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
    std::cout << "----------------" << std::endl;
}

int Mesh::AddVertex(const double vs[3])
{
    vertices.push_back(vs[0]);
    vertices.push_back(vs[1]);
    vertices.push_back(vs[2]);
    return vertices.size() / 3 - 1;
}

int Mesh::AddVertex(double v1, double v2, double v3)
{
    vertices.push_back(v1);
    vertices.push_back(v2);
    vertices.push_back(v3);
    return vertices.size() / 3 - 1;
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
