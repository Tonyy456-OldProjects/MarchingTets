#ifndef TONY_MAIN_WINDOW_H
#define TONY_MAIN_WINDOW_H

#include "ui_TonyDesign.h"
#include "Buttons/HWButton.h"
#include "UIElement.h"

#include <QMainWindow>
#include <QPushButton>

namespace Ui {
    class MainQTWindow;
}

class MainQTWindow : public QMainWindow, public UIElement
{
    Q_OBJECT
    public:
        // Constructor/Destructor
        explicit MainQTWindow(QWidget* parent = nullptr);
        virtual ~MainQTWindow() = default;
        void Setup(Ui::TonyMainWindow *ui);
};

#endif
