#pragma once
#include "Actions/Action.h"
#include "ApplicationManager.h"

class ADD_COMP : public Action
{
private:

public:
	ADD_COMP(ApplicationManager* pApp);
	~ADD_COMP(void);

	//Reads parameters required for action to execute
	virtual void ReadActionParameters();
	//Execute action (code depends on action type)
	virtual void Execute();

	virtual void Undo();
	virtual void Redo();
};

