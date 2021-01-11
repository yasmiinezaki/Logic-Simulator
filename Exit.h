#pragma once
#pragma once
#include "Actions/Action.h"
#include "ApplicationManager.h"

class Exit : public Action
{
private:

public:
	Exit(ApplicationManager* pApp);
	~Exit(void);

	//Reads parameters required for action to execute
	virtual void ReadActionParameters();
	//Execute action (code depends on action type)
	virtual void Execute();

	virtual void Undo();
	virtual void Redo();
};

