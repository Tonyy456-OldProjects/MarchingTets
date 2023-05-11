#include <QApplication>
#include <QSurfaceFormat>

#include "MainQTWindow.h"
#include "UIManager.h"

int main(int argc, char* argv[])
{
    QSurfaceFormat::setDefaultFormat(QVTKOpenGLNativeWidget::defaultFormat());
    QApplication app(argc, argv);

    UIManager manager;
    manager.Show(); 
    return app.exec();
}
