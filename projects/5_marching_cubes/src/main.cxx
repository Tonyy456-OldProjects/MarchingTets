#include <QApplication>
#include <QSurfaceFormat>
#include <iostream>
#include <sys/stat.h>
#include <unistd.h>
#include <QDebug>
#include <filesystem>

#include "Settings.h"
#include "Application.h"
#include "Debug.h"

Debug debug;

inline bool exists (const std::string& name) {
  struct stat buffer;   
  return (stat (name.c_str(), &buffer) == 0); 
}

int main(int argc, char* argv[])
{
    QSurfaceFormat::setDefaultFormat(QVTKOpenGLNativeWidget::defaultFormat());
    QApplication app(argc, argv);
  
    // INITIALIZE SETTINGS
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

    Application app2;

    return app.exec();
}
