
#include "ui_TonyDesign.h"
#include "MainQTWindow.h"
#include "Buttons/ButtonBehavior.h"

namespace Ui {
    class UIManager;
}

class UIManager
{
    public:
        UIManager();
        virtual ~UIManager() = default;
        void Show();
        MainQTWindow *GetWindow();
    private:
        ButtonBehavior *btn1;
        ButtonBehavior *btn2;
        MainQTWindow *mainWindow;
        Ui::TonyMainWindow *ui;
};
