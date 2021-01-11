#include "Select.h"

Select::Select(ApplicationManager* pMang) : Action(pMang)
{
	x = 0;
	y = 0;
	Index = -1;
	CompSelected = NULL;
}
Select::~Select(void)
{}
void Select::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pIn->ReturnPointClicked(x, y);

}
void Select::Execute()
{
	ReadActionParameters();
	int Index;
	CompType TypeSelected = NoComp;
	CompSelected = pManager->FindComp(x, y, Index,TypeSelected);
	if (TypeSelected != NoComp)
	{
			if (CompSelected->getSelected() == false)
			{
				int SIndex = -1; // index of selected component in CompList
				if (!pManager->GetSelectedComp(SIndex))
				{
					CompSelected->setSelected(true);
					pManager->SetSelectedComp(CompSelected);
				}
				else
				{
					Component* OldSelected = pManager->GetSelectedComp(SIndex);
					OldSelected->setSelected(false);
					CompSelected->setSelected(true);
					pManager->SetSelectedComp(CompSelected);

				}
			}
			else
			{
				CompSelected->setSelected(false);
				pManager->SetSelectedComp(NULL);
				pManager->RemoveSelectedIndex();
			}
	}
	if (TypeSelected == Comp_SWITCH)
	{
		if (CompSelected->getResult() == false)
		{
			CompSelected->setResult(true);
		}
		else
		{
			CompSelected->setResult(false);
		}
	}
}
	

void Select::Undo()
{}
void Select::Redo()
{}

