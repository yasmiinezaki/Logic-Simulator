#include "Actions/Action.h"
#include "ApplicationManager.h"

bool Action::CheckIsValid(int X, int Y)
{
	int len = UI.height;
	if (Y< (len - UI.StatusBarHeight - UI.AND2_Height) && Y>(UI.ToolBarHeight * 2 + UI.AND2_Height))
	{
		return true;
	}
	return false;
}