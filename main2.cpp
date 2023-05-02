// This version allows manipulating the image (pan, zoom...) using an Interactor Style.
// It requires some changes, including using a 3D actor to display a 2D image, which kinda irks me.
// Nevertheless, the code ends up being simpler than the 2D implementation.

#include <vtkJPEGReader.h>
#include <vtkImageMapper3D.h>
#include <vtkImageActor.h> // Note: this is a 3D actor (c.f. vtkImageMapper which is 2D)
#include <vtkRenderer.h>
#include <vtkRenderWindow.h>
#include <vtkRenderWindowInteractor.h>
#include <vtkInteractorStyleImage.h>
#include <vtkSmartPointer.h>

int main(int argc, char **argv)
{
    vtkSmartPointer<vtkJPEGReader> reader =
        vtkSmartPointer<vtkJPEGReader>::New();
    reader->SetFileName("lenna.jpg");

    vtkSmartPointer<vtkImageActor> image =
        vtkSmartPointer<vtkImageActor>::New();
    image->GetMapper()->SetInputConnection(reader->GetOutputPort());

    vtkSmartPointer<vtkRenderer> renderer =
        vtkSmartPointer<vtkRenderer>::New();
    renderer->AddActor(image);

    vtkSmartPointer<vtkRenderWindow> window =
        vtkSmartPointer<vtkRenderWindow>::New();
    window->AddRenderer(renderer);

    vtkSmartPointer<vtkRenderWindowInteractor> interactor =
        vtkSmartPointer<vtkRenderWindowInteractor>::New();
    interactor->SetRenderWindow(window);

    vtkSmartPointer<vtkInteractorStyleImage> style =
        vtkSmartPointer<vtkInteractorStyleImage>::New();
    interactor->SetInteractorStyle(style);

    interactor->Start();

    return EXIT_SUCCESS;
}
