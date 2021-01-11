#pragma once
#include "Actions/Action.h"
#include "ApplicationManager.h"

class Simulation_Mode : public Action
{
private:

public:
	Simulation_Mode(ApplicationManager* pApp);
	~Simulation_Mode(void);

	//Reads parameters required for action to execute
	virtual void ReadActionParameters();
	//Execute action (code depends on action type)
	virtual void Execute();

	virtual void Undo();
	virtual void Redo();
};

