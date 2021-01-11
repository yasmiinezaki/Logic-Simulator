#include "AND2.h"
#include <iomanip>

AND2::AND2(int r_FanOut) :Gate(2, r_FanOut)
{
}

AND2::AND2(const GraphicsInfo& r_GfxInfo, int r_FanOut, int Id, string Label) : Gate(2, r_FanOut)
{
	m_GfxInfo.x1 = r_GfxInfo.x1;
	m_GfxInfo.y1 = r_GfxInfo.y1;
	m_GfxInfo.x2 = r_GfxInfo.x2;
	m_GfxInfo.y2 = r_GfxInfo.y2;
	this->Id = Id;
	SetLabel(Label);
	setSelected(false);
}


void AND2::Operate()
{
	//caclulate the output status as the ANDing of the two input pins

	//Add you code here

	// The AND2 gate gives output 1 in one case only if both the input are 1 , it gives 0 otherwise.
	/*So here I consider result be 1 (true) as if it anded with 0 will give 0 (LOW),
	anded with 1 will give 1(HIGH), it do the same operation of and (&&) operation.*/
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

		//If result 1 (true) output HIGH , result 0 (false) output (LOW).

		m_OutputPin.setStatus(result ? STATUS::HIGH : STATUS::LOW);
	}
	//Another methode
	/*bool result = 1;
	for (int i = 0;i < m_Inputs;i++)
	{
		result = result * (m_InputPins[i].getStatus());
	}
	m_OutputPin.setStatus(result ? STATUS::HIGH : STATUS::LOW);*/
	
}


// Function Draw
// Draws 2-input AND gate
void AND2::Draw(Output* pOut)
{
	//Call output class and pass gate drawing info to it.
	pOut->DrawAND2(m_GfxInfo, getSelected());
}

//returns status of outputpin
int AND2::GetOutPinStatus()	
{
	return m_OutputPin.getStatus();
}


//returns status of Inputpin #n
int AND2::GetInputPinStatus(int n)	
{
	return m_InputPins[n-1].getStatus();	//n starts from 1 but array index starts from 0.
}

//Set status of an input pin ot HIGH or LOW
void AND2::setInputPinStatus(int n, STATUS s)
{
	m_InputPins[n-1].setStatus(s);
}

//returns no. of input pin .
int AND2::GetInputPinsNum()
{
	return 2;
}


int AND2::Getm_Conn()
{
	return m_OutputPin.Getm_Conn();
}

CompType AND2::GetCompType()
{
	return Comp_AND2;
}
OutputPin* AND2::getSourcePin()
{
	return &m_OutputPin;
}

InputPin* AND2::getDestPin(int n)
{
	return &m_InputPins[n];
}

void AND2::SaveComp(ofstream& SaveFile)
{
	GraphicsInfo GInfo = GetGraphicsInfo(); //Converting rectangular coordinates to center point
	int Cx = GInfo.x1 + (UI.AND2_Width / 2);
	int Cy = GInfo.y1 + (UI.AND2_Height / 2);
	//Format output
	SaveFile << left << setw(8) << "AND2" << setw(5) << Id << setw(12) << GetLabel() << setw(5) << Cx << Cy << '\n';
}


void AND2::LoadComp(ifstream& LoadFile)
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

