#pragma once

#pragma once
#include "Actions/Action.h"
#include "ApplicationManager.h"

class Load : public Action
{
private:
	string FileName;

public:
	Load(ApplicationManager* pApp);
	~Load(void);

	//Reads parameters required for action to execute
	virtual void ReadActionParameters();
	//Execute action (code depends on action type)
	virtual void Execute();

	virtual void Undo();
	virtual void Redo();
};

