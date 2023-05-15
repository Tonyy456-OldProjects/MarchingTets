#include "ButtonBehavior.h"
ButtonBehavior::ButtonBehavior(QPushButton* button, QWidget* parent)
    : m_button(button)
{
    m_button = button;
    QObject::connect(m_button, &QPushButton::clicked, parent, [this](){
        onClick();
    });
    setText("Close");
}

void ButtonBehavior::setText(const QString& str)
{
    this->m_button->setText(str);
}
