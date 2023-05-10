#include <QApplication>
#include <QSurfaceFormat>

#include "MainQTWindow.h"

int main(int argc, char* argv[])
{
    QSurfaceFormat::setDefaultFormat(QVTKOpenGLNativeWidget::defaultFormat());
    QApplication app(argc, argv);
    MainQTWindow main_window;
    main_window.show();
    return app.exec();
}
