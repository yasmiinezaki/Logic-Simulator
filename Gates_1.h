#pragma once
#include "Actions/Action.h"
#include "ApplicationManager.h"

class Gates_1 : public Action
{
private:

public:
	Gates_1(ApplicationManager* pApp);
	~Gates_1(void);

	//Reads parameters required for action to execute
	virtual void ReadActionParameters();
	//Execute action (code depends on action type)
	virtual void Execute();

	virtual void Undo();
	virtual void Redo();
};


