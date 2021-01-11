#include "AddLed.h"

AddLed::AddLed(ApplicationManager* pApp) :Action(pApp)
{
}

AddLed::~AddLed(void)
{
}

void AddLed::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	//Print Action Message
	pOut->PrintMsg("LED: Click to add the gate");

	//Wait for User Input
	pIn->GetPointClicked(Cx, Cy);

	//Clear Status Bar
	pOut->ClearStatusBar();

}

void AddLed::Execute()
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
		int Len = UI.BULB_Width;
		int Wdth = UI.BULB_Height;

		GraphicsInfo GInfo; //Gfx info to be used to construct the AND2 gate

		GInfo.x1 = Cx - Len / 2;
		GInfo.x2 = Cx + Len / 2;
		GInfo.y1 = Cy - Wdth / 2;
		GInfo.y2 = Cy + Wdth / 2;
		int Id = pManager->GetUniqueId();
		string Label = "LED_" + to_string(Id); //setting a default unique label for the gate
		BULB* pA = new BULB(GInfo, AND2_FANOUT, Id, Label);
		pManager->AddComponent(pA);
	}
	else
	{
		pOut->PrintMsg("Invalid Position");
	}
}

void AddLed::Undo()
{
}

void AddLed::Redo()
{
}
