#include "Select.h"

Select::Select(ApplicationManager* pMang) : Action(pMang)
{
	x = 0;
	y = 0;
	CompSelected = NULL;
}
Select::~Select(void)
{}
void Select::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	//Wait for User Input
	pIn->GetPointClicked(x, y);

}
void Select::Execute()
{
	ReadActionParameters();
	int Index;
	CompType TypeSelected = pManager->FindComp(x, y, Index);
	CompSelected = pManager->getComp(Index);
	if (CompSelected->getSelected() == false)
	{
		CompSelected->setSelected(true);
	}
	else
	{
		CompSelected->setSelected(false);
	}
}

void Select::Undo()
{}
void Select::Redo()
{}

/*Select::Select(ApplicationManager* pMang) : Action(pMang)
{
	px = 0;
	py = 0;
	Index = -1;
	pIn = NULL;
	CompSelected = NULL;
}

Select::~Select(void)
{}
void Select::ReadActionParameters()
{
	pIn = pManager->GetInput();
	pManager->GetLastPointClicked(px, py);
	CompType TypeSelected = pManager->FindComp(px, py, Index);
}
void Select::Execute()
{
	if (Index != -1)
	{
		CompSelected = pManager->getComp(Index);
		CompSelected->setSelected(!CompSelected->getSelected());
	}
}

void Select::Undo()
{}
void Select::Redo()
{}*/
