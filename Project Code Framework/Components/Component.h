#ifndef _COMPONENT_H
#define _COMPONENT_H

#include "..\Defs.h"
#include "..\GUI\Output.h"

//Base class for classes Gate, Switch, and LED.
class Component
{
private:
	string m_Label;
	bool selected;
protected:
	GraphicsInfo m_GfxInfo;	//The parameters required to draw a component
public:
	Component(const GraphicsInfo &r_GfxInfo);
	virtual void Operate() = 0;	//Calculates the output according to the inputs
	virtual void Draw(Output* pOut) = 0;	//for each component to Draw itself selected or not
	virtual GraphicsInfo GetGraphicsInfo(); // Each component returns its dimensions
	virtual bool getSelected();         // Checks if component is selected or not   
	virtual void setSelected(bool s);  // changes value of selected
	virtual CompType GetCompType()=0;    // returns type of component
	//virtual void PrintLabel(Output* pOut)=0; //Prints label of component onto the drawing area
	virtual int GetOutPinStatus()=0;	//returns status of outputpin if LED, return -1
	virtual int GetInputPinStatus(int n)=0;	//returns status of Inputpin # n if SWITCH, return -1

	virtual void setInputPinStatus(int n, STATUS s)=0;	//set status of Inputpin # n, to be used by connection class.

	
	Component();	
	
	//Destructor must be virtual
	virtual ~Component();
};

#endif
