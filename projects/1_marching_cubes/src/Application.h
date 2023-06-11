#ifndef MY_APP_H
#define MY_APP_H

#include "UI/UIManager.h"

class Application
{
    public:
        Application();
        ~Application();
    private:
        UIManager manager;
};

#endif
