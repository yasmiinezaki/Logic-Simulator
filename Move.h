#pragma once
#include"Actions/Action.h"
#include "ApplicationManager.h"

class Move : public Action
{
private:
	int FirstX, FirstY;
	int x, y;

public:
	Move(ApplicationManager* pApp);
	~Move(void);

	//Reads parameters required for action to execute
	virtual void ReadActionParameters();
	//Execute action (code depends on action type)
	virtual void Execute();

	virtual void Undo();
	virtual void Redo();
};

