#include "ApplicationManager.h"
#include "Actions\AddANDgate2.h"
#include "AddOrGate2.h"
#include "AddNandGate2.h"
#include "AddNorGate2.h"
#include "AddXorGate2.h"
#include "AddXnorGate2.h"
#include "AddAndGate3.h"
#include "AddXorGate3.h"
#include "AddNorGate3.h"
#include "AddBuffGate1.h"
#include "AddInvGate1.h"
#include "AddSwitch.h"
#include "AddLed.h"
#include "Copy.h"
#include "Cut.h"
#include "Paste.h"
#include "Save.h"
#include "Load.h"
#include "Select.h"
#include "Delete.h"
#include "ADD_COMP.h"
#include "Gates_1.h"
#include "Gates_2.h"
#include "Exit.h"
#include "Label.h"
#include "Components/Connection.h"
#include "Simulation_Mode.h"
#include "Design_Mode.h"
#include <fstream>
#include"Components/Gate.h"
#include"AddConnection.h"
#include"Simulate.h"
#include "ChangeSwitch.h"
#include"Probing.h"
#include"Move.h"
ApplicationManager::ApplicationManager()
{
	UniqueId = 1;
	CopiedComp = NoComp;
	UniqueId = 1;
	GatesCount = 0;
	/////////////////////////////
	CompCount = 0;

	for(int i=0; i<MaxCompCount; i++)
		CompList[i] = NULL;

	//Creates the Input / Output Objects & Initialize the GUI
	OutputInterface = new Output();
	InputInterface = OutputInterface->CreateInput();

	SelectedComp = NULL;
	SelectedIndex = -1;
}
////////////////////////////////////////////////////////////////////
void ApplicationManager::AddComponent(Component* pComp)
{
	CompList[CompCount++] = pComp;	
	if (pComp->GetCompType() != Comp_WIRE)
	{
		GatesCount++;
	}
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
	case ADD_COMPONENT:
		pAct = new ADD_COMP(this);
		break;

	case ADD_AND_GATE_2:
		pAct = new AddANDgate2(this);
		break;

	case ADD_OR_GATE_2:
		pAct = new AddOrGate2(this);
		break;

	case ADD_NAND_GATE_2:
		pAct = new AddNandGate2(this);
		break;

	case ADD_NOR_GATE_2:
		pAct = new AddNorGate2(this);
		break;

	case ADD_XOR_GATE_2:
		pAct = new AddXorGate2(this);
		break;

	case ADD_XNOR_GATE_2:
		pAct = new AddXnorGate2(this);
		break;

	case ADD_AND_GATE_3:
		pAct = new AddAndGate3(this);
		break;

	case ADD_XOR_GATE_3:
		pAct = new AddXorGate3(this);
		break;

	case ADD_NOR_GATE_3:
		pAct = new AddNorGate3(this);
		break;

	case ADD_Buff:
		pAct = new AddBuffGate1(this);
		break;

	case ADD_INV:
		pAct = new AddInvGate1(this);
		break;

	case ADD_Switch:
		pAct = new AddSwitch(this);
		break;

	case ADD_LED:
		pAct = new AddLed(this);
		break;

	case ADD_CONNECTION:
		pAct = new AddConnection(this);
		break;

	case Gate_Menu1:
		pAct = new Gates_1(this);
		break;

	case Gate_Menu2:
		pAct = new Gates_2(this);
		break;

	case ADD_Label:
		pAct = new Label(this);
		break;

	case COPY:
		pAct = new Copy(this);
		break;

	case PASTE:
		pAct = new Paste(this);
		break;

	case CUT:
		pAct = new Cut(this);
		break;

	case SAVE:
		pAct = new Save(this);
		break;

	case LOAD:
		pAct = new Load(this);
		break;

	case DSN_MODE:
		pAct = new Design_Mode(this);
		break;

	case SIM_MODE:
		pAct = new Simulation_Mode(this);
		break;

	case MOVE:
		pAct = new Move(this);
		break;

	case SIMULATE:
		pAct = new Simulate(this);
		break;

	case SELECT:
		pAct = new Select(this);
		break;
	case PROBE:
		pAct = new Probing(this);
		break;
	case Change_Switch:
		pAct = new ChangeSwitch(this);
		break;
		/*case DEL:
			pAct = new Delete(this);
			break;*/
	}
	if (pAct)
	{
		pAct->Execute();
		delete pAct;
		pAct = NULL;
	}
}
////////////////////////////////////////////////////////////////////

