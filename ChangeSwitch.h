#ifndef _CHANGE_SWITCH_H
#define _CHANGE_SWITCH_H
#include "Actions/Action.h"
#include "ApplicationManager.h"
class ChangeSwitch : public Action
{
	int x, y;
	Component* CompSelected;
public:
	ChangeSwitch(ApplicationManager* pMang);
	virtual ~ChangeSwitch(void);
	virtual void ReadActionParameters(void);
	virtual void Execute();
	virtual void Undo();
	virtual void Redo();
};

#endif


