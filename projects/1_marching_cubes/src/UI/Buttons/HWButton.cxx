#include "HWButton.h"
#include <QDebug>
HWButton::HWButton(QPushButton* button, QWidget* parent)
    : ButtonBehavior(button, parent)
{
    //no extra behavior yet
}

void HWButton::onClick()
{
    qDebug() << "Hello World!";
    m_button->setText("Clicked!");
}

