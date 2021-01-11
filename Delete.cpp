#include "Delete.h"
#include "Actions/Action.h"
#include "ApplicationManager.h"


Delete::Delete(ApplicationManager* pMang) : Action(pMang)
{
	x = 0;
	y = 0;
	//pSelect = NULL;
	CompToDelete = NULL;
	Index = -1;
}
Delete::~Delete(void)
{}
void Delete::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	CompToDelete = pManager->GetSelectedComp(Index);

}
void Delete::Execute()
{
	/*ReadActionParameters();
	int Index;
	pSelect->Execute();
	CompType TypeToDelete = pManager->FindComp(x, y, Index);
	pManager->RemoveComp(Index);*/
}
void Delete::Undo()
{}
void Delete::Redo()
{}
