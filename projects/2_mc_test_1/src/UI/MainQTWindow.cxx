
#include "MainQTWindow.h"
#include "QTWindow.h"
#include <vtkRenderer.h>
#include <QDebug.h>
#include <iostream>



MainQTWindow::MainQTWindow( QWidget* parent)
    :QMainWindow(parent) 
{
    windowOne = QTWindow::New();
    windowTwo = QTWindow::New();
}

/*
MainQTWindow::~MainQTWindow()
{
    windowOne->Delete();
    windowTwo->Delete();
}
*/

void MainQTWindow::Setup(Ui::TonyMainWindow *ui)
{
    ui->TonyLeftWindow->setRenderWindow(windowOne);
    ui->TonyRightWindow->setRenderWindow(windowTwo);
}

void MainQTWindow::SetRenderOne(MTWindowScene *scene)
{
    vtkSmartPointer<vtkRenderer> renderer = scene->GetScene();
    windowOne->AddRenderer(renderer);
}

void MainQTWindow::SetRenderTwo(MTWindowScene *scene)
{
    vtkSmartPointer<vtkRenderer> renderer = scene->GetScene();
    windowTwo->AddRenderer(renderer);
}
