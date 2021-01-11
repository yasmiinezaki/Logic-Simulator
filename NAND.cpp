#include "NAND.h"
#include <iomanip>

NAND::NAND(int r_FanOut) :Gate(2, r_FanOut)
{
}

NAND::NAND(const GraphicsInfo& r_GfxInfo, int r_FanOut, int Id, string Label) : Gate(2, r_FanOut)
{
	m_GfxInfo.x1 = r_GfxInfo.x1;
	m_GfxInfo.y1 = r_GfxInfo.y1;
	m_GfxInfo.x2 = r_GfxInfo.x2;
	m_GfxInfo.y2 = r_GfxInfo.y2;
	this->Id = Id;
	SetLabel(Label);
	setSelected(false);
}


void NAND::Operate()
{
	//caclulate the output status 

	//Add you code here

	//NAND gate is reverse of AND gate , it returns 0 only when the both inputs are 1 , othewise it raturn 1.
	if (NotAssignedInput())
	{
		m_OutputPin.setStatus(STATUS::NOTAssigned);
	}
	else
	{
		bool result = 1;
		for (int i = 0; i < m_Inputs; i++)
		{
			result = result && (m_InputPins[i].getStatus() == STATUS::HIGH ? 1 : 0);
		}

		//If result 1 (true) output (LOW) , result 0 (false) output (HIGH).

		m_OutputPin.setStatus(result ? STATUS::LOW : STATUS::HIGH);
	}
}

// Function Draw
// Draws NAND gate
void NAND::Draw(Output* pOut)
{
	//Call output class and pass gate drawing info to it.
	pOut->DrawNAND(m_GfxInfo, getSelected());
}

//returns status of outputpin
int NAND::GetOutPinStatus()
{
	return m_OutputPin.getStatus();
}


//returns status of Inputpin #n
int NAND::GetInputPinStatus(int n)
{
	return m_InputPins[n - 1].getStatus();	//n starts from 1 but array index starts from 0.
}

//Set status of an input pin ot HIGH or LOW
void NAND::setInputPinStatus(int n, STATUS s)
{
	m_InputPins[n - 1].setStatus(s);
}

//returns no. of input pins.
int NAND::GetInputPinsNum()
{
	return 2;
}
int NAND::Getm_Conn()
{
	return m_OutputPin.Getm_Conn();
}

CompType NAND::GetCompType()
{
	return Comp_NAND2;
}
OutputPin* NAND::getSourcePin()
{
	return &m_OutputPin;
}

InputPin* NAND::getDestPin(int n)
{
	return &m_InputPins[n];
}

void NAND::SaveComp(ofstream& SaveFile)
{
	GraphicsInfo GInfo = GetGraphicsInfo(); //Converting rectangular coordinates to center point
	int Cx = GInfo.x1 + (UI.AND2_Width / 2);
	int Cy = GInfo.y1 + (UI.AND2_Height / 2);
	//Format output
	SaveFile << left << setw(8) << "NAND2" << setw(5) << Id << setw(12) << GetLabel() << setw(5) << Cx << Cy << '\n';
}

void NAND::LoadComp(ifstream& LoadFile)
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

