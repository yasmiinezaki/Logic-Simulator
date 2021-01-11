#include "INVERTER.h"
#include <iomanip>  

INVERTER::INVERTER(int r_FanOut) :Gate(1, r_FanOut)
{
}

INVERTER::INVERTER(const GraphicsInfo& r_GfxInfo, int r_FanOut, int Id, string Label) : Gate(1, r_FanOut)
{
	m_GfxInfo.x1 = r_GfxInfo.x1;
	m_GfxInfo.y1 = r_GfxInfo.y1;
	m_GfxInfo.x2 = r_GfxInfo.x2;
	m_GfxInfo.y2 = r_GfxInfo.y2;
	this->Id = Id;
	SetLabel(Label);
	setSelected(false);
}



void INVERTER::Operate()
{
	//caclulate the output status 

	//Add you code here

	//IN INVERTER operate it return the oppsite of the input , if the input is HIGH the output is LOW and vise a versa.
	if (NotAssignedInput())
	{
		m_OutputPin.setStatus(STATUS::NOTAssigned);
	}
	else
	{
		m_OutputPin.setStatus(m_InputPins[0].getStatus() == STATUS::HIGH ? STATUS::LOW : STATUS::HIGH);
	}
}


// Function Draw
// Draws INVERTER gate
void INVERTER::Draw(Output* pOut)
{
	//Call output class and pass gate drawing info to it.
	pOut->DrawINVERTER(m_GfxInfo, getSelected());
}

//returns status of outputpin
int INVERTER::GetOutPinStatus()
{
	return m_OutputPin.getStatus();
}


//returns status of Inputpin #n
int INVERTER::GetInputPinStatus(int n)
{
	return m_InputPins[n - 1].getStatus();	//n starts from 1 but array index starts from 0.
}

//Set status of an input pin ot HIGH or LOW
void INVERTER::setInputPinStatus(int n, STATUS s)
{
	m_InputPins[n - 1].setStatus(s);
}

//returns no. of input pins.
int INVERTER::GetInputPinsNum()
{
	return 1;
}

int INVERTER::Getm_Conn()
{
	return m_OutputPin.Getm_Conn();
}

CompType INVERTER::GetCompType()
{
	return CompType(Comp_INV);
}
OutputPin* INVERTER::getSourcePin()
{
	return &m_OutputPin;
}

InputPin* INVERTER::getDestPin(int n)
{
	return &m_InputPins[n];
}

void INVERTER::SaveComp(ofstream& SaveFile)
{
	GraphicsInfo GInfo = GetGraphicsInfo(); //Converting rectangular coordinates to center point
	int Cx = GInfo.x1 + (UI.AND2_Width / 2);
	int Cy = GInfo.y1 + (UI.AND2_Height / 2);
	//Format output
	SaveFile << left << setw(8) << "INV" << setw(5) << Id << setw(12) << GetLabel() << setw(5) << Cx << Cy << '\n';
}

void INVERTER::LoadComp(ifstream& LoadFile)
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

