#pragma once
#include"Actions/Action.h"
#include"ApplicationManager.h"
using namespace std;

class Simulate : public Action  //inherited from class Action.
{


public:
	//Constructor
	Simulate(ApplicationManager* pApp) ;

	//Reads parameters required for action to execute
	virtual void ReadActionParameters() ;

	//Execute action (code depends on action type)
	virtual void Execute() ;

	//To undo this action (code depends on action type)
	virtual void Undo() ;

	//To redo this action (code depends on action type)
	virtual void Redo() ;

	//Destructor
	~Simulate(void);

};

