#pragma once
#include "../Project Code Framework/Components/Connection.h"
#include "Actions/Action.h"
#include"Components/Component.h"

class AddConnection : public Action
{
private:
	Connection* rconnection;
	int indDstPin;	//an index for destination pin
	int x1, y1, x2, y2; //coordinates needed to draw the connection
	GraphicsInfo CGInfo;
	OutputPin* SrcPin; //pointer to source pin
	InputPin* DstPin; //pointer to destination pin
	//window* pWind;
public:
	AddConnection(ApplicationManager* pApp);
	virtual ~AddConnection(void);

	//Reads parameters required for action to execute
	virtual void ReadActionParameters();
	//Execute action (code depends on action type)
	virtual void Execute();
	bool DetectSrcValidity(); //a function that detects the validity of the source component
	bool DetectDstValidity(); //a function that detects the validity of the destination component
	virtual void Undo();
	virtual void Redo();


};