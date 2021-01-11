#pragma once
#include "component.h"
#include "InputPin.h"
#include "OutputPin.h"
#include "../ApplicationManager.h"
#include <fstream>
#include <string>
class InputPin;

class Connection :	public Component
{
	Component*	SrcCmpnt;	//Connection source component
	Component*	DstCmpnt;	//Connection Destination component
	int	IndexDstPin;		//The Input pin to which this connection is linked
	OutputPin* SrcPin;	//The Source pin of this connection (an output pin of certain Component)
	InputPin* DstPin;	//The Destination pin of this connection (an input pin of certain Component)
	ApplicationManager* pManager;
	bool Status;
public:
	Connection(const GraphicsInfo& r_GfxInfo, ApplicationManager* pApp);
	Connection(const GraphicsInfo& r_GfxInfo, OutputPin* pSrcPin, InputPin* pDstPin, int Pin);

	virtual void Operate() ;	//Calculates the output according to the inputs
	virtual void Draw(Output* pOut);	//for each component to Draw itself

	
	void setSourcePin(OutputPin *pSrcPin);
	void setDestPin(InputPin* pDstPin, int c);
	OutputPin* getSourcePin();
	InputPin* getDestPin();
	//Component* getSrcCmpnt();
   //Component* getDstCmpnt();


	virtual int GetOutPinStatus();	//returns status of outputpin if LED, return -1
	virtual int GetInputPinStatus(int n);	//returns status of Inputpin # n if SWITCH, return -1

	virtual void setInputPinStatus(int n, STATUS s);	//set status of Inputpin # n, to be used by connection class.
	virtual CompType GetCompType();
	virtual void SaveComp(ofstream& SaveFile);
	virtual void LoadComp(ifstream& LoadFile); //takes the file stream and reads its parameters
	virtual bool NotAssignedInput();
	bool getProbResult();
	void SetSrcComp(Component* SrcComp);
	bool Found(int x, int y);

};