void ApplicationManager::UpdateInterface()
{
	OutputInterface->ClearDrawingArea();
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
bool ApplicationManager::CheckCircuitValidation(int& InputPins, int& OutputPinsConn)
{
	InputPins = 0;              //count the sum of all input pins 
	OutputPinsConn = 0;         //count the sum of all output pins connections
	int SwitchNum = 0;
	int LedNum = 0;
	int CurrOutPinConn;
	if (CompCount == 0)
	{
		return true;
	}
	else
	{
		for (int i = 0; i < CompCount; i++)
		{
			if ((CompList[i]->GetCompType() == Comp_LED))
			{
				LedNum++;
			}
			if ((CompList[i]->GetCompType() == Comp_SWITCH))
			{
				SwitchNum++;
			}
			if (CompList[i]->GetCompType() != Comp_WIRE)
			{
				Gate* CurrentGate;
				CurrentGate = (Gate*)CompList[i];  //casting component to gate pointer
				CurrOutPinConn = CurrentGate->Getm_Conn();  //get the number of connection in the output of the current gate
				if (CurrOutPinConn == 0) // check if it is zero
				{
					return true;  //it mean that the current component has zero connections to the its output pin
				}
				else
				{
					if (CompList[i]->GetCompType() != Comp_LED)
					{
						OutputPinsConn += CurrOutPinConn; //Add the current m_conn to the sum
					}
					InputPins += CurrentGate->GetInputPinsNum(); //add the current input to the sum
				}
			}
		}
	}
	if ((LedNum == 0) || (SwitchNum == 0))
	{
		return true;
	}
	 return false; //it means that all gates has at least 1 connection to their output pin
}

/////////////////////////////////////////////////////////////////////

void ApplicationManager::SimulateCircuitOutput()
{
	bool repeat = true;
	while (repeat)
	{
		repeat = false;
		for (int i = 0;i < CompCount;i++)
		{
			CompList[i]->Operate();  //call operate function 
			if (CompList[i]->NotAssignedInput()) //check if input pin of any gate assigned or not
			{
				repeat = true;
			}
		}
	}
}

Component* ApplicationManager::FindComp(int Cx, int Cy, int& FoundCompCount, CompType& FoundCompType)
{
	FoundCompCount = -1;//Know which component has been clicked on
	GraphicsInfo GInfo;
	FoundCompType = NoComp;
	for (int i = 0; i < CompCount; i++)
	{
		if (CompList[i]->GetCompType() != Comp_WIRE)
		{
			GInfo = CompList[i]->GetGraphicsInfo();
			if (Cx >= GInfo.x1 && Cx <= GInfo.x2 && Cy >= GInfo.y1 && Cy <= GInfo.y2)
			{
				FoundCompType = CompList[i]->GetCompType();
				FoundCompCount = i;
				return CompList[i];
			}
		}
		else
		{
			GInfo = CompList[i]->GetGraphicsInfo();
			if (GInfo.y1 != GInfo.y2 && GInfo.x1 != GInfo.x2)
			{
				if (GInfo.x1 < GInfo.x2)
				{
					if ((Cx >= GInfo.x1 && Cx <= (GInfo.x2 + 20) && Cy >= (GInfo.y1 - 20) && Cy <= (GInfo.y1 + 20)) || (Cx >= (GInfo.x2 - 20) && Cx <= (GInfo.x2 + 20) && Cy <= (GInfo.y1 + 20) && Cy >= GInfo.y2))
					{
						FoundCompType = CompList[i]->GetCompType();
						FoundCompCount = i;
						return CompList[i];
					}
				}
				else
				{
					if ((Cx >= GInfo.x2 && Cx <= (GInfo.x1 + 20) && Cy >= (GInfo.y2 - 20) && Cy <= (GInfo.y2 + 20)) || (Cx >= (GInfo.x1 - 20) && Cx <= (GInfo.x1 + 20) && Cy <= (GInfo.y2 + 20) && Cy >= GInfo.y1))
					{
						FoundCompType = CompList[i]->GetCompType();
						FoundCompCount = i;
						return CompList[i];
					}
				}

			}
			else if (GInfo.x1 != GInfo.x2)
			{
				if ((Cx >= (GInfo.x1 - 15) && Cx <= (GInfo.x1 + 15) && Cy >= (GInfo.y1 + 15) && Cy <= (GInfo.y2 + 15)) || (Cx >= (GInfo.x1 + 15) && Cx <= (GInfo.x2 - 15) && Cy >= (GInfo.y2 - 15) && Cy <= (GInfo.y2 + 15)) || (Cx >= (GInfo.x2 - 15) && Cx <= (GInfo.x2 + 15) && Cy >= (GInfo.y1 + 15) && Cy <= (GInfo.y2 + 15)))
				{
					FoundCompType = CompList[i]->GetCompType();
					FoundCompCount = i;
					return CompList[i];
				}
			}
			else
			{
				if (Cx >= GInfo.x1 && Cx <= GInfo.x2 && Cy >= (GInfo.y1 - 15) && Cy <= (GInfo.y1 + 15))
				{
					FoundCompType = CompList[i]->GetCompType();
					FoundCompCount = i;
					return CompList[i];
				}
			}
		}
	}
}

Component* ApplicationManager::GetComp(int i)
{
	return CompList[i];
}


////////////////////////////////////////////////////////////////////

ApplicationManager::~ApplicationManager()
{
	for(int i=0; i<CompCount; i++)
		delete CompList[i];
	delete OutputInterface;
	delete InputInterface;
	
}

//////////////////////////////////////////////////////////////////// 
void ApplicationManager::RemoveComp(int Count)
{
	if (CompList[Count]->GetCompType() != Comp_WIRE)
	{
		GatesCount--;
	}
	delete CompList[Count]; //delete the dynamically allocated component
	CompList[Count] = NULL;
	for (int i = Count; i < CompCount - 1; i++)
	{
		CompList[i] = CompList[i + 1];
	}
	CompList[CompCount] = NULL;
	CompCount--;
}

void ApplicationManager::RemoveAll()
{
	for (int i = 0; i < CompCount; i++)
	{
		delete CompList[i];
		CompList[i] = NULL;
	}
	CompCount = 0;
	GatesCount = 0;
}

Component* ApplicationManager::GetComp_Id(int Id)
{
	for (int i = 0; i < CompCount; i++)
	{
		Gate* CurrentGate;
		CurrentGate = (Gate*)CompList[i];
		if (CurrentGate->GetId() == Id)
		{
			return CompList[i];
		}
	}
	return NULL;
}

void ApplicationManager::AddCopiedComp(CompType Type)
{
	CopiedComp = Type;
}

CompType ApplicationManager::GetCopiedComp()
{
	return CopiedComp;
}

void ApplicationManager::SaveAll(ofstream& SaveFile)
{
	SaveFile << GatesCount << '\n';  //Add gates number to the file
	for (int i = 0; i < CompCount; i++) //Adding gates data first
	{
		if (CompList[i]->GetCompType() != Comp_WIRE)
		{
			CompList[i]->SaveComp(SaveFile);
		}
	}
	SaveFile << "Connections\n"; //Adding Connections headding
	for (int i = 0; i < CompCount; i++) //Then connections
	{
		if (CompList[i]->GetCompType() == Comp_WIRE)
		{
			CompList[i]->SaveComp(SaveFile);
		}
	}
	SaveFile << -1 << '\n';
}

void ApplicationManager::LoadAll(ifstream& LoadFile)
{
	//Dlete already existing components
	RemoveAll();
	int GatesCount; //Takes the number of gates in the file (not connections)
	string GateType; //Takes the type of the gate
	LoadFile >> GatesCount; //reads GatesCount
	//loop on the file to read each line till it reaches the header "Connection" 
	for (int i = 0; i < GatesCount; i++)
	{
		LoadFile >> GateType; //reads gate type
		if (GateType == "AND2")
		{
			AND2* pComp = new AND2(AND2_FANOUT);
			pComp->LoadComp(LoadFile);
			AddComponent(pComp);
		}
		else if (GateType == "OR2")
		{
			OR* pComp = new OR(AND2_FANOUT);
			pComp->LoadComp(LoadFile);
			AddComponent(pComp);
		}
		else if (GateType == "NAND2")
		{
			NAND* pComp = new NAND(AND2_FANOUT);
			pComp->LoadComp(LoadFile);
			AddComponent(pComp);
		}
		else if (GateType == "NOR2")
		{
			NOR2* pComp = new NOR2(AND2_FANOUT);
			pComp->LoadComp(LoadFile);
			AddComponent(pComp);
		}
		else if (GateType == "XOR2")
		{
			XOR2* pComp = new XOR2(AND2_FANOUT);
			pComp->LoadComp(LoadFile);
			AddComponent(pComp);
		}
		else if (GateType == "XNOR2")
		{
			XNOR* pComp = new XNOR(AND2_FANOUT);
			pComp->LoadComp(LoadFile);
			AddComponent(pComp);
		}
		else if (GateType == "AND3")
		{
			AND3* pComp = new AND3(AND2_FANOUT);
			pComp->LoadComp(LoadFile);
			AddComponent(pComp);
		}
		else if (GateType == "XOR3")
		{
			XOR3* pComp = new XOR3(AND2_FANOUT);
			pComp->LoadComp(LoadFile);
			AddComponent(pComp);
		}
		else if (GateType == "NOR3")
		{
			NOR3* pComp = new NOR3(AND2_FANOUT);
			pComp->LoadComp(LoadFile);
			AddComponent(pComp);
		}
		else if (GateType == "BUFF")
		{
			BUFFER* pComp = new BUFFER(AND2_FANOUT);
			pComp->LoadComp(LoadFile);
			AddComponent(pComp);
		}
		else if (GateType == "INV")
		{
			INVERTER* pComp = new INVERTER(AND2_FANOUT);
			pComp->LoadComp(LoadFile);
			AddComponent(pComp);
		}
		else if (GateType == "SWITCH")
		{
			SWITCH* pComp = new SWITCH(AND2_FANOUT);
			pComp->LoadComp(LoadFile);
			AddComponent(pComp);
		}
		else if (GateType == "LED")
		{
			BULB* pComp = new BULB(AND2_FANOUT);
			pComp->LoadComp(LoadFile);
			AddComponent(pComp);
		}
	}
	Gate* LastGate; //Cast last component to call the GetId function
	LastGate = (Gate*)CompList[CompCount - 1];
	UniqueId = LastGate->GetId() + 1; //reset the unique to the last used Id +1
	//Load connections:
	GraphicsInfo GInfoDefault; //deafult GraphicsInfo to send it to the connection constructor
	GInfoDefault.x1 = -1;
	GInfoDefault.y1 = -1;
	GInfoDefault.x2 = -1;
	GInfoDefault.y2 = -1;
	LoadFile >> GateType; //Reads connection header
	while (true)
	{
		Connection* Conn= new Connection(GInfoDefault, this);
		Conn->LoadComp(LoadFile);
		GraphicsInfo CurrentGInfo;
		CurrentGInfo = Conn->GetGraphicsInfo();
		if (CurrentGInfo.x1 == GInfoDefault.x1 && CurrentGInfo.x2 == GInfoDefault.x2 && CurrentGInfo.y1 == GInfoDefault.y1 && CurrentGInfo.y2 == GInfoDefault.y2)
		{
			//This means that the default graphics info is unchanged
			delete Conn;
			break;
		}
		AddComponent(Conn);
	}
}

int ApplicationManager::GetUniqueId()
{
	return UniqueId++;
}

void ApplicationManager::SetSelectedComp(Component* sComponent)
{
	SelectedComp = sComponent;
	for (int i = 0; i < CompCount; i++)
	{
		if (SelectedComp == CompList[i])
		{
			SelectedIndex = i;
			break;
		}
	}
}
Component* ApplicationManager::GetSelectedComp(int& sIndex)
{
	sIndex = SelectedIndex;
	return SelectedComp;
}

int ApplicationManager::ReturnIndex(Component* pComp)
{
	for (int i = 0; i < CompCount; i++)
	{
		if (CompList[i] == pComp)
		{
			return i;
		}
	}
}
void ApplicationManager::RemoveSelectedIndex()
{
	SelectedIndex = -1;
}