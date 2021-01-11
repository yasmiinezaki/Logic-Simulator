#include "Simulation_Mode.h"

Simulation_Mode::Simulation_Mode(ApplicationManager* pApp) :Action(pApp)
{
}

Simulation_Mode::~Simulation_Mode(void)
{
}

void Simulation_Mode::ReadActionParameters()
{
}

void Simulation_Mode::Execute()
{
	//Get a pointer to the output interfaces
	Output* pOut = pManager->GetOutput();
	int InputPins;
	int OutputPinsConn;
	if (pManager->CheckCircuitValidation(InputPins, OutputPinsConn))
	{
		//There is at least 1 output pin without connections. 
		pOut->PrintMsg("The circuit is invalid.");
	}
	else
	{
		//Check if input pins equal outpins connections. 
		if (InputPins == OutputPinsConn)
		{
			//Get a Pointer to the Output Interfaces
			pOut->PrintMsg("switch to simulation mode");
			pOut->ClearSimulationBar();  //clear Design toolbar
			UI.AppMode = SIMULATION;
			pOut->CreateSimulationToolBar();  //draw simulation toolbar
			pManager->ExecuteAction(SIMULATE);

		}
		else
		{
			pOut->PrintMsg("The circuit is invalid.");
		}
	}
}

void Simulation_Mode::Undo()
{
}

void Simulation_Mode::Redo()
{
}

