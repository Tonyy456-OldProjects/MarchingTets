#ifndef UI_MANAGER_H
#define UI_MANAGER_H
#include "ui_TonyDesign.h"
#include "MainQTWindow.h"
#include "Buttons/CloseScreenButton.h"

namespace Ui {
    class UIManager;
}

class UIManager
{
    public:
        UIManager();
        virtual ~UIManager() = default;

        void Show();
        void CloseLeftWindow();
        void CloseRightWindow();

        MainQTWindow* GetWindow();
    private:
        CloseScreenButton *btn1;
        CloseScreenButton *btn2;
        MainQTWindow *mainWindow;
        Ui::TonyMainWindow *ui;
};

#endif
