#include "Probing.h"

Probing::Probing(ApplicationManager* pMang) :Action(pMang)
{
	x = 0;
	y = 0;
	CompSelected = NULL;
}

Probing::~Probing(void)
{}

void Probing::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	pOut->PrintMsg("click on the wire to know its status.");
	pIn->GetPointClicked(x, y);
}

void Probing::Execute()
{
	ReadActionParameters();
	Output* pOut = pManager->GetOutput();
	int Index;
	CompType TypeSelected = NoComp;
	CompSelected = pManager->FindComp(x, y, Index, TypeSelected);
	if (TypeSelected == Comp_WIRE)
	{
		//CompSelected = pManager->GetComp(Index);
		Connection* ConnSelected = (Connection*)CompSelected;
		if (ConnSelected->getProbResult())
		{
			pOut->PrintMsg("The status of this wire is HIGH (1).");
		}
		else
		{
			pOut->PrintMsg("The status of this wire is LOW (0).");
		}
	}
}

void Probing::Redo()
{

}
void Probing::Undo()
{

}