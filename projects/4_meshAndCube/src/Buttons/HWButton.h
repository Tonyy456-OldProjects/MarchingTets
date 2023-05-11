#ifndef HWBUTTON_H
#define HWBUTTON_H

#include <QDebug>
#include <QPushButton>
#include <QMainWindow>

#include "../ui_TonyDesign.h"


class HWButton : public QPushButton
{
Q_OBJECT
    public:
        explicit HWButton(QMainWindow mainWindow, QWidget *parent = nullptr)
        virtual ~HWButton() = default;
    private slots:
        void handleHelloWorldButton();
}


#endif
