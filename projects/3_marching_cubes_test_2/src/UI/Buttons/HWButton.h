#ifndef HW_BUTTON_H
#define HW_BUTTON_H

#include "ButtonBehavior.h"

class HWButton : ButtonBehavior
{
    public:
        HWButton(QPushButton* button, QWidget* parent = nullptr);
        void onClick();

};


#endif
