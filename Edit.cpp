#include "Edit.h"

Edit::Edit(ApplicationManager* pMang) : Action(pMang)
{
	x = 0;
	y = 0;
	
	CompToEdit = NULL;
	pInputPin = NULL;
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

	int Index = -1;
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

	Connection* ConnToEdit = (Connection*) CompToEdit;
	pOutputPin =ConnToEdit->getSourcePin();
	pInputPin = ConnToEdit->getDestPin();

	pOut->PrintMsg("Please click on the gate you want the connection to attach to.");
	pIn->ReturnPointClicked(x, y);
	int Index2 = -1;
	CompType TypeToEditTo = NoComp;
	Component* CompToEditTo = pManager->FindComp(x, y, Index2, TypeToEditTo);

	if(CompToEditTo)
	{ 
		if(TypeToEditTo != Comp_WIRE)
		{
			Gate* GateToEditTo = (Gate*)CompToEditTo;
			InputPin* InPin[3] = { NULL,NULL,NULL};
			for (int i = 0; i < noOfInputPins; i++)
			{
				InputPin* InPin[i] = GateToEditTo->getDestPin(i);
			}
		    bool pinValidity;
		    int Choice;
				if (PinChoice == "1")
				{
					Choice = 0;
					pinValidity = pInputPin[Choice]->getIsConnected();
					if (pinValidity)
					{
						EditInputPin(0);
					}
					else
					{
						pOut->PrintMsg("No connection at chosen input pin.");
					}
				}
				else if (PinChoice == "2" && (pInputPin[1]))
				{
					Choice = 1;
					pinValidity = pInputPin[Choice]->getIsConnected();
					if (pinValidity)
					{
						EditInputPin(1);
					}
					else
					{
						pOut->PrintMsg("No connection at chosen input pin.");
					}
				}
				if (PinChoice == "3" && (pInputPin[2]))
				{
					Choice = 2;
					pinValidity = pInputPin[Choice]->getIsConnected();
					if (pinValidity)
					{
						EditInputPin(2);
					}
					else
					{
						pOut->PrintMsg("No connection at chosen input pin.");
					}
				}

	pOut->PrintMsg("Please click on the new gate.");
	pIn->GetPointClicked(x, y);
	pOut->ClearStatusBar();

	int Index1=-1; // index of chosen gate in component list

	CompType TypeToEdit;
	Component* CompToEdit = pManager->FindComp(x, y, Index1, TypeToEdit);

	if (Index1 != -1 && TypeToEdit!= Comp_WIRE)
	{
		Gate* GateToEdit = (Gate*)CompToEdit;

		// get output pin of gate
		OutputPin* pOutPin;
		GateToEdit->getSourcePinPointer(pOutPin);
		bool Validity = pOutPin->IsFull();
		if (!Validity)
		{  
			
				Connection* ConnToEdit = pInputPin[i]->getConnection();
				ConnToEdit->setSourcePin(GateToEdit->getSourcePin());
			
		}
		else
		{
			pOut->PrintMsg("Pin invalid. Please try again");
		}
	}
	else
	{
		pOut->PrintMsg("Action unsucessful. Please try again.");
	}
}

void Edit::EditOutputPin()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();


	pOut->PrintMsg("Please click on the new gate.");
	pIn->GetPointClicked(x, y);
	pOut->ClearStatusBar();

	int Index1 = -1; // index of chosen gate in component list

	CompType TypeToEdit;
	Component* nCompToEdit = pManager->FindComp(x, y, Index1, TypeToEdit);

	if (Index1 != -1 && TypeToEdit != Comp_WIRE)
	{
		Gate* nGateToEdit = (Gate*)nCompToEdit;
		int nOfInputPins = nGateToEdit->get_m_Inputs();

		// get input pins of gate
		InputPin* npInPin[3] = { NULL,NULL,NULL };
		for (int i = 0; i < nOfInputPins; i++)
		{
			nGateToEdit->getDestPinPointer(npInPin[i],i);
		}

		pOut->PrintMsg("Please Enter the index of the input you want to change the connection to.");
		string PinChoice = pIn->GetSrting(pOut);
		pOut->ClearStatusBar();

		bool nPinValidity;
		if (PinChoice == "1")
		{
			int choice = 0;
			nPinValidity = npInPin[choice]->getIsConnected();
			if (nPinValidity)
			{
			}
		}
		else if (PinChoice == "2")
		{

		}
		else if (PinChoice == "3")
		{

		}
		else
		{
			pOut->PrintMsg("Pin invalid. Please try again");
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
