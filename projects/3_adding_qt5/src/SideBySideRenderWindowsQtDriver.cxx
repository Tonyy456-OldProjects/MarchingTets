#include <QApplication>
#include <QSurfaceFormat>

#include "SideBySideRenderWindowsQt.h"
#include <QVTKOpenGLNativeWidget.h>

int main(int argc, char** argv)
{
    //boiler plate
    QSurfaceFormat::setDefaultFormat(QVTKOpenGLNativeWidget::defaultFormat());
    //start an app
    QApplication app(argc, argv);
    //calls class from other file and make it render
    //this class extends QMainWindow and ui
    SideBySideRenderWindowsQt sideBySideRenderWindowsQt;
    sideBySideRenderWindowsQt.show();

    return app.exec();
}
