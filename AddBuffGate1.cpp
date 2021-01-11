#include "AddBuffGate1.h"

AddBuffGate1::AddBuffGate1(ApplicationManager* pApp) :Action(pApp)
{
}

AddBuffGate1::~AddBuffGate1(void)
{
}

void AddBuffGate1::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	//Print Action Message
	pOut->PrintMsg("1-Input Buffer Gate: Click to add the gate");

	//Wait for User Input
	pIn->GetPointClicked(Cx, Cy);

	//Clear Status Bar
	pOut->ClearStatusBar();

}

void AddBuffGate1::Execute()
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
		int Len = UI.BUFFER_Width;
		int Wdth = UI.BUFFER_Height;

		GraphicsInfo GInfo; //Gfx info to be used to construct the AND2 gate

		GInfo.x1 = Cx - Len / 2;
		GInfo.x2 = Cx + Len / 2;
		GInfo.y1 = Cy - Wdth / 2;
		GInfo.y2 = Cy + Wdth / 2;
		int Id = pManager->GetUniqueId();
		string Label = "BUFF_" + to_string(Id); //setting a default unique label for the gate
		BUFFER* pA = new BUFFER(GInfo, AND2_FANOUT, Id, Label);
		pManager->AddComponent(pA);
	}
	else
	{
		pOut->PrintMsg("Invalid Position");
	}
}

void AddBuffGate1::Undo()
{
}

void AddBuffGate1::Redo()
{
}

