#ifndef _GATE_H
#define _GATE_H

/*
  Class Gate
  -----------
  - Base class for all types of gates
  - Each gate has n inputs pins and one output pin
*/


#include "InputPin.h"
#include "OutputPin.h"
#include "Component.h"

class Gate :public Component
{
protected:
	InputPin* m_InputPins;	//Array of input pins of the Gate
	OutputPin m_OutputPin;	//The Gate output pin
	int m_Inputs;		//No. of input pins of that Gate.
	int Id;
public:
	Gate(int r_Inputs, int r_FanOut);

	virtual CompType GetCompType() = 0;

	virtual void GetInputPinCoordinates(int& x, int& y, int index);
	virtual void GetOutputPinCoordinates(int& x, int& y);
	virtual int GetIndex();//a function that return the index of first available input pin and if no pin is found -1 is returned

	virtual OutputPin* getSourcePin()=0;
	virtual InputPin* getDestPin(int n)=0;

	virtual void ResetSrcPinValidity();
	virtual void ResetDstPinValidity(int i);

	virtual void getSourcePinPointer(OutputPin* & pOutPin );
	virtual void getDestPinPointer(InputPin* & pInPin,int n);
	virtual int get_m_Inputs();
};

#endif
