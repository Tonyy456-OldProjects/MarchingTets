#include <QApplication>
#include <QSurfaceFormat>
#include <iostream>

#include "UI/MainQTWindow.h"
#include "UI/UIManager.h"
#include "CubeScene.h"
#include "MeshScene.h"
#include "MyItem.h"
#include "Settings.h"

#include <sys/stat.h>
#include <unistd.h>
#include <QDebug>
#include <filesystem>

inline bool exists (const std::string& name) {
  struct stat buffer;   
  return (stat (name.c_str(), &buffer) == 0); 
}

int main(int argc, char* argv[])
{
    QSurfaceFormat::setDefaultFormat(QVTKOpenGLNativeWidget::defaultFormat());
    QApplication app(argc, argv);
   
    Settings &instance = Settings::getInstance();
#ifdef SAVE_FILE_PATH
    if(exists(SAVE_FILE_PATH))
    {
        instance.Initialize(SAVE_FILE_PATH);
    } else {
        qDebug() << "settings file does not exist";
        return 0;
    }
#else
    qDebug() << "No settings file";
    return 0;
#endif
    instance.Print();

    UIManager manager;

    MeshScene *ms = new MeshScene();
    MyItem *item = new MyItem();
    ms->AddMesh(*(item->GetMesh()));

    manager.GetWindow()->SetRenderOne(new CubeScene());
    manager.GetWindow()->SetRenderTwo(ms);

    manager.Show(); 

    return app.exec();
}
