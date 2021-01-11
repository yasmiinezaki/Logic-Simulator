#include "AddXnorGate2.h"

AddXnorGate2::AddXnorGate2(ApplicationManager* pApp) :Action(pApp)
{
}

AddXnorGate2::~AddXnorGate2(void)
{
}

void AddXnorGate2::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	//Print Action Message
	pOut->PrintMsg("2-Input XNOR Gate: Click to add the gate");

	//Wait for User Input
	pIn->GetPointClicked(Cx, Cy);

	//Clear Status Bar
	pOut->ClearStatusBar();
}

void AddXnorGate2::Execute()
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
		int Len = UI.XNOR_Width;
		int Wdth = UI.XNOR_Height;

		GraphicsInfo GInfo; //Gfx info to be used to construct the AND2 gate

		GInfo.x1 = Cx - Len / 2;
		GInfo.x2 = Cx + Len / 2;
		GInfo.y1 = Cy - Wdth / 2;
		GInfo.y2 = Cy + Wdth / 2;
		int Id = pManager->GetUniqueId();
		string Label = "XNOR2_" + to_string(Id); //setting a default unique label for the gate
		XNOR* pA = new XNOR(GInfo, AND2_FANOUT, Id, Label);
		pManager->AddComponent(pA);
	}
	else
	{
		pOut->PrintMsg("Invalid Position");
	}
}

void AddXnorGate2::Undo()
{
}

void AddXnorGate2::Redo()
{
}

