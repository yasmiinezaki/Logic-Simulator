#ifndef APPLICATION_MANAGER_H
#define APPLICATION_MANAGER_H

#include "Defs.h"
#include "GUI\Output.h"
#include "GUI\Input.h"
#include "Actions\Action.h"
#include "Components\Component.h"

//Main class that manages everything in the application.
class ApplicationManager
{

	enum { MaxCompCount = 200 };	//Max no of Components	

private:
	int CompCount;		//Actual number of Components
	Component* CompList[MaxCompCount];	//List of all Components (Array of pointers)
	int x, y;
	Output* OutputInterface; //pointer to the Output Clase Interface
	Input* InputInterface; //pointer to the Input Clase Interface


public:


public:	
	ApplicationManager(); //constructor

	void RemoveComp(int count);

	//take the point clicked to find if it is in the list and return the component type
	//Also returns the index of the found component
	CompType FindComp(int Cx, int Cy, int& FoundCompCount);

	//returns component clicked on
	Component* getComp(int i);

	//Reads the required action from the user and returns the corresponding action type
	ActionType GetUserAction();
	
	//Creates an action and executes it
	void ExecuteAction(ActionType);
	
	void UpdateInterface();	//Redraws all the drawing window

	//Gets a pointer to Input / Output Object
	Output* GetOutput();
	Input* GetInput();

	//Adds a new component to the list of components
	void AddComponent(Component* pComp);

	//destructor
	~ApplicationManager();
};

#endif