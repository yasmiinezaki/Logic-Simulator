#include "BULB.h"
#include <iomanip> 

BULB::BULB(int r_FanOut) :Gate(1, 0)
{
}

BULB::BULB(const GraphicsInfo& r_GfxInfo, int r_FanOut, int Id, string Label) : Gate(1, 0)
{
	m_GfxInfo.x1 = r_GfxInfo.x1;
	m_GfxInfo.y1 = r_GfxInfo.y1;
	m_GfxInfo.x2 = r_GfxInfo.x2;
	m_GfxInfo.y2 = r_GfxInfo.y2;
	this->Id = Id;
	SetLabel(Label);
	setSelected(false);
}



void BULB::Operate()
{
	//caclulate the output status 

	//Add you code here
	if (!NotAssignedInput())
	{
		if (bulbOutput())
		{
			m_InputPins->getStatus() == STATUS::HIGH;
		}
		else
		{
			m_InputPins->getStatus() == STATUS::LOW;
		}
	}
}
bool BULB::bulbOutput()
{
	if (m_InputPins->getStatus() == STATUS::HIGH)
	{
		return true;
	}
	else
	{
		return false;
	}
}

// Function Draw
// Draws BULB
void BULB::Draw(Output* pOut)
{
	//Call output class and pass gate drawing info to it.
	pOut->DrawBULB(m_GfxInfo, getSelected(), bulbOutput());
}

//returns status of outputpin
int BULB::GetOutPinStatus()
{
	return -1;
}


//returns status of Inputpin #n
int BULB::GetInputPinStatus(int n)
{
	return m_InputPins[n - 1].getStatus();	//n starts from 1 but array index starts from 0.
}

//Set status of an input pin ot HIGH or LOW
void BULB::setInputPinStatus(int n, STATUS s)
{
	m_InputPins[n - 1].setStatus(s);
}

CompType BULB::GetCompType()
{
	return Comp_LED;
}
OutputPin* BULB::getSourcePin()
{
	return nullptr;
}

InputPin* BULB::getDestPin(int n)
{
	return &m_InputPins[n];
}

void BULB::SaveComp(ofstream& SaveFile)
{
	GraphicsInfo GInfo = GetGraphicsInfo(); //Converting rectangular coordinates to center point
	int Cx = GInfo.x1 + (UI.AND2_Width / 2);
	int Cy = GInfo.y1 + (UI.AND2_Height / 2);
	//Format output
	SaveFile << left << setw(8) << "LED" << setw(5) << Id << setw(12) << GetLabel() << setw(5) << Cx << Cy << '\n';
}

void BULB::LoadComp(ifstream& LoadFile)
{
	//Variables to read the data
	int Cx, Cy, Id;
	string Label;
	LoadFile >> Id >> Label >> Cx >> Cy;
	//To calculate rectangular corners
	int Len = UI.AND2_Width;
	int Wdth = UI.AND2_Height;
	//setting the data of the gate
	m_GfxInfo.x1 = Cx - Len / 2;
	m_GfxInfo.x2 = Cx + Len / 2;
	m_GfxInfo.y1 = Cy - Wdth / 2;
	m_GfxInfo.y2 = Cy + Wdth / 2;
	this->Id = Id;
	SetLabel(Label);
}

int BULB::GetInputPinsNum()
{
	return 1;
}

int BULB::Getm_Conn()
{
	return -1;
}


