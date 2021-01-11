#pragma once
#include"Actions/Action.h"
#include"ApplicationManager.h"
#include"Components/Connection.h"

class Probing :public Action
{
	int x, y;
	Component* CompSelected;
public:
	Probing(ApplicationManager* pMang);
	virtual ~Probing(void);
	virtual void ReadActionParameters(void);
	virtual void Execute();
	virtual void Undo();
	virtual void Redo();
};

