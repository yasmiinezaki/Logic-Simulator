#pragma once
#include"Components/Gate.h"
#include <fstream>
#include <string>
#include"ApplicationManager.h"

class BUFFER :public Gate
{
public:
	BUFFER(int r_FanOut); //Overloaded constructor for the load action
	BUFFER(const GraphicsInfo& r_GfxInfo, int r_FanOut, int Id, string Label);
	virtual void Operate();	//Calculates the output of the BUFFER gate
	virtual void Draw(Output* pOut);	//Draws BUFFER gate

	virtual int GetOutPinStatus();	//returns status of outputpin if LED, return -1
	virtual int GetInputPinStatus(int n);	//returns status of Inputpin # n if SWITCH, return -1

	virtual void setInputPinStatus(int n, STATUS s);	//set status of Inputpin # n, to be used by connection class.

	int GetInputPinsNum();   //returns no. of input pins. 
	int Getm_Conn();
	virtual CompType GetCompType();
	virtual OutputPin* getSourcePin();
	virtual InputPin* getDestPin(int n);
	virtual void SaveComp(ofstream& SaveFile);
	virtual void LoadComp(ifstream& LoadFile); //takes the file stream and reads its parameters
};

