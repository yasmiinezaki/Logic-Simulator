#ifndef _AND2_H
#define _AND2_H

/*
  Class AND2
  -----------
  represent the 2-input AND gate
*/

#include "Gate.h"
#include <fstream>
#include <string>

class AND2:public Gate
{
public:
	AND2(int r_FanOut); //Overloaded constructor for the load action
	AND2(const GraphicsInfo& r_GfxInfo, int r_FanOut, int Id, string Label);
	virtual void Operate();	//Calculates the output of the AND gate
	virtual void Draw(Output* pOut);	//Draws 2-input gate

	virtual int GetOutPinStatus();	//returns status of outputpin if LED, return -1
	virtual int GetInputPinStatus(int n);	//returns status of Inputpin # n if SWITCH, return -1

	virtual void setInputPinStatus(int n, STATUS s);	//set status of Inputpin # n, to be used by connection class.

	virtual int GetInputPinsNum();  //returns no. of input pins.
	int Getm_Conn();
	virtual CompType GetCompType();
	virtual OutputPin* getSourcePin();
	virtual InputPin* getDestPin(int n);
	virtual void SaveComp(ofstream& SaveFile); //take the file stream and write its data
	virtual void LoadComp(ifstream& LoadFile); //takes the file stream and reads its parameters

};

#endif