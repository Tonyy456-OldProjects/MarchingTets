#include <QApplication>
#include <QSurfaceFormat>

#include "UI/MainQTWindow.h"
#include "UI/UIManager.h"
#include "CubeScene.h"
#include "MeshScene.h"

int main(int argc, char* argv[])
{
    QSurfaceFormat::setDefaultFormat(QVTKOpenGLNativeWidget::defaultFormat());
    QApplication app(argc, argv);

    UIManager manager;

    manager.GetWindow()->SetRenderOne(new CubeScene());
    manager.GetWindow()->SetRenderTwo(new MeshScene());

    manager.Show(); 

    return app.exec();
}
