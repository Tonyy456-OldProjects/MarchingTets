#ifndef HW_BUTTON_H
#define HW_BUTTON_H

#include <QPushButton>
#include <QMainWindow>
#include "../ui_TonyDesign.h"

class HWButton
{
    public:
        explicit HWButton(QPushButton* button, QWidget* parent = nullptr);
        virtual ~HWButton() = default;
        void onClick();

    private:
        QPushButton* m_button;
};


#endif
