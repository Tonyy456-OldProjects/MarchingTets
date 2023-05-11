#include "HWButton.h"
#include <QDebug>
#include <QAbstractButton>

HWButton::HWButton(QPushButton* button, QWidget *parent) :
    QPushButton(parent), m_button(button)    
{
    connect(m_button, &QPushButton::clicked, this, &HWButton::handleButtonClicked);
}

void HWButton::handleButtonClicked()
{
    // Add your desired functionality here
    qDebug() << "Hello World Button clicked!";
    m_button->setText("Clicked!");
}

