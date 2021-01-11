#include "XOR2.h"
#include <iomanip>

XOR2::XOR2(int r_FanOut) :Gate(2, r_FanOut)
{
}

XOR2::XOR2(const GraphicsInfo& r_GfxInfo, int r_FanOut, int Id, string Label) : Gate(2, r_FanOut)
{
	m_GfxInfo.x1 = r_GfxInfo.x1;
	m_GfxInfo.y1 = r_GfxInfo.y1;
	m_GfxInfo.x2 = r_GfxInfo.x2;
	m_GfxInfo.y2 = r_GfxInfo.y2;
	this->Id = Id;
	SetLabel(Label);
	setSelected(false);
}

void XOR2::Operate()
{
	//caclulate the output status 

	//Add you code here

	//XOR2 gate return 0 when two inputs are similar , return 1 when two inputs are different.
	if (NotAssignedInput())
	{
		m_OutputPin.setStatus(STATUS::NOTAssigned);
	}
	{
		bool result = 0;
		for (int i = 0; i < m_Inputs; i++)
		{
			if (result == (m_InputPins[i].getStatus()))
			{
				result = 0;
			}
			else if (result != (m_InputPins[i].getStatus()))
			{
				result = 1;
			}
		}
		//If result 1 (true) output HIGH , result 0 (false) output (LOW).
		m_OutputPin.setStatus(result ? STATUS::HIGH : STATUS::LOW);
	}
}


// Function Draw
// Draws XOR2 gate
void XOR2::Draw(Output* pOut)
{
	//Call output class and pass gate drawing info to it.
	pOut->DrawXOR2(m_GfxInfo, getSelected());
}

//returns status of outputpin
int XOR2::GetOutPinStatus()
{
	return m_OutputPin.getStatus();
}


//returns status of Inputpin #n
int XOR2::GetInputPinStatus(int n)
{
	return m_InputPins[n - 1].getStatus();	//n starts from 1 but array index starts from 0.
}

//Set status of an input pin ot HIGH or LOW
void XOR2::setInputPinStatus(int n, STATUS s)
{
	m_InputPins[n - 1].setStatus(s);
}

//returns no. of input pins.
int XOR2::GetInputPinsNum()
{
	return 2;
}

int XOR2::Getm_Conn()
{
	return m_OutputPin.Getm_Conn();
}

CompType XOR2::GetCompType()
{
	return Comp_XOR2;
}
OutputPin* XOR2::getSourcePin()
{
	return &m_OutputPin;
}

InputPin* XOR2::getDestPin(int n)
{
	return &m_InputPins[n];
}

void XOR2::SaveComp(ofstream& SaveFile)
{
	GraphicsInfo GInfo = GetGraphicsInfo(); //Converting rectangular coordinates to center point
	int Cx = GInfo.x1 + (UI.AND2_Width / 2);
	int Cy = GInfo.y1 + (UI.AND2_Height / 2);
	//Format output
	SaveFile << left << setw(8) << "XOR2" << setw(5) << Id << setw(12) << GetLabel() << setw(5) << Cx << Cy << '\n';
}

void XOR2::LoadComp(ifstream& LoadFile)
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

