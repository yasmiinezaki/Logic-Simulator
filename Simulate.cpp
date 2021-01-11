#include "Simulate.h"
#include <iostream>

//Constructor
Simulate::Simulate(ApplicationManager* pApp) :Action(pApp)
{
	Execute();
}

//Reads parameters required for action to execute
void Simulate::ReadActionParameters()
{
}

//Execute action 
void Simulate::Execute()
{
	Output* pOut = pManager->GetOutput();
	pOut->PrintMsg("simulate");
	pManager->SimulateCircuitOutput();
}

//Redo action
void Simulate::Redo()
{

}

//Undo action
void Simulate::Undo()
{

}

//Destructor
Simulate::~Simulate(void)
{

}