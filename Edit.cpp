#include "Edit.h"

Edit::Edit(ApplicationManager* pMang) : Action(pMang)
{
	x = 0;
	y = 0;
	
	CompToEdit = NULL;
	pInputPin = NULL;

	Index = -1;
}

Edit::~Edit(void)
{}

void Edit::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMsg("Please select connection to edit.");
	pIn->GetPointClicked(x, y);

	CompType TypeToEdit = NoComp;
	CompToEdit = pManager->FindComp(x, y, Index, TypeToEdit);

	if (CompToEdit)
	{
		if (TypeToEdit == Comp_WIRE)
		{
			pOut->PrintMsg("Please enter 1 to change input pin or 2 to change output pin");
			string UserChoice = pIn->GetSrting(pOut);
			pOut->ClearStatusBar();

			if (UserChoice == "1")
			{
				EditInputPin();
				
			}
			else if (UserChoice == "2")
			{
				EditOutputPin();
			}
			else
			{
				pOut->PrintMsg("Action Unsucessful. Please try again.");
			}
		}
	}
}

void Edit::Execute()
{
	ReadActionParameters();
}

void Edit::EditInputPin()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	Connection* ConnToEdit = (Connection*)CompToEdit;
	pOutputPin = ConnToEdit->getSourcePin();

	pOut->PrintMsg("Please click on the gate you want the connection to attach to.");
	pIn->GetPointClicked(x, y);
	int Index2 = -1;
	CompType TypeToEditTo = NoComp;
	Component* CompToEditTo = pManager->FindComp(x, y, Index2, TypeToEditTo);

	if (CompToEditTo && TypeToEditTo != Comp_WIRE)
	{
			Gate* GateToEditTo = (Gate*)CompToEditTo;
			InputPin* InPin[3] = { NULL,NULL,NULL };
			int noOfInputPins = GateToEditTo->get_m_Inputs();
			for (int i = 0; i < noOfInputPins; i++)
			{
				InPin[i] = GateToEditTo->getDestPin(i);
			}

			pOut->PrintMsg("Please enter the index of input pin.");
			string PinChoice = pIn->GetSrting(pOut);
			pOut->ClearStatusBar();

			bool pinConnected;
			int Choice;
			if (PinChoice == "1")
			{
				Choice = 0;
				pinConnected = InPin[Choice]->getIsConnected();
				if (pinConnected==false)
				{
					ConnToEdit->setDestPin(InPin[Choice],Choice);
					pManager->UpdateInterface();
					pOut->DrawConnection()

				}
			}
			else if (PinChoice == "2" && (InPin[1]))
			{
				Choice = 1;
				pinConnected = InPin[Choice]->getIsConnected();
				if (pinConnected==false)
				{
					ConnToEdit->setDestPin(InPin[Choice], Choice);
				}
				else
				{
					pOut->PrintMsg("No connection at chosen input pin.");
				}
			}
			if (PinChoice == "3" && (InPin[2]))
			{
				Choice = 2;
				pinConnected = InPin[Choice]->getIsConnected();
				if (pinConnected==false)
				{
					ConnToEdit->setDestPin(InPin[Choice], Choice);
				}
				else
				{
					pOut->PrintMsg("No connection at chosen input pin.");
				}
			}
		}
}


void Edit::EditOutputPin()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	Connection* ConnToEdit = (Connection*)CompToEdit;

	pOut->PrintMsg("Please click on the new gate.");
	pIn->GetPointClicked(x, y);
	pOut->ClearStatusBar();

	int Index1 = -1; // index of chosen gate in component list

	CompType TypeToEdit;
	Component* nCompToEdit = pManager->FindComp(x, y, Index1, TypeToEdit);

	if (Index1 != -1 && TypeToEdit != Comp_WIRE)
	{
		Gate* nGateToEdit = (Gate*)nCompToEdit;
		OutputPin* OutPin=NULL;
		nGateToEdit->getSourcePinPointer(OutPin);

		bool isFull = OutPin->IsFull();
		if (isFull == false)
		{
			ConnToEdit->setSourcePin(OutPin);
			pManager->UpdateInterface();
			ConnToEdit->Draw(pOut);
		}
	}
	else
	{
		pOut->PrintMsg("Action unsucessful. Please try again.");
	}
}

void Edit::Undo()
{}
void Edit::Redo()
{}
