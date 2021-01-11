#include "AND3.h"
#include <iomanip>  

AND3::AND3(int r_FanOut) :Gate(3, r_FanOut)
{
}

AND3::AND3(const GraphicsInfo& r_GfxInfo, int r_FanOut, int Id, string Label) : Gate(3, r_FanOut)
{
	m_GfxInfo.x1 = r_GfxInfo.x1;
	m_GfxInfo.y1 = r_GfxInfo.y1;
	m_GfxInfo.x2 = r_GfxInfo.x2;
	m_GfxInfo.y2 = r_GfxInfo.y2;
	this->Id = Id;
	SetLabel(Label);
	setSelected(false);
}



void AND3::Operate()
{
	//caclulate the output status 

	//Add you code here

    // The AND3 gate gives output 1 in one case only if all the input are 1 , it gives 0 otherwise.
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
// Draws 3-input AND gate
void AND3::Draw(Output* pOut)
{
	//Call output class and pass gate drawing info to it.
	pOut->DrawAND3(m_GfxInfo, getSelected());
}

//returns status of outputpin
int AND3::GetOutPinStatus()
{
	return m_OutputPin.getStatus();
}


//returns status of Inputpin #n
int AND3::GetInputPinStatus(int n)
{
	return m_InputPins[n - 1].getStatus();	//n starts from 1 but array index starts from 0.
}

//Set status of an input pin ot HIGH or LOW
void AND3::setInputPinStatus(int n, STATUS s)
{
	m_InputPins[n - 1].setStatus(s);
}

//returns no. of input pins .
int AND3::GetInputPinsNum()
{
	return 3;
}

int AND3::Getm_Conn()
{
	return m_OutputPin.Getm_Conn();
}

CompType AND3::GetCompType()
{
	return CompType(Comp_AND3);
}
OutputPin* AND3::getSourcePin()
{
	return &m_OutputPin;
}

InputPin* AND3::getDestPin(int n)
{
	return &m_InputPins[n];
}

void AND3::SaveComp(ofstream& SaveFile)
{
	GraphicsInfo GInfo = GetGraphicsInfo(); //Converting rectangular coordinates to center point
	int Cx = GInfo.x1 + (UI.AND2_Width / 2);
	int Cy = GInfo.y1 + (UI.AND2_Height / 2);
	//Format output
	SaveFile << left << setw(8) << "AND3" << setw(5) << Id << setw(12) << GetLabel() << setw(5) << Cx << Cy << '\n';
}

void AND3::LoadComp(ifstream& LoadFile)
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

