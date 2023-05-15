#include <QApplication>
#include <QSurfaceFormat>

#include "UI/MainQTWindow.h"
#include "UI/UIManager.h"
#include "CubeScene.h"
#include "MeshScene.h"
#include "MyItem.h"

int main(int argc, char* argv[])
{
    QSurfaceFormat::setDefaultFormat(QVTKOpenGLNativeWidget::defaultFormat());
    QApplication app(argc, argv);

    UIManager manager;

    MeshScene *ms = new MeshScene();
    MyItem *item = new MyItem();
    ms->AddMesh(*(item->GetMesh()));

    manager.GetWindow()->SetRenderOne(new CubeScene());
    manager.GetWindow()->SetRenderTwo(ms);

    manager.Show(); 

    return app.exec();
}
