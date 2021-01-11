#include "Exit.h"

Exit::Exit(ApplicationManager* pApp) :Action(pApp)
{
}

Exit::~Exit(void)
{
}

void Exit::ReadActionParameters()
{
}

void Exit::Execute()
{
	pManager->RemoveAll();
}

void Exit::Undo()
{
}

void Exit::Redo()
{
}

