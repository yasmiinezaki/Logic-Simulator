#include "Gates_2.h"

Gates_2::Gates_2(ApplicationManager* pApp) :Action(pApp)
{
}

Gates_2::~Gates_2(void)
{
}

void Gates_2::ReadActionParameters()
{
}

void Gates_2::Execute()
{
	//Get a Pointer to the Output Interfaces
	Output* pOut = pManager->GetOutput();
	pOut->ClearGateBar(); //clear the other gates bar
	UI.GateMenuNo = GATE_MODE2;
	pOut->CreateGate2ToolBar(); //draws second gates bar
}

void Gates_2::Undo()
{
}

void Gates_2::Redo()
{
}
