#ifndef _DELETE_H
#define _DELETE_H
#include "Actions/Action.h"
#include "Components/Component.h"
#include "Select.h"

class Delete : public Action
{
	int x, y; // Clicked point
	int Index; // Index of Component to be deleted in CompList
public:
	Delete(ApplicationManager* pMang);
	virtual ~Delete(void);
	virtual void ReadActionParameters();
	virtual void Execute();
	virtual void Undo();
	virtual void Redo();
};
#endif
