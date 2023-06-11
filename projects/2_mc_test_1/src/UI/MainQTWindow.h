#ifndef TONY_MAIN_WINDOW_H
#define TONY_MAIN_WINDOW_H

#include "ui_TonyDesign.h"
#include "UIElement.h"
#include "MTWindowScene.h"
#include "QTWindow.h"
#include <QMainWindow>

namespace Ui {
    class MainQTWindow;
}

class MainQTWindow : public QMainWindow, public UIElement
{
    Q_OBJECT
    public:
        // Constructor/Destructor
        explicit MainQTWindow(QWidget* parent = nullptr);
        virtual ~MainQTWindow() = default;
        void Setup(Ui::TonyMainWindow *ui);
        void SetRenderOne(MTWindowScene *scene);
        void SetRenderTwo(MTWindowScene *scene);
    private:
        QTWindow *windowOne;
        QTWindow *windowTwo;
};

#endif
