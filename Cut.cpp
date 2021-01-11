#include "Cut.h"

Cut::Cut(ApplicationManager* pApp) :Action(pApp)
{
}

Cut::~Cut(void)
{
}

void Cut::ReadActionParameters()
{
}

void Cut::Execute()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	//Find if there is any selected component
	int Index;
	Component* SelectedComp = pManager->GetSelectedComp(Index);
	if (SelectedComp != NULL)
	{
		if (SelectedComp->GetCompType() != Comp_WIRE)
		{
			pManager->AddCopiedComp(SelectedComp->GetCompType());
			pManager->RemoveComp(Index);
			pOut->PrintMsg("The component is successfully cut");
		}
		else
		{
			pOut->PrintMsg("Operation is not suitable for a connection");
		}
	}
	else
	{
		pOut->PrintMsg("please select a component first");
	}
}

void Cut::Undo()
{
}

void Cut::Redo()
{
}
