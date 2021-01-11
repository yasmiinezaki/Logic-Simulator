#pragma once
#include "Actions/Action.h"
#include  "ApplicationManager.h"

class Paste : public Action
{
private:
	//point clicked by the user
	int Cx, Cy;
	//The component to be copied
	CompType CopiedComp;

public:
	Paste(ApplicationManager* pApp);
	~Paste(void);

	//Reads parameters required for action to execute
	virtual void ReadActionParameters();
	//Execute action (code depends on action type)
	virtual void Execute();

	virtual void Undo();
	virtual void Redo();
};

