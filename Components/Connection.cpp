#include "Connection.h"
#include <iomanip>  
#include "Gate.h"

Connection::Connection(const GraphicsInfo& r_GfxInfo, ApplicationManager* pApp) :Component(r_GfxInfo)
{
	pManager = pApp;
	setSelected(false);
	Status = false;
}
Connection::Connection(const GraphicsInfo& r_GfxInfo, OutputPin* pSrcPin, InputPin* pDstPin, int c) :Component(r_GfxInfo)

{
	SrcPin = pSrcPin;
	DstPin = pDstPin;
	IndexDstPin = c;
	Status = false;
}
void Connection::setSourcePin(OutputPin* pSrcPin)
{
	SrcPin = pSrcPin;
}

OutputPin* Connection::getSourcePin()
{
	return SrcPin;
}


void Connection::setDestPin(InputPin* pDstPin, int c)
{
	DstPin = pDstPin;
	IndexDstPin = c;
}

InputPin* Connection::getDestPin()
{
	return DstPin;
}


void Connection::Operate()
{
	//Status of connection destination pin = status of connection source pin
	DstPin->setStatus((STATUS)SrcPin->getStatus());
}

void Connection::Draw(Output* pOut)
{
	pOut->DrawConnection(m_GfxInfo, getSelected(), SrcPin->getStatus());
}

int Connection::GetOutPinStatus()	//returns status of outputpin if LED, return -1
{
	return DstPin->getStatus();
}


int Connection::GetInputPinStatus(int n)	//returns status of Inputpin # n if SWITCH, return -1
{
	return SrcPin->getStatus();	//n is ignored as connection has only one input pin (src pin)	
}

void Connection::setInputPinStatus(int n, STATUS s)
{
	SrcPin->setStatus(s);
}

CompType Connection::GetCompType()
{
	return Comp_WIRE;
}
	
void Connection::SaveComp(ofstream& SaveFile)
{
	Gate* SrcGate;
	Gate* DstGate;
	SrcGate = (Gate*)SrcCmpnt;
	DstGate = (Gate*)DstCmpnt;
	SaveFile << left << setw(8) << SrcGate->GetId() << setw(5) << DstGate->GetId() << setw(12) << IndexDstPin << '\n';
}

void Connection::LoadComp(ifstream& LoadFile)
{
	int SrcId, DstId;
	LoadFile >> SrcId;
	if (SrcId != -1)// check if it is the end of the file
	{
		LoadFile >> DstId >> IndexDstPin;
		IndexDstPin -= 1;
		SrcCmpnt = pManager->GetComp_Id(SrcId);
		DstCmpnt = pManager->GetComp_Id(DstId);
		Gate* SrcGate;
		Gate* DstGate;
		SrcGate = (Gate*)SrcCmpnt;
		DstGate = (Gate*)DstCmpnt;
		SrcGate->GetOutputPinCoordinates(m_GfxInfo.x1, m_GfxInfo.y1);
		DstGate->GetInputPinCoordinates(m_GfxInfo.x2, m_GfxInfo.y2, IndexDstPin);
		SrcPin = SrcGate->getSourcePin();
		if (SrcPin) //if SrcPin != NULL
		{
			SrcPin->ConnectTo(this);
		}
		DstPin = DstGate->getDestPin(IndexDstPin);
		DstPin->setConnection(this);
	}
}



void Connection::SetSrcComp(Component* SrcComp)
{
	this->SrcCmpnt = SrcComp;
}

bool Connection::Found(int x, int y)
{
	return false;
}

bool Connection::NotAssignedInput()
{
	if (DstPin->getStatus() == STATUS::NOTAssigned)
	{
		return true;
	}
	return false;
}

bool Connection::getProbResult()
{
	if (DstPin->getStatus() == STATUS::HIGH)
	{
		Status = true;
		return Status;
	}
	else
	{
		Status = false;
	    return Status;
	}

}