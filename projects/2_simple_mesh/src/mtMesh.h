#ifndef MT_MESH_H
#define MT_MESH_H

#include "vtkFiltersSourcesModule.h" // For export macro
#include "vtkPolyDataAlgorithm.h"

#include "vtkCell.h" // Needed for VTK_CELL_SIZE

class mtMesh : public vtkPolyDataAlgorithm
{
    public:
        vtkTypeMacro(mtMesh, vtkPolyDataAlgorithm);
        void PrintSelf(ostream& os, vtkIndent indent) override;
        static mtMesh* New();

        //LENGTH MACROS
        vtkSetClampMacro(LengthX, double, 0.0, VTK_DOUBLE_MAX);
        vtkGetMacro(LengthX, double);
        vtkSetClampMacro(LengthY, double, 0.0, VTK_DOUBLE_MAX);
        vtkGetMacro(LengthY, double);
        vtkSetClampMacro(HeightMult, double, 0.0, VTK_DOUBLE_MAX);
        vtkGetMacro(HeightMult, double);

        //DIVISONS MACROS
        vtkSetClampMacro(DivisionsX, int, 0, VTK_CELL_SIZE);
        vtkGetMacro(DivisionsX, int);
        vtkSetClampMacro(DivisionsY, int, 0, VTK_CELL_SIZE);
        vtkGetMacro(DivisionsY, int);

        //CENTER MACROS
        vtkSetVector3Macro(Center, double);
        vtkGetVectorMacro(Center, double, 3);
    protected:
        mtMesh(int res = 6);
        ~mtMesh() override = default;
        int RequestData(vtkInformation*, vtkInformationVector**, vtkInformationVector*) override;
        int RequestInformation(vtkInformation*, vtkInformationVector**, vtkInformationVector*) override;
        int DivisionsX;
        int DivisionsY;
        double LengthX;
        double LengthY;
        double HeightMult;
        double Center[3];
    private:
        mtMesh(const mtMesh&) = delete;
        void operator=(const mtMesh&) = delete;
};

#endif

