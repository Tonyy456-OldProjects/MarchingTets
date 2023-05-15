#ifndef M_MESH_H
#define M_MESH_H

#include <vector>

class Mesh
{
    public:
        Mesh();
        ~Mesh();
        int AddVertex(const double vs[3]);
        int AddTriangle(int v1, int v2, int v3);
        int AddCube(const int vs[4]);
        std::vector<double> GetVertices();
        std::vector<int> GetTriangles();
        void Print();
    private:
        std::vector<double> vertices;
        std::vector<int> triangles;
};

#endif
