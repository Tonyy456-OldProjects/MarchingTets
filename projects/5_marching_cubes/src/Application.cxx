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
    MCGenerator *item = new MCGenerator(5,5,5,1.0);
    ms->AddMesh(*(item->GetMesh()));
    manager.GetWindow()->SetRenderOne(new CubeScene());
    manager.GetWindow()->SetRenderTwo(ms);

    manager.Show(); 
}

Application::~Application()
{

}
