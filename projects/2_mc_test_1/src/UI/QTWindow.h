#ifndef a_QTWINDOW_H
#define a_QTWINDOW_H

namespace Ui{
    class QTWindow;
}

#include <vtkGenericOpenGLRenderWindow.h>
class QTWindow : public vtkGenericOpenGLRenderWindow
{
    public:
        static QTWindow* New();

    protected:
        QTWindow();
};

#endif
