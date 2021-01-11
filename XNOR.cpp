#include "XNOR.h"
#include <iomanip>

XNOR::XNOR(int r_FanOut) :Gate(2, r_FanOut)
{
}

XNOR::XNOR(const GraphicsInfo& r_GfxInfo, int r_FanOut, int Id, string Label) : Gate(2, r_FanOut)
{
	m_GfxInfo.x1 = r_GfxInfo.x1;
	m_GfxInfo.y1 = r_GfxInfo.y1;
	m_GfxInfo.x2 = r_GfxInfo.x2;
	m_GfxInfo.y2 = r_GfxInfo.y2;
	this->Id = Id;
	SetLabel(Label);
	setSelected(false);
}



void XNOR::Operate()
{
	//caclulate the output status 

	//Add you code here

	/*XNOR gate is reverse of XOR gate, it returns 0 when two inputs are similar ,
	returns 1 when two inputs are different*/
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
		//If result 1 (true) output LOW , result 0 (false) output HIGH.
		m_OutputPin.setStatus(result ? STATUS::LOW : STATUS::HIGH);
	}
}


// Function Draw
// Draws XNOR gate
void XNOR::Draw(Output* pOut)
{
	//Call output class and pass gate drawing info to it.
	pOut->DrawXNOR(m_GfxInfo, getSelected());
}

//returns status of outputpin
int XNOR::GetOutPinStatus()
{
	return m_OutputPin.getStatus();
}


//returns status of Inputpin #n
int XNOR::GetInputPinStatus(int n)
{
	return m_InputPins[n - 1].getStatus();	//n starts from 1 but array index starts from 0.
}

//Set status of an input pin ot HIGH or LOW
void XNOR::setInputPinStatus(int n, STATUS s)
{
	m_InputPins[n - 1].setStatus(s);
}

//returns no. of input pins.
int XNOR::GetInputPinsNum()
{
	return 2;
}

int XNOR::Getm_Conn()
{
	return m_OutputPin.Getm_Conn();
}

CompType XNOR::GetCompType()
{
	return Comp_XNOR2;
}
OutputPin* XNOR::getSourcePin()
{
	return &m_OutputPin;
}

InputPin* XNOR::getDestPin(int n)
{
	return &m_InputPins[n];
}

void XNOR::SaveComp(ofstream& SaveFile)
{
	GraphicsInfo GInfo = GetGraphicsInfo(); //Converting rectangular coordinates to center point
	int Cx = GInfo.x1 + (UI.AND2_Width / 2);
	int Cy = GInfo.y1 + (UI.AND2_Height / 2);
	//Format output
	SaveFile << left << setw(8) << "XNOR2" << setw(5) << Id << setw(12) << GetLabel() << setw(5) << Cx << Cy << '\n';
}

void XNOR::LoadComp(ifstream& LoadFile)
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

