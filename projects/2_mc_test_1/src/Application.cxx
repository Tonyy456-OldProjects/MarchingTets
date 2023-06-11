#include <iostream>

#include "Application.h"
#include "Scene/CubeScene.h"
#include "Scene/MeshScene.h"
#include "MCubes/MCGenerator.h"
#include "UI/MainQTWindow.h"
#include <functional>
#include "Settings.h"
#include "./Debug.h"

using namespace std;
Application *app;

void OSO(float value)
{
    app->OnSliderOne(value/100);
}

void OST(float value)
{
    app->OnSliderTwo(value/100);
}

void Application::OnSliderOne(float value)
{
    generator->SetFrequency(value);
}
void Application::OnSliderTwo(float value)
{
    generator->SetIsolevel(value);
}

Application::Application()
{
    app = this;
    // Set Up Based On Settings
    Settings &setting = Settings::getInstance();

    bool leftWindowOpen;
    bool rightWindowOpen;
    if(setting.TryGetSetting<bool>("CloseLeft", leftWindowOpen) && leftWindowOpen)
        manager.CloseLeftWindow();
    if(setting.TryGetSetting<bool>("CloseRight", rightWindowOpen) && rightWindowOpen)
        manager.CloseRightWindow();

    MeshScene *ms = new MeshScene();

    // ------- Make MCGenerator
    int nx = 10;
    int ny = 10;
    int nz = 10;
    double sep = 1.0;
    float freq = 0.05f;
    float iso = 0.0f;
    setting.TryGetSetting<int>("nx", nx);
    setting.TryGetSetting<int>("ny", ny);
    setting.TryGetSetting<int>("nz", nz);
    setting.TryGetSetting<double>("sep", sep);
    setting.TryGetSetting<float>("freq", freq);
    setting.TryGetSetting<float>("isolevel", iso);
    generator = new MCGenerator(manager, *ms);
    generator->SetFrequency(freq);
    generator->SetIsolevel(iso);

    manager.ConnectIsoSlider(&OSO);
    manager.ConnectFrqSlider(&OST);
    generator->Start();
    manager.GetWindow()->SetRenderOne(new CubeScene());
    manager.GetWindow()->SetRenderTwo(ms);

    manager.Show(); 
}

Application::~Application()
{

}
