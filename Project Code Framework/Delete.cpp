#include "Delete.h"
#include "Actions/Action.h"
#include "ApplicationManager.h"


Delete::Delete(ApplicationManager* pMang) : Action(pMang)
{
	Index = -1;
	x = 0;
	y = 0;
}
Delete::~Delete(void)
{}
void Delete::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	//Wait for User Input
	do{
		pOut->PrintMsg("Please select component to be deleted. ");
		pIn->GetPointClicked(x, y);
	CompType TypeToDelete = pManager->FindComp(x, y, Index);
	} while (Index == -1);
}
void Delete::Execute()
{
	ReadActionParameters();	
	pManager->RemoveComp(Index);
}
void Delete::Undo()
{}
void Delete::Redo()
{}