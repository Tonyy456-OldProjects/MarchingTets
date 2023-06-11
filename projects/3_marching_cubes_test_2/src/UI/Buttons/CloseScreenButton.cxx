#include "CloseScreenButton.h"
#include <QDebug>
CloseScreenButton::CloseScreenButton(QWidget *window, QPushButton* button, QWidget* parent)
    : ButtonBehavior(button, parent)
{
    this->parent = parent;
    this->window = window;

    if(window->isVisibleTo(parent))
        this->setText("Close");
    else 
        this->setText("Open");
}

void CloseScreenButton::Close()
{
    this->setText("Open");
    window->close();
}

void CloseScreenButton::Open()
{
    this->setText("Close");
    window->show();
}

void CloseScreenButton::Toggle()
{
    if(window->isVisibleTo(parent))
    {
        window->close();
        this->setText("Open");
    } 
    else 
    {
        window->show();
        this->setText("Close");
    }
}


void CloseScreenButton::onClick()
{
    Toggle();
}
