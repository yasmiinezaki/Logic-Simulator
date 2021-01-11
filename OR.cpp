#include "OR.h"
#include <iomanip>  

OR::OR(int r_FanOut) :Gate(2, r_FanOut)
{
}

OR::OR(const GraphicsInfo& r_GfxInfo, int r_FanOut, int Id, string Label) : Gate(2, r_FanOut)
{
	m_GfxInfo.x1 = r_GfxInfo.x1;
	m_GfxInfo.y1 = r_GfxInfo.y1;
	m_GfxInfo.x2 = r_GfxInfo.x2;
	m_GfxInfo.y2 = r_GfxInfo.y2;
	this->Id = Id;
	SetLabel(Label);
	setSelected(false);
}


void OR::Operate()
{
	//caclulate the output status 

	//Add you code here

	// OR gate return 0 only when both input are 0 , otherwise it return 1. 
	/*So here I consider result be 0 (false) as if it ored with 0 will give 0 (LOW),
	ored with 1 will give 1 (HIGH) , it do the same operation of or(||) operation .*/
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
		//If result 1 (true) output HIGH , result 0 (false) output LOW.
		m_OutputPin.setStatus(result ? STATUS::HIGH : STATUS::LOW);
	}
}


// Function Draw
// Draws OR gate
void OR::Draw(Output* pOut)
{
	//Call output class and pass gate drawing info to it.
	pOut->DrawOR(m_GfxInfo, getSelected());
}

//returns status of outputpin
int OR::GetOutPinStatus()
{
	return m_OutputPin.getStatus();
}


//returns status of Inputpin #n
int OR::GetInputPinStatus(int n)
{
	return m_InputPins[n - 1].getStatus();	//n starts from 1 but array index starts from 0.
}

//Set status of an input pin ot HIGH or LOW
void OR::setInputPinStatus(int n, STATUS s)
{
	m_InputPins[n - 1].setStatus(s);
}

//returns no. of input pins.
int OR::GetInputPinsNum()
{
	return 2;
}

int OR::Getm_Conn()
{
	return m_OutputPin.Getm_Conn();
}

CompType OR::GetCompType()
{
	return Comp_OR2;
}
OutputPin* OR::getSourcePin()
{
	return &m_OutputPin;
}

InputPin* OR::getDestPin(int n)
{
	return &m_InputPins[n];
}

void OR::SaveComp(ofstream& SaveFile)
{
	GraphicsInfo GInfo = GetGraphicsInfo(); //Converting rectangular coordinates to center point
	int Cx = GInfo.x1 + (UI.AND2_Width / 2);
	int Cy = GInfo.y1 + (UI.AND2_Height / 2);
	//Format output
	SaveFile << left << setw(8) << "OR2" << setw(5) << Id << setw(12) << GetLabel() << setw(5) << Cx << Cy << '\n';
}

void OR::LoadComp(ifstream& LoadFile)
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

