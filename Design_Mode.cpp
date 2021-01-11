#include "Design_Mode.h"

Design_Mode::Design_Mode(ApplicationManager* pApp) :Action(pApp)
{
}

Design_Mode::~Design_Mode(void)
{
}

void Design_Mode::ReadActionParameters()
{
}

void Design_Mode::Execute()
{
	//Get a Pointer to the Output Interfaces
	Output* pOut = pManager->GetOutput();
	pOut->PrintMsg("switch to design mode");
	pOut->ClearSimulationBar();  //clear simulation toolbar
	UI.AppMode = DESIGN;
	pOut->CreateDesignToolBar();  //draw design toolbar

}

void Design_Mode::Undo()
{
}

void Design_Mode::Redo()
{
}

