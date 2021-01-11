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
	
	int z, w;
	Component* NotEditedComp = pOutputPin->getCompConnected();
	Gate* NotEditedGate = (Gate*)NotEditedComp;
	NotEditedGate->GetOutputPinCoordinates(z, w);

	pOut->PrintMsg("Please click on the gate you want the connection to attach to.");
	pIn->GetPointClicked(x, y);
	pOut->ClearStatusBar();

	int Index2 = -1;
	CompType TypeToEditTo = NoComp;
	Component* CompToEditTo = pManager->FindComp(x, y, Index2, TypeToEditTo);

	if (CompToEditTo && TypeToEditTo != Comp_WIRE)
	{
			Gate* GateToEditTo = (Gate*)CompToEditTo;
			int Ind = -1;
			Ind=GateToEditTo->GetIndex();
			InputPin* InPin = NULL;
			if (Ind != -1)
			{
				InPin = GateToEditTo->getDestPin(Ind);

				GateToEditTo->GetInputPinCoordinates(x, y, Ind);
				GraphicsInfo gInfo;
				gInfo.x1 = z;
				gInfo.y1 = w;
				gInfo.x2 = x;
				gInfo.y2 = y;
				Component* comp = ConnToEdit->getDstCmpnt();
				int mm = ConnToEdit->getIndexDstPin();
				Gate* gate = (Gate*)comp;
				gate->ResetDstPinValidity(mm);
				ConnToEdit->setGrxInfo(gInfo);
				ConnToEdit->setDestPin(InPin, Ind);
			}
	}
}


void Edit::EditOutputPin()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	Connection* ConnToEdit = (Connection*)CompToEdit;
	pInputPin = ConnToEdit->getDestPin();

	int t, s;
	Component* CompNotEdited = pInputPin->getComponent();
	Gate* GateNotEdited = (Gate*)CompNotEdited;
	int count = GateNotEdited->GetIndex();
	GateNotEdited->GetInputPinCoordinates(t, s,count);

	pOut->PrintMsg("Please click on the new gate.");
	pIn->GetPointClicked(x, y);
	pOut->ClearStatusBar();

	int Index1 = -1; // index of chosen gate in component list

	CompType TypeToEdit= NoComp;
	Component* nCompToEdit = pManager->FindComp(x, y, Index1, TypeToEdit);

	if (nCompToEdit && TypeToEdit != Comp_WIRE)
	{
		Gate* nGateToEdit = (Gate*)nCompToEdit;
		OutputPin* OutPin=NULL;
		nGateToEdit->getSourcePinPointer(OutPin);
		nGateToEdit->GetOutputPinCoordinates(x, y);
		GraphicsInfo GrInfo;
		GrInfo.x1 = x;
		GrInfo.y1 = y;
		GrInfo.x2 = t;
		GrInfo.y2 = s;

		bool isFull = OutPin->IsFull();
		if (isFull == false)
		{
			Component* comp = ConnToEdit->getSrcCmpnt();
			Gate* gate = (Gate*)comp;
			gate->ResetSrcPinValidity();
			ConnToEdit->setGrxInfo(GrInfo);
			ConnToEdit->setSourcePin(OutPin);
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
