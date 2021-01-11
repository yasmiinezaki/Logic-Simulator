#pragma once
#include "Actions/Action.h"
#include "ApplicationManager.h"

class Copy : public Action
{
private:
public:
	Copy(ApplicationManager* pApp);
	~Copy(void);

	//Reads parameters required for action to execute
	virtual void ReadActionParameters();
	//Execute action (code depends on action type)
	virtual void Execute();

	virtual void Undo();
	virtual void Redo();
};