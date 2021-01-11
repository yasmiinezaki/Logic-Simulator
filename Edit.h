#pragma once
#include "Actions/Action.h"
#include "AddConnection.h"
#include "ApplicationManager.h"
#include "Components/Gate.h"
class Edit : public Action
{
	int x, y; // user click
	Component* CompToEdit;
	InputPin* pInputPin;
	OutputPin* pOutputPin;
	int Index;
public:
	Edit(ApplicationManager* pMang);
	virtual ~Edit(void);
	virtual void ReadActionParameters();
	virtual void Execute();
	void EditInputPin(); //takes the index of the input pin user wants to edit
	void EditOutputPin();
	virtual void Undo();
	virtual void Redo();
};

