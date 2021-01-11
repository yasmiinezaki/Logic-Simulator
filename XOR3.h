#pragma once
#include"Components/Gate.h"
#include <fstream>
#include"ApplicationManager.h"

class XOR3 :public Gate
{
public:
	XOR3(int r_FanOut); //Overloaded constructor for the load action
	XOR3(const GraphicsInfo& r_GfxInfo, int r_FanOut, int Id, string Label);
	virtual void Operate();	//Calculates the output of the 3-input XOR gate
	virtual void Draw(Output* pOut);	//Draws XOR3 gate

	virtual int GetOutPinStatus();	//returns status of outputpin if LED, return -1
	virtual int GetInputPinStatus(int n);	//returns status of Inputpin # n if SWITCH, return -1

	virtual void setInputPinStatus(int n, STATUS s);	//set status of Inputpin # n, to be used by connection class.

	virtual int GetInputPinsNum();   //returns no. input pins.
	virtual int Getm_Conn();
	virtual CompType GetCompType();
	virtual OutputPin* getSourcePin();
	virtual InputPin* getDestPin(int n);
	virtual void SaveComp(ofstream& SaveFile);
	virtual void LoadComp(ifstream& LoadFile); //takes the file stream and reads its parameters
};


