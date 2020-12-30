#ifndef _SELECT_H
#define _SELECT_H
#include "Actions/Action.h"
#include "ApplicationManager.h"
class Select : public Action
{
	int x, y;// clicked point
	int Index;
	Component* CompSelected;
public:
	Select(ApplicationManager* pMang);
	virtual ~Select(void);
	virtual void ReadActionParameters(void);
	virtual void Execute();
	virtual void Undo();
	virtual void Redo();
};
#endif

