#include "HWButton.h"
#include <QDebug>

HWButton::HWButton(QMainWindow mainWindow, QWidget *parent = nullptr)
    :QPushButton(parent), ui(new Ui::TonyHelloWorld)
{
    connect(this, &QPushButton::clicked, mainWindow, &HWButton::handleHelloWorldButton() );
}

void HWButton::handleHelloWorldButton()
{
    // Add your desired functionality here
    qDebug() << "Hello World Button clicked!";
}

