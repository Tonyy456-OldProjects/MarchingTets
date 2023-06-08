#include "../Debug.h"
#include "UIManager.h"
#include "ui_TonyDesign.h"
#include "Buttons/HWButton.h"
#include "Buttons/CloseScreenButton.h"

void debug_test()
{
    debug("Value Updated");
}

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

    iso_slider = ui->isolevel_slider;
    frq_slider = ui->frequency_slider;
}

void UIManager::ConnectIsoSlider(const FunctionPtr &foo)
{
    MainQTWindow::connect(iso_slider, &QSlider::valueChanged, mainWindow, 
        [](float value) { 
            debug(value); 
        });
}
void UIManager::ConnectFrqSlider(const FunctionPtr &foo)
{
    MainQTWindow::connect(frq_slider, &QSlider::valueChanged, mainWindow, [](float value) { debug(value); });
}

MainQTWindow * UIManager::GetWindow() 
{
    return this->mainWindow;
}

void UIManager::Show()
{
    mainWindow->show();
}

void UIManager::CloseLeftWindow()
{
    btn1->Close();
}

void UIManager::CloseRightWindow()
{
    btn2->Close();
}
