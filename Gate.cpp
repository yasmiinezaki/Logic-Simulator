#include "Gate.h"

//Gate Constructor
//Parameters:
//r_Inputs: no. of gate's input pins
//r_FanOut: Fan out of the gate's output pin
Gate::Gate(int r_Inputs, int r_FanOut):m_OutputPin(r_FanOut)
{
	//Allocate number of input pins (equals r_Inputs)
	m_InputPins = new InputPin[r_Inputs];
	m_Inputs = r_Inputs;	//set no. of inputs of that gate
	
	//Associate all input pins to this gate
	for(int i=0; i<m_Inputs; i++)
		m_InputPins[i].setComponent(this);
}


///////////////////////////////////////
int Gate::GetId()
{
	return Id;
}


void Gate::GetInputPinCoordinates(int& x, int& y, int index)
{
	x = m_GfxInfo.x1;
	switch (m_Inputs)
	{
	case 1:
		y = m_GfxInfo.y1 + ((m_GfxInfo.y2 - m_GfxInfo.y1) / 2);
		break;
	case 2:
		y = m_GfxInfo.y1 + UI.PinOffSet + (UI.PinOffSet * index * 2);
		break;
	case 3:
		y = m_GfxInfo.y1 + UI.PinOffSet + (UI.PinOffSet * index);
		break;
	default:
		break;
	}
}

void Gate::GetOutputPinCoordinates(int& x, int& y)
{
	x = m_GfxInfo.x2;
	y = m_GfxInfo.y1 + (m_GfxInfo.y2 - m_GfxInfo.y1) / 2;
}

int Gate::GetIndex()
{
	for (int i = 0; i < m_Inputs; i++)
	{
		bool b;
		b = m_InputPins[i].getIsConnected();
		if (b == false)
		{
			m_InputPins[i].setIsConnected(!b);
			return i;
		}
	}
	return -1;
}

bool Gate::Found(int x, int y)
{
	if (x >= m_GfxInfo.x1 && x <= m_GfxInfo.x2 && y >= m_GfxInfo.y1 && y <= m_GfxInfo.y2) //see if it matches the coordinaates
	{
		return true;
	}
	return false;
}

void Gate::getSourcePinPointer(OutputPin*& pOutPin)
{
	if (&m_OutputPin)
	{
		pOutPin = &m_OutputPin;
	}
}
void Gate::getDestPinPointer(InputPin*& pInPin, int n)
{
	pInPin = &m_InputPins[n];
}

int Gate::get_m_Inputs()
{
	return m_Inputs;
}

bool Gate::NotAssignedInput()
{
	for (int i = 0; i < m_Inputs; i++)
	{
		if (m_InputPins->getStatus() == STATUS::NotAssigned)
		{
			return true;
		}
	}
	return false;
}
