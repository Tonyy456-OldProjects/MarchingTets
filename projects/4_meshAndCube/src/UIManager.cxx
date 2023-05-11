
#include "UIManager.h"
#include "ui_TonyDesign.h"

UIManager::UIManager() : ui(new Ui::TonyMainWindow)
{
    // creates main window and sets ui up
    mainWindow = new MainQTWindow();
    ui->setupUi(mainWindow);
    mainWindow->Initialize(ui);

    // set up button to have HWButton behavior
    btn = new HWButton(ui->TonyHelloWorld, mainWindow);

}

void UIManager::Show()
{
    mainWindow->show();
}
