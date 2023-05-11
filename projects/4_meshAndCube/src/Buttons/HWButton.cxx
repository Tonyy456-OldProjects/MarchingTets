#include "HWButton.h"
#include <QDebug>
HWButton::HWButton(QPushButton* button, QWidget* parent) : m_button(button)
{
    QObject::connect(m_button, &QPushButton::clicked, parent, [this]() {
        onClick();
    });
}

void HWButton::onClick()
{
    qDebug() << "Hello World!";
    m_button->setText("Clicked!");
}

