#include "Gates_1.h"

Gates_1::Gates_1(ApplicationManager* pApp) :Action(pApp)
{
}

Gates_1::~Gates_1(void)
{
}

void Gates_1::ReadActionParameters()
{
}

void Gates_1::Execute()
{
	//Get a Pointer to the Output Interfaces
	Output* pOut = pManager->GetOutput();
	pOut->ClearGateBar(); //clear the other gates bar
	UI.GateMenuNo = GATE_MODE1;
	pOut->CreateGate1ToolBar(); //draws first gates bar
}

void Gates_1::Undo()
{
}

void Gates_1::Redo()
{
}

