#ifndef _LABEL_H
#define _LABEL_H
#include "Actions/Action.h"
#include "ApplicationManager.h"
class Label : public Action
{
	int x, y; // clicked point
	Component* CompLabeled;
	int Index;
public:
	Label(ApplicationManager* pMang);
	virtual ~Label(void);
	virtual void ReadActionParameters();
	virtual void Execute();
	virtual void Undo();
	virtual void Redo();
};
#endif