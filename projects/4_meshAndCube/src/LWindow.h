#ifndef RWINDOW_H
#define RWINDOW_H

#include <vtkGenericOpenGLRenderWindow.h>
class LWindow : public vtkGenericOpenGLRenderWindow
{
    public:
        static LWindow* New();

        // Add any additional functionality or overrides here

    protected:
        LWindow();
};

#endif
