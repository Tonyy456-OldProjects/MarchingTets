#include "CloseScreenButton.h"
#include <QDebug>
CloseScreenButton::CloseScreenButton(QWidget *window, QPushButton* button, QWidget* parent)
    : ButtonBehavior(button, parent)
{
    this->window = window;
    if(window->isVisibleTo(parent))
    {
        this->setText("Close");
    } 
    else 
    {
        this->setText("Open");
    }
}


void CloseScreenButton::onClick()
{
    if(window->isVisible())
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
