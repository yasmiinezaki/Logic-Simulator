#include "NOR3.h"
#include <iomanip>  

NOR3::NOR3(int r_FanOut) :Gate(3, r_FanOut)
{
}

NOR3::NOR3(const GraphicsInfo& r_GfxInfo, int r_FanOut, int Id, string Label) : Gate(3, r_FanOut)
{
	m_GfxInfo.x1 = r_GfxInfo.x1;
	m_GfxInfo.y1 = r_GfxInfo.y1;
	m_GfxInfo.x2 = r_GfxInfo.x2;
	m_GfxInfo.y2 = r_GfxInfo.y2;
	this->Id = Id;
	SetLabel(Label);
	setSelected(false);
}

void NOR3::Operate()
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
			result = result || (m_InputPins[i].getStatus() == STATUS::HIGH ? 1 : 0);
		}
		//If result 1 (true) output (LOW) , result 0 (false) output (HIGH).
		m_OutputPin.setStatus(result ? STATUS::LOW : STATUS::HIGH);
	}
}


// Function Draw
// Draws NOR3 gate
void NOR3::Draw(Output* pOut)
{
	//Call output class and pass gate drawing info to it.
	pOut->DrawNOR3(m_GfxInfo, getSelected());
}

//returns status of outputpin
int NOR3::GetOutPinStatus()
{
	return m_OutputPin.getStatus();
}


//returns status of Inputpin #n
int NOR3::GetInputPinStatus(int n)
{
	return m_InputPins[n - 1].getStatus();	//n starts from 1 but array index starts from 0.
}

//Set status of an input pin ot HIGH or LOW
void NOR3::setInputPinStatus(int n, STATUS s)
{
	m_InputPins[n - 1].setStatus(s);
}

//returns on. of input pins.
int NOR3::GetInputPinsNum()
{
	return 3;
}

int NOR3::Getm_Conn()
{
	return m_OutputPin.Getm_Conn();
}

CompType NOR3::GetCompType()
{
	return CompType(Comp_NOR3);
}
OutputPin* NOR3::getSourcePin()
{
	return &m_OutputPin;
}

InputPin* NOR3::getDestPin(int n)
{
	return &m_InputPins[n];
}

void NOR3::SaveComp(ofstream& SaveFile)
{
	GraphicsInfo GInfo = GetGraphicsInfo(); //Converting rectangular coordinates to center point
	int Cx = GInfo.x1 + (UI.AND2_Width / 2);
	int Cy = GInfo.y1 + (UI.AND2_Height / 2);
	//Format output
	SaveFile << left << setw(8) << "NOR3" << setw(5) << Id << setw(12) << GetLabel() << setw(5) << Cx << Cy << '\n';
}

void NOR3::LoadComp(ifstream& LoadFile)
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

