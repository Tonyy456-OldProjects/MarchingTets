#ifndef HW_BUTTON_H
#define HW_BUTTON_H

#include <QDebug>
#include <QPushButton>
#include <QWidget>
#include <QMainWindow>

#include "../ui_TonyDesign.h"


class HWButton : public QPushButton
{
Q_OBJECT
    public:
        explicit HWButton(QPushButton* button, QWidget *parent = nullptr);
        virtual ~HWButton() = default;

    private slots:
        void handleButtonClicked();

    private:
        QPushButton* m_button;
};


#endif
