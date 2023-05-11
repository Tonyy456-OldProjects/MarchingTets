#ifndef HW_BUTTON_H
#define HW_BUTTON_H

#include <QPushButton>
#include "../ui_TonyDesign.h"
#include <QObject>

class HWButton
{
    public:
        explicit HWButton(QMainWindow* window, QPushButton* button);
        virtual ~HWButton() = default;
        void handleButtonClicked();

    private:
        QPushButton* m_button;
};


#endif
