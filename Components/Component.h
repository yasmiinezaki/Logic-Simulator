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
	static int UniqueId;
	bool result;
public:
	Component(const GraphicsInfo &r_GfxInfo);
	virtual void Operate() = 0;	//Calculates the output according to the inputs
	virtual void Draw(Output* pOut) = 0;	//for each component to Draw itself
	
	
	virtual int GetOutPinStatus()=0;	//returns status of outputpin if LED, return -1
	virtual int GetInputPinStatus(int n)=0;	//returns status of Inputpin # n if SWITCH, return -1

	virtual void setInputPinStatus(int n, STATUS s)=0;	//set status of Inputpin # n, to be used by connection class.
	Component();	

	//return component type
	virtual CompType GetCompType() = 0;

	virtual bool getSelected();         // Checks if component is selected or not   
	virtual void setSelected(bool s);        // changes value of selected
	GraphicsInfo GetGraphicsInfo();
	virtual void SaveComp(ofstream& SaveFile) = 0;
	virtual void LoadComp(ifstream& LoadFile) = 0; //It takes the line of the file corresponding to the gate type
	string GetLabel();
	void SetLabel(string Label);
	bool getResult();
	void setResult(bool r);
	virtual bool NotAssignedInput()=0 ;
	virtual bool Found(int x, int y) = 0;// takes the coordinates of the point clicked and returns true if the click is within the are of the component
	//Destructor must be virtual
	virtual ~Component();
};
 
#endif
