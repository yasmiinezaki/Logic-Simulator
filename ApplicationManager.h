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

	Output* OutputInterface; //pointer to the Output Clase Interface
	Input* InputInterface; //pointer to the Input Clase Interface

	//////////////////////////////////////////////////////////////////// 
	CompType CopiedComp; // Component type of copied component
	int UniqueId;
	int GatesCount; //Counts the number of gates in the compList
	Component* SelectedComp;
	int SelectedIndex;
public:



public:	
	ApplicationManager(); //constructor

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

	//////////////////////////////////////////////////////////////////// 
	void RemoveComp(int Count); //Removes the component at the given index
	void RemoveAll(); //REmoves all the components in the list

	//take the point clicked to find if it is in the list and return the component type
	//Also returns the index of the found component
	Component* FindComp(int Cx, int Cy, int& Index, CompType& Type);
	Component* GetComp(int i); //returns pointer to component at index i
	Component* GetComp_Id(int Id); //returns the component with this Id

	void AddCopiedComp(CompType Type); //Add the type of the component found at this index
	CompType GetCopiedComp();

	void SaveAll(ofstream& SaveFile);
	void LoadAll(ifstream& LoadFile);

	int GetUniqueId(); //generates a unique id for every component
	bool CheckCircuitValidation(int& InputPins, int& OutputPinsConn);

	void SetSelectedComp(Component* sComponent);
	Component* GetSelectedComp(int& sIndex);

	int ReturnIndex(Component*);
	void RemoveSelectedIndex();

	void SimulateCircuitOutput();

};

#endif