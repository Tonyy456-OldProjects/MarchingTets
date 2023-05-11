#ifndef TONY_MAIN_WINDOW_H
#define TONY_MAIN_WINDOW_H

#include "ui_TonyDesign.h"

#include <QMainWindow>
#include <QPushButton>

namespace Ui {
    class MainQTWindow;
}

class MainQTWindow : public QMainWindow
{
    Q_OBJECT
    public:
        // Constructor/Destructor
        explicit MainQTWindow(QWidget* parent = nullptr);
        virtual ~MainQTWindow() = default;
    private:
        // Designer form
        Ui::TonyMainWindow* ui;
        QPushButton *helloWorldButton;

};

#endif
