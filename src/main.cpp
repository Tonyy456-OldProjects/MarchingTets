#include <vtkJPEGReader.h>
#include <vtkImageData.h>
#include <vtkImageMapper.h> // Note: this is a 2D mapper (cf. vtkImageActor which is 3D)
#include <vtkActor2D.h>
#include <vtkRenderer.h>
#include <vtkRenderWindow.h>
#include <vtkRenderWindowInteractor.h>
#include <vtkSmartPointer.h>

int main(int argc, char **argv)
{
    vtkSmartPointer<vtkJPEGReader> reader =
        vtkSmartPointer<vtkJPEGReader>::New();
    reader->SetFileName("lenna.jpg");
    reader->Update(); // why is this necessary? shouldn't the VTK pipeline take care of this automatically?

    vtkSmartPointer<vtkImageMapper> mapper =
        vtkSmartPointer<vtkImageMapper>::New();
    mapper->SetInputData(reader->GetOutput());
    mapper->SetColorWindow(255); // width of the color range to map to
    mapper->SetColorLevel(127.5); // center of the color range to map to

    vtkSmartPointer<vtkActor2D> image =
        vtkSmartPointer<vtkActor2D>::New();
    image->SetMapper(mapper);

    vtkSmartPointer<vtkRenderer> renderer =
        vtkSmartPointer<vtkRenderer>::New();
    renderer->AddActor(image);

    vtkSmartPointer<vtkRenderWindow> window =
        vtkSmartPointer<vtkRenderWindow>::New();
    window->AddRenderer(renderer);

    vtkSmartPointer<vtkRenderWindowInteractor> interactor =
        vtkSmartPointer<vtkRenderWindowInteractor>::New();
    interactor->SetRenderWindow(window);

    // Set window to the image size. Note: why is this so cumbersome?
    int imageSize[3];
    reader->GetOutput()->GetDimensions(imageSize);
    window->SetSize(imageSize[0], imageSize[1]);

    // Here we'd normally call window->Render() to run the pipeline assembled above,
    // But instead we'll start an event loop using an interactor,
    // which prevents the program from returning as soon as it opens the image
    interactor->Start();

    return EXIT_SUCCESS;
}
