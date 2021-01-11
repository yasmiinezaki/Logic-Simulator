#pragma once
#include "Actions/Action.h"
#include"ApplicationManager.h"

class Cut : public Action
{
private:
public:
	Cut(ApplicationManager* pApp);
	~Cut(void);

	//Reads parameters required for action to execute
	virtual void ReadActionParameters();
	//Execute action (code depends on action type)
	virtual void Execute();

	virtual void Undo();
	virtual void Redo();
};