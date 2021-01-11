#include "XOR3.h"
#include <iomanip>  

XOR3::XOR3(int r_FanOut) :Gate(3, r_FanOut)
{
}

XOR3::XOR3(const GraphicsInfo& r_GfxInfo, int r_FanOut, int Id, string Label) : Gate(3, r_FanOut)
{
	m_GfxInfo.x1 = r_GfxInfo.x1;
	m_GfxInfo.y1 = r_GfxInfo.y1;
	m_GfxInfo.x2 = r_GfxInfo.x2;
	m_GfxInfo.y2 = r_GfxInfo.y2;
	this->Id = Id;
	SetLabel(Label);
	setSelected(false);
}

void XOR3::Operate()
{
	//caclulate the output status 

	//Add you code here
	if (NotAssignedInput())
	{
		m_OutputPin.setStatus(STATUS::NOTAssigned);
	}
	else
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
// Draws XOR3 gate
void XOR3::Draw(Output* pOut)
{
	//Call output class and pass gate drawing info to it.
	pOut->DrawXOR3(m_GfxInfo, getSelected());
	pOut->PrintLabelInDrawingArea(GetLabel(), m_GfxInfo);
}

//returns status of outputpin
int XOR3::GetOutPinStatus()
{
	return m_OutputPin.getStatus();
}


//returns status of Inputpin #n
int XOR3::GetInputPinStatus(int n)
{
	return m_InputPins[n - 1].getStatus();	//n starts from 1 but array index starts from 0.
}

//Set status of an input pin ot HIGH or LOW
void XOR3::setInputPinStatus(int n, STATUS s)
{
	m_InputPins[n - 1].setStatus(s);
}

//returns no. of input pins.
int XOR3::GetInputPinsNum()
{
	return 3;
}

int XOR3::Getm_Conn()
{
	return m_OutputPin.Getm_Conn();
}

CompType XOR3::GetCompType()
{
	return Comp_XOR3;
}

OutputPin* XOR3::getSourcePin()
{
	return &m_OutputPin;
}

InputPin* XOR3::getDestPin(int n)
{
	return &m_InputPins[n];
}
void XOR3::SaveComp(ofstream& SaveFile)
{
	GraphicsInfo GInfo = GetGraphicsInfo(); //Converting rectangular coordinates to center point
	int Cx = GInfo.x1 + (UI.AND2_Width / 2);
	int Cy = GInfo.y1 + (UI.AND2_Height / 2);
	//Format output
	SaveFile << left << setw(8) << "XOR3" << setw(5) << Id << setw(12) << GetLabel() << setw(5) << Cx << Cy << '\n';
}

void XOR3::LoadComp(ifstream& LoadFile)
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

