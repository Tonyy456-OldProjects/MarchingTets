#include "CloseScreenButton.h"
#include <QDebug>
CloseScreenButton::CloseScreenButton(QWidget *window, QPushButton* button, QWidget* parent)
    : ButtonBehavior(button, parent)
{
    this->window = window;
}


void CloseScreenButton::onClick()
{
    if(closed)
    {
        window->show();
        this->setText("Close");
        qDebug() << "Screen Open";
    } 
    else 
    {
        window->close();
        this->setText("Open");
        qDebug() << "Screen Closed";
    }
    closed = !closed;
}
