#include "Label.h"
Label::Label(ApplicationManager* pMang) : Action(pMang)
{
	x = 0;
	y = 0;
	CompLabeled = NULL;
	Index = -1;
}
Label::~Label(void)
{}
void Label::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	do {
		pOut->PrintMsg("Please select component to be labeled. ");
		pIn->GetPointClicked(x, y);
		CompType TypeToDelete = pManager->FindComp(x, y, Index);
	} while (Index == -1);
}
void Label::Execute()
{
	ReadActionParameters();
	CompLabeled = pManager->getComp(Index);
}
void Label::Undo()
{}
void Label::Redo()
{}