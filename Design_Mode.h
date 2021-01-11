#pragma once
#include "Actions/Action.h"
#include "ApplicationManager.h"

class Design_Mode : public Action
{
private:

public:
	Design_Mode(ApplicationManager* pApp);
	~Design_Mode(void);

	//Reads parameters required for action to execute
	virtual void ReadActionParameters();
	//Execute action (code depends on action type)
	virtual void Execute();

	virtual void Undo();
	virtual void Redo();
};


