#include "copy.h"
#include "Components/Connection.h"

Copy::Copy(ApplicationManager* pApp) :Action(pApp)
{
}

Copy::~Copy(void)
{
}

void Copy::ReadActionParameters()
{
}

void Copy::Execute()
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
			pOut->PrintMsg("The component is successfully copied");
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

void Copy::Undo()
{
}

void Copy::Redo()
{
}
