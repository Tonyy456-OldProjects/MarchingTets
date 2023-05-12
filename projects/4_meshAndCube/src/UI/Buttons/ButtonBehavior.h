#ifndef BUTTON_BEHAVIOR_H
#define BUTTON_BEHAVIOR_H

#include <QPushButton>
#include <QMainWindow>
#include <QString>
#include "../ui_TonyDesign.h"

class ButtonBehavior
{
    public:
        virtual ~ButtonBehavior() {}
        ButtonBehavior(QPushButton* button, QWidget* parent = nullptr);
        void setText(const QString& str);

    protected:
        virtual void onClick() = 0;
        QPushButton* m_button;
};

#endif
