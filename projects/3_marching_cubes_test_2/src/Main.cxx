#include <iostream>

#include "./Helper/Settings.h"
#include "./Helper/Debug.h"

Debug debug;

int main(int argc, char* argv[])
{
    // INITIALIZE SETTINGS
    Settings &instance = Settings::getInstance();
    instance.Initialize();
    instance.Print();
    debug << "Hello World!";
    return 0;
}
