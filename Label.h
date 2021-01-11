#pragma once
#include "Actions/Action.h"
#include "ApplicationManager.h"

class Label : public Action
{
private:
	//Parameters for rectangular area to be occupied by the gate
	int Cx, Cy;	//Center point of the gate
public:
	Label(ApplicationManager* pApp);
	virtual ~Label(void);

	//Reads parameters required for action to execute
	virtual void ReadActionParameters();
	//Execute action (code depends on action type)
	virtual void Execute();

	virtual void Undo();
	virtual void Redo();


};


