#ifndef UI_MANAGER_H
#define UI_MANAGER_H
#include "ui_TonyDesign.h"
#include "MainQTWindow.h"
#include "Buttons/CloseScreenButton.h"
#include <string>
#include <vector>
typedef void (*FunctionPtr)(float value);

namespace Ui {
    class UIManager;
}

class UIManager
{
    public:
        UIManager();
        virtual ~UIManager() = default;

        void Show();
        void ConnectIsoSlider(const FunctionPtr &foo);
        void ConnectFrqSlider(const FunctionPtr &foo);
        void CloseLeftWindow();
        void CloseRightWindow();

        MainQTWindow* GetWindow();
    private:
        QSlider *iso_slider;
        QSlider *frq_slider;
        CloseScreenButton *btn1;
        CloseScreenButton *btn2;
        MainQTWindow *mainWindow;
        Ui::TonyMainWindow *ui;
};

#endif
