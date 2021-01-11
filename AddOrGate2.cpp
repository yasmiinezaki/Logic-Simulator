#include "AddOrGate2.h"
#include "ApplicationManager.h"
#include <string>

AddOrGate2::AddOrGate2(ApplicationManager* pApp) :Action(pApp)
{
}

AddOrGate2::~AddOrGate2(void)
{
}

void AddOrGate2::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	//Print Action Message
	pOut->PrintMsg("2-Input OR Gate: Click to add the gate");

	//Wait for User Input
	pIn->GetPointClicked(Cx, Cy);

	//Clear Status Bar
	pOut->ClearStatusBar();
}

void AddOrGate2::Execute()
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
		int Len = UI.OR_Width;
		int Wdth = UI.OR_Height;

		GraphicsInfo GInfo; //Gfx info to be used to construct the AND2 gate

		GInfo.x1 = Cx - Len / 2;
		GInfo.x2 = Cx + Len / 2;
		GInfo.y1 = Cy - Wdth / 2;
		GInfo.y2 = Cy + Wdth / 2;
		int Id = pManager->GetUniqueId();
		string Label = "OR2_" + to_string(Id); //setting a default unique label for the gate
		OR* pA = new OR(GInfo, AND2_FANOUT, Id, Label);
		pManager->AddComponent(pA);
	}
	else
	{
		pOut->PrintMsg("Invalid Position");
	}
}

void AddOrGate2::Undo()
{
}

void AddOrGate2::Redo()
{
}

