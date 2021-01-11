#include "AddAndGate3.h"

AddAndGate3::AddAndGate3(ApplicationManager* pApp) :Action(pApp)
{
}

AddAndGate3::~AddAndGate3(void)
{
}

void AddAndGate3::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	//Print Action Message
	pOut->PrintMsg("3-Input AND Gate: Click to add the gate");

	//Wait for User Input
	pIn->GetPointClicked(Cx, Cy);

	//Clear Status Bar
	pOut->ClearStatusBar();
}

void AddAndGate3::Execute()
{
	//Get a Pointer to the Output Interface
	Output* pOut = pManager->GetOutput();
	//Get Center point of the Gate
	ReadActionParameters();

	//Check if the coordinates are valid 
	bool Valid = CheckIsValid(Cx, Cy);
	if (Valid)
	{
		//Calculate the rectangle Corners
		int Len = UI.AND3_Width;
		int Wdth = UI.AND3_Height;

		GraphicsInfo GInfo; //Gfx info to be used to construct the AND2 gate

		GInfo.x1 = Cx - Len / 2;
		GInfo.x2 = Cx + Len / 2;
		GInfo.y1 = Cy - Wdth / 2;
		GInfo.y2 = Cy + Wdth / 2;
		int Id = pManager->GetUniqueId();
		string Label = "AND3_" + to_string(Id); //setting a default unique label for the gate
		AND3* pA = new AND3(GInfo, AND2_FANOUT, Id, Label);
		pManager->AddComponent(pA);
	}
	else
	{
		pOut->PrintMsg("Invalid Position");
	}
}

void AddAndGate3::Undo()
{
}

void AddAndGate3::Redo()
{
}

