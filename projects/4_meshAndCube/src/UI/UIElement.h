
#include "ui_TonyDesign.h"
class UIElement 
{
    public:
        virtual ~UIElement() {}
        virtual void Setup(Ui::TonyMainWindow *ui) = 0;
};
