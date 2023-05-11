#include "HWButton.h"
#include <QDebug>

HWButton::HWButton(QMainWindow* window, QPushButton* button) : m_button(button)    
{
    //QObject::connect(m_button, &QPushButton::clicked, this, &HWButton::handleButtonClicked);
    
    QObject::connect(m_button, &QPushButton::clicked, window, [this]() {
        handleButtonClicked();
    });
}

void HWButton::handleButtonClicked()
{
    // Add your desired functionality here
    qDebug() << "Hello World Button clicked!";
    m_button->setText("Clicked!");
}

