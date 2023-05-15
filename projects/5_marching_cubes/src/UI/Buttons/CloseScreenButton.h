#ifndef CLOSESBTN_H
#define CLOSESBTN_H

#include "ButtonBehavior.h"
#include <QWidget>
#include <string>

class CloseScreenButton : public ButtonBehavior
{
    public:
        CloseScreenButton(QWidget *window, QPushButton* button, QWidget* parent = nullptr);
        void onClick();
    private:
        QWidget *window;
        bool closed = false;

};

#endif
