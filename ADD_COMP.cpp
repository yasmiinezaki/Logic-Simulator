#include "ADD_COMP.h"

ADD_COMP::ADD_COMP(ApplicationManager* pApp) :Action(pApp)
{
}

ADD_COMP::~ADD_COMP(void)
{
}

void ADD_COMP::ReadActionParameters()
{
}

void ADD_COMP::Execute()
{
	//Get a Pointer to the Output Interfaces
	Output* pOut = pManager->GetOutput();
	UI.GateMenuNo = GATE_MODE1;
	pOut->CreateGate1ToolBar(); //draw the first gates bar
}

void ADD_COMP::Undo()
{
}

void ADD_COMP::Redo()
{
}

