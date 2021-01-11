#pragma once
#include"Components/Gate.h"
#include "ApplicationManager.h"
#include <fstream>
#include <string>

class SWITCH :public Gate
{
public:
	SWITCH(int r_FanOut); //Overloaded constructor for the load action
	SWITCH(const GraphicsInfo& r_GfxInfo, int r_FanOut, int Id, string Label);
	virtual void Operate();	//Calculates the output of the SWITCH
	virtual void Draw(Output* pOut);	//Draws SWITCH gate

	virtual int GetOutPinStatus();	//returns status of outputpin if LED, return -1
	virtual int GetInputPinStatus(int n);	//returns status of Inputpin # n if SWITCH, return -1

	virtual void setInputPinStatus(int n, STATUS s);	//set status of Inputpin # n, to be used by connection class.

////////////////////////////////////////////////////////////////////
	virtual CompType GetCompType();
	virtual OutputPin* getSourcePin();
	virtual InputPin* getDestPin(int n);
	virtual void SaveComp(ofstream& SaveFile);
	virtual void LoadComp(ifstream& LoadFile); //takes the file stream and reads its parameters
	int GetInputPinsNum();
	int Getm_Conn();
	virtual bool NotAssignedInput();
};


