#include "SWITCH.h"
#include <iomanip>  

SWITCH::SWITCH(int r_FanOut) :Gate(0, r_FanOut)
{
}

SWITCH::SWITCH(const GraphicsInfo& r_GfxInfo, int r_FanOut, int Id, string Label) : Gate(0, r_FanOut)
{
	m_GfxInfo.x1 = r_GfxInfo.x1;
	m_GfxInfo.y1 = r_GfxInfo.y1;
	m_GfxInfo.x2 = r_GfxInfo.x2;
	m_GfxInfo.y2 = r_GfxInfo.y2;
	this->Id = Id;
	SetLabel(Label);
	setSelected(false);
}


void SWITCH::Operate()
{
	//caclulate the output status 

	//Add you code here
	if (getResult())
	{
		m_OutputPin.setStatus(STATUS::LOW);
	}
	else
	{
		m_OutputPin.setStatus(STATUS::HIGH);
	}
}


// Function Draw
// Draws SWITCH
void SWITCH::Draw(Output* pOut)
{
	//Call output class and pass gate drawing info to it.
	pOut->DrawSWITCH(m_GfxInfo, getSelected(),getResult());
}

//returns status of outputpin
int SWITCH::GetOutPinStatus()
{
	return m_OutputPin.getStatus();
}


//returns status of Inputpin #n
int SWITCH::GetInputPinStatus(int n)
{
	return -1;
}

void SWITCH::setInputPinStatus(int n, STATUS s)
{
}


OutputPin* SWITCH::getSourcePin()
{
	return &m_OutputPin;
}

InputPin* SWITCH::getDestPin(int n)
{
	return nullptr;
}


CompType SWITCH::GetCompType()
{
	return Comp_SWITCH;
}

void SWITCH::SaveComp(ofstream& SaveFile)
{
	GraphicsInfo GInfo = GetGraphicsInfo(); //Converting rectangular coordinates to center point
	int Cx = GInfo.x1 + (UI.AND2_Width / 2);
	int Cy = GInfo.y1 + (UI.AND2_Height / 2);
	//Format output
	SaveFile << left << setw(8) << "SWITCH" << setw(5) << Id << setw(12) << GetLabel() << setw(5) << Cx << Cy << '\n';
}

void SWITCH::LoadComp(ifstream& LoadFile)
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

int SWITCH::GetInputPinsNum()
{
	return 0;
}

int SWITCH::Getm_Conn()
{
	return m_OutputPin.Getm_Conn();
}

bool SWITCH::NotAssignedInput()
{
	return false;
}