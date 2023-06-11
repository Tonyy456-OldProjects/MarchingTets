#include "MCGenerator.h"
#include <iostream>
#include <vtkMath.h>
#include "LookUpTable.h"
#include "../headers/FastNoiseLite.h"
#include "../Debug.h"
#include "../Settings.h"
#include <vector>
#include <iostream>
#include <iomanip>
#include <thread>
using namespace std;
MCGenerator::MCGenerator(int xn, int yn, int zn, double seperation)
{
    frequency=0.09f;
    isolevel=0.0f;
    x_slices = xn;
    y_slices = yn;
    z_slices = zn;
    this->seperation = seperation;
    mesh = new Mesh();
}

void MCGenerator::SetFrequency(float value) { frequency = value; }
void MCGenerator::SetIsolevel(float value) { isolevel = value; }

MCGenerator::~MCGenerator()
{

}

void displayLoadingBar(int progress, int total, int barWidth = 50) {
    //std::this_thread::sleep_for(std::chrono::milliseconds(50));
    float fraction = static_cast<float>(progress) / total;
    int filledWidth = static_cast<int>(fraction * barWidth);

    std::cout << "\r[";
    std::cout << std::setw(filledWidth) << std::setfill('=') << std::left << std::string(filledWidth, '=');
    std::cout << std::setw(barWidth - filledWidth) << std::setfill(' ') << std::right << "]";
    std::cout << " " << static_cast<int>(fraction * 100.0) << "%";
    std::cout.flush();
}

Point VertexInterp(float isolevel, Point p1, Point p2, float v1, float v2)
{
    Point p = (p1 + p2) / 2.0f;
    return p;
}

Mesh * MCGenerator::GetMesh()
{
    FastNoiseLite noise;
    noise.SetNoiseType(FastNoiseLite::NoiseType_Perlin);
    noise.SetFrequency(this->frequency);

    int total = x_slices * y_slices * z_slices;
    total += (x_slices - 1) * (y_slices - 1) * (z_slices - 1);
    int it = 0;

    Point *cvs = new Point[x_slices * y_slices * z_slices];
    float *val = new float[x_slices * y_slices * z_slices];
    for(int x = 0; x < x_slices; x++)
    {
        for(int y = 0; y < y_slices; y++)
        {
            for(int z = 0; z < z_slices; z++)
            {
                double xw = x, yw = y, zw = z;
                cvs[ind(x,y,z)].x = xw; 
                cvs[ind(x,y,z)].y = yw; 
                cvs[ind(x,y,z)].z = zw; 
                val[ind(x,y,z)] = noise.GetNoise(xw,yw,zw);
                it++;
            }
        }
        displayLoadingBar(it, total);
    }
    for(int x = 0; x < x_slices - 1; x++)
    {
        displayLoadingBar(it, total);
        for(int y = 0; y < y_slices - 1; y++)
        {
            for(int z = 0; z < z_slices - 1; z++)
            {
                it++;
                //get all points
                Point p[8];
                p[0] = cvs[ind(x + 0,y + 0,z + 0)];
                p[1] = cvs[ind(x + 1,y + 0,z + 0)];
                p[2] = cvs[ind(x + 1,y + 0,z + 1)];
                p[3] = cvs[ind(x + 0,y + 0,z + 1)];
                p[4] = cvs[ind(x + 0,y + 1,z + 0)];
                p[5] = cvs[ind(x + 1,y + 1,z + 0)];
                p[6] = cvs[ind(x + 1,y + 1,z + 1)];
                p[7] = cvs[ind(x + 0,y + 1,z + 1)];

                //get all surface values
                float n[8];
                n[0] = val[ind(x + 0,y + 0,z + 0)];
                n[1] = val[ind(x + 1,y + 0,z + 0)];
                n[2] = val[ind(x + 1,y + 0,z + 1)];
                n[3] = val[ind(x + 0,y + 0,z + 1)];
                n[4] = val[ind(x + 0,y + 1,z + 0)];
                n[5] = val[ind(x + 1,y + 1,z + 0)];
                n[6] = val[ind(x + 1,y + 1,z + 1)];
                n[7] = val[ind(x + 0,y + 1,z + 1)];

                int cubeindex = 0;
                if(n[0] < isolevel) cubeindex |= 1;
                if(n[1] < isolevel) cubeindex |= 2;
                if(n[2] < isolevel) cubeindex |= 4;
                if(n[3] < isolevel) cubeindex |= 8;
                if(n[4] < isolevel) cubeindex |= 16;
                if(n[5] < isolevel) cubeindex |= 32;
                if(n[6] < isolevel) cubeindex |= 64;
                if(n[7] < isolevel) cubeindex |= 128;

                //debug << "cubeindex: " << cubeindex << "\n";
                if (edgeTable[cubeindex] == 0)
                    continue;

                Point vertlist[12];
                if (edgeTable[cubeindex] & 1)
                    vertlist[0] = VertexInterp(isolevel,p[0],p[1],n[0],n[1]);
                if (edgeTable[cubeindex] & 2)
                    vertlist[1] = VertexInterp(isolevel,p[1],p[2],n[1],n[2]);
                if (edgeTable[cubeindex] & 4)
                    vertlist[2] = VertexInterp(isolevel,p[2],p[3],n[2],n[3]);
                if (edgeTable[cubeindex] & 8)
                    vertlist[3] = VertexInterp(isolevel,p[3],p[0],n[3],n[0]);
                if (edgeTable[cubeindex] & 16)
                    vertlist[4] = VertexInterp(isolevel,p[4],p[5],n[4],n[5]);
                if (edgeTable[cubeindex] & 32)
                    vertlist[5] = VertexInterp(isolevel,p[5],p[6],n[5],n[6]);
                if (edgeTable[cubeindex] & 64)
                    vertlist[6] = VertexInterp(isolevel,p[6],p[7],n[6],n[7]);
                if (edgeTable[cubeindex] & 128)
                    vertlist[7] = VertexInterp(isolevel,p[7],p[4],n[7],n[4]);
                if (edgeTable[cubeindex] & 256)
                    vertlist[8] = VertexInterp(isolevel,p[0],p[4],n[0],n[4]);
                if (edgeTable[cubeindex] & 512)
                    vertlist[9] = VertexInterp(isolevel,p[1],p[5],n[1],n[5]);
                if (edgeTable[cubeindex] & 1024)
                    vertlist[10] = VertexInterp(isolevel,p[2],p[6],n[2],n[6]);
                if (edgeTable[cubeindex] & 2048)
                    vertlist[11] = VertexInterp(isolevel,p[3],p[7],n[3],n[7]);
               
                

                auto tri = triangleIndex[cubeindex];
                for(int i = 2; i < tri.size(); i+=3)
                {
                    int tri1 = tri[i-2];
                    int tri2 = tri[i-1];
                    int tri3 = tri[i-0];

                    Point v1 = vertlist[tri1];
                    Point v2 = vertlist[tri2];
                    Point v3 = vertlist[tri3];

                    int i1 = mesh->AddVertex(v1.x, v1.y, v1.z);
                    int i2 = mesh->AddVertex(v2.x, v2.y, v2.z);
                    int i3 = mesh->AddVertex(v3.x, v3.y, v3.z);

                    mesh->AddTriangle(i1,i2,i3);
                }
            }
        }
    }
    bool cleanMesh = false;
    Settings &setting = Settings::getInstance();
    setting.TryGetSetting<bool>("CleanMesh", cleanMesh);
    if(cleanMesh){
        mesh->Clean();
        displayLoadingBar(100, 100);
    }
    return mesh;
}
