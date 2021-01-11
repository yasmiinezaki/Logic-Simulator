#ifndef _DELETE_H
#define _DELETE_H
#include "Actions/Action.h"
#include "Select.h"
#include"ApplicationManager.h"
#include"Components/Component.h"
#include"Components/Connection.h"
#include"Components/InputPin.h"
#include"Components/OutputPin.h"
#include"Components/Gate.h"

class Delete : public Action
{
	int x, y; // Clicked point
	Component* CompToDelete;
	int Index; //Index of selected Component
	//Select* pSelect;
public:
	Delete(ApplicationManager* pMang);
	virtual ~Delete(void);
	virtual void ReadActionParameters();
	virtual void Execute();
	virtual void Undo();
	virtual void Redo();
};
#endif


