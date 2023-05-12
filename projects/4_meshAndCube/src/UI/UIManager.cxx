
#include "UIManager.h"
#include "ui_TonyDesign.h"
#include "Buttons/HWButton.h"
#include "Buttons/CloseScreenButton.h"

UIManager::UIManager() : ui(new Ui::TonyMainWindow)
{
    // creates main window and sets ui up
    mainWindow = new MainQTWindow();
    ui->setupUi(mainWindow);
    mainWindow->Setup(ui);

    // set up button to have HWButton behavior
    //btn = new HWButton(ui->TonyHelloWorld, mainWindow);
    btn1 = new CloseScreenButton(ui->TonyLeftWindow, ui->CloseWindowOne, mainWindow);
    btn2 = new CloseScreenButton(ui->TonyRightWindow, ui->CloseWindowTwo, mainWindow);

}

MainQTWindow * UIManager::GetWindow() 
{
    return this->mainWindow;
}

void UIManager::Show()
{
    mainWindow->show();
}
