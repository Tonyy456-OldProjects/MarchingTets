#include <iostream>

#include "Application.h"
#include "Scene/CubeScene.h"
#include "Scene/MeshScene.h"
#include "MCubes/MCGenerator.h"
#include "UI/MainQTWindow.h"

#include "Settings.h"

using namespace std;

Application::Application()
{
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
    MCGenerator *item = new MCGenerator(nx,ny,nz,sep);
    item->SetFrequency(freq);
    item->SetIsolevel(iso);


    ms->AddMesh(*(item->GetMesh()));
    manager.GetWindow()->SetRenderOne(new CubeScene());
    manager.GetWindow()->SetRenderTwo(ms);

    manager.Show(); 
}

Application::~Application()
{

}
