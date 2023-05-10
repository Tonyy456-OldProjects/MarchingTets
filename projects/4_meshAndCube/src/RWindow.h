#ifndef R_WINDOW_H
#define R_WINDOW_H

#include <vtkGenericOpenGLRenderWindow.h>
class RWindow : public vtkGenericOpenGLRenderWindow
{
    public:
        static RWindow* New();

        // Add any additional functionality or overrides here

    protected:
        RWindow();
};

#endif
