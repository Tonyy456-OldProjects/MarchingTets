#ifndef MY_APP_H
#define MY_APP_H

#include "UI/UIManager.h"
#include "./MCubes/MCGenerator.h"

class Application
{
    public:
        Application();
        ~Application();
        void OnSliderOne(float value);
        void OnSliderTwo(float value);

    private:
        UIManager manager;
        MCGenerator *generator;
};

#endif
