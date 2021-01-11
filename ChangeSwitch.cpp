#include "ChangeSwitch.h"
ChangeSwitch::ChangeSwitch(ApplicationManager* pMang) :Action(pMang)
{
	x = 0;
	y = 0;
	CompSelected = NULL;
	Execute();
}
ChangeSwitch::~ChangeSwitch(void)
{}
void ChangeSwitch::ReadActionParameters()
{
	
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	pIn->ReturnPointClicked(x, y);
}

void ChangeSwitch::Execute()
{
	ReadActionParameters();
	int Index;
	CompType TypeSelected;
	Component* CompSelected= pManager->FindComp(x, y, Index,TypeSelected);
	if (TypeSelected == Comp_SWITCH)
	{
		CompSelected = pManager->GetComp(Index);
		if (CompSelected->getResult() == false)
		{
			//HIGH

			CompSelected->setResult(true);
			pManager->ExecuteAction(SIMULATE);
		}
		else
		{
			//LOW

			CompSelected->setResult(false);
			pManager->ExecuteAction(SIMULATE);
		}
	}
}

void ChangeSwitch::Undo()
{}
void ChangeSwitch::Redo()
{}
