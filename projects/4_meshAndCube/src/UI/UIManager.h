
#include "ui_TonyDesign.h"
#include "MainQTWindow.h"
#include "Buttons/HWButton.h"

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
        HWButton *btn;
        MainQTWindow *mainWindow;
        Ui::TonyMainWindow *ui;
};
