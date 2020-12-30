#include "ApplicationManager.h"
#include "Actions/AddANDgate2.h"
#include "Select.h"
#include "Delete.h"
#include "Label.h"

ApplicationManager::ApplicationManager()
{
	CompCount = 0;
	for(int i=0; i<MaxCompCount; i++)
		CompList[i] = NULL;

	//Creates the Input / Output Objects & Initialize the GUI
	OutputInterface = new Output();
	InputInterface = OutputInterface->CreateInput();
}

// delete component from CompList
void ApplicationManager::RemoveComp(int Count)
{
	for (int i = Count; i < CompCount - 1; i++)
	{
		CompList[i] = CompList[i + 1];
	}
	CompList[CompCount] = NULL;
	CompCount--;
}

CompType ApplicationManager::FindComp(int Cx, int Cy, int& FoundCompCount)
{
	FoundCompCount = -1;//Know which component has been clicked on
	GraphicsInfo GInfo;
	CompType FoundCompType = NoComp;
	for (int i = 0; i < CompCount; i++)
	{
		GInfo = CompList[i]->GetGraphicsInfo();
		if (Cx >= GInfo.x1 && Cx <= GInfo.x2 && Cy >= GInfo.y1 && Cy <= GInfo.y2)
		{
			FoundCompType = CompList[i]->GetCompType();
			FoundCompCount = i;
			break;
		}
	}
	return FoundCompType;
}

Component* ApplicationManager::getComp(int i)
{
	return CompList[i];
}

////////////////////////////////////////////////////////////////////
void ApplicationManager::AddComponent(Component* pComp)
{
	CompList[CompCount++] = pComp;		
}
////////////////////////////////////////////////////////////////////

ActionType ApplicationManager::GetUserAction()
{
	//Call input to get what action is reuired from the user
	return InputInterface->GetUserAction(); 	
}
////////////////////////////////////////////////////////////////////

void ApplicationManager::ExecuteAction(ActionType ActType)
{
	Action* pAct = NULL;
	switch (ActType)
	{
		case ADD_AND_GATE_2:
			pAct= new AddANDgate2(this);
			break;

		case ADD_CONNECTION:
			//TODO: Create AddConection Action here
			break;
	
		case ADD_COMPONENT:
			UI.GateMenuNo = GATE_MODE1;
			break;

		case SELECT:
			pAct = new Select(this);
			break;
		case DEL:
			pAct = new Delete(this);
			break;
		case ADD_Label:
			pAct = new Label(this);
			break;

		case EXIT:
			///TODO: create ExitAction here
			break;
	}
	if(pAct)
	{
		pAct->Execute();
		delete pAct;
		pAct = NULL;
	}
}
////////////////////////////////////////////////////////////////////

void ApplicationManager::UpdateInterface()
{
		for(int i=0; i<CompCount; i++)
			CompList[i]->Draw(OutputInterface);

}

////////////////////////////////////////////////////////////////////
Input* ApplicationManager::GetInput()
{
	return InputInterface;
}

////////////////////////////////////////////////////////////////////
Output* ApplicationManager::GetOutput()
{
	return OutputInterface;
}

////////////////////////////////////////////////////////////////////

ApplicationManager::~ApplicationManager()
{
	for(int i=0; i<CompCount; i++)
		delete CompList[i];
	delete OutputInterface;
	delete InputInterface;
	
}
