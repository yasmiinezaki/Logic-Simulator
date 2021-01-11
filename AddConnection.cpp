#include "AddConnection.h"
#include "../Project Code Framework/ApplicationManager.h"
#include "Components/Gate.h"

AddConnection::AddConnection(ApplicationManager* pApp) :Action(pApp)
{
	SrcPin = NULL;
	DstPin = NULL;
}

AddConnection::~AddConnection(void)
{
}

void AddConnection::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	//Print Action Message
	pOut->PrintMsg("Drawing a connection: Please click on the source gate");

	//Wait for User Input
	pIn->GetPointClicked(x1, y1);

	//Clear Status Bar
	pOut->ClearStatusBar();

	//Print Action Message
	pOut->PrintMsg("Drawing a connection: Please click on the destination gate");

	//Wait for User Input
	pIn->GetPointClicked(x2, y2);

	//Clear Status Bar
	pOut->ClearStatusBar();

}

void AddConnection::Execute()
{
	ReadActionParameters();
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	bool c = DetectSrcValidity();
	if (c == false)
	{
		pOut->PrintMsg("Invalid Source Pin. Operation is Cancelled");
		return;
	}
	bool d = DetectDstValidity();
	if (d == false)
	{
		pOut->PrintMsg("Invalid Destination Pin. Operation is Cancelled");
		return;
	}
	rconnection = new Connection(CGInfo, SrcPin, DstPin, indDstPin);
	pManager->AddComponent(rconnection);
}

bool AddConnection::DetectSrcValidity()
{
	int a;
	CompType c;
	Component* comp = pManager->FindComp(x1, y1, a, c);

	if (c == NoComp || c == Comp_LED)
	{
		return false;
	}
	else
	{
		Gate* gate;
		gate = (Gate*)comp;
		gate->GetOutputPinCoordinates(x1, y1);
		//pManager->GetOutput()->TestFunction(x1, y1, 30);
		CGInfo.x1 = x1;
		CGInfo.y1 = y1;
		SrcPin = gate->getSourcePin();
	}
	if (SrcPin->ConnectTo(rconnection) == false)
	{
		return false;
	}
	return true;
}

bool AddConnection::DetectDstValidity()
{
	int a;
	CompType c;
	Component* comp = pManager->FindComp(x2, y2, a, c);
	if (c == NoComp || c == Comp_SWITCH)
	{
		return false;
	}
	else
	{
		Gate* gate;
		gate = (Gate*)comp;
		indDstPin = gate->GetIndex();
		if (indDstPin == -1)
		{
			return false;
		}
		gate->GetInputPinCoordinates(x2, y2, indDstPin);
		CGInfo.x2 = x2;
		CGInfo.y2 = y2;
		DstPin = gate->getDestPin(indDstPin);
	}
	return true;
}

void AddConnection::Undo()
{}

void AddConnection::Redo()
{}