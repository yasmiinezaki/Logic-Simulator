#include "Input.h"
#include "Output.h"

Input::Input(window* pW)
{
	pWind = pW; //point to the passed window
}

void Input::GetPointClicked(int &x, int &y)
{
	pWind->FlushMouseQueue(); //removes any waiting mouse click action from the buffer
	pWind->WaitMouseClick(x, y);	//Wait for mouse click
}

string Input::GetSrting(Output *pOut)
{
	pWind->FlushKeyQueue();  // removes any waiting key action from the buffer
	const int MAX = 50; // maximum number of characters
	int c = 0;
	char keys[MAX];
	for (int i = 0; i < MAX;i++)
	{
		keys[i] = '\0';
	}
	char key; 
	pWind->WaitKeyPress(key); // take key press from the user
	while (key != 13) //Code of Enter key
	{
		if (key == 27) // Code of Escape key
		{
			return "";
		}
		if (key == 8) // Code of Backspace key
		{
			if (c != 0)
			{
				keys[c - 1] = '\0';
				c--;
			}
		}
		else
		{
			keys[c] = key; // Adding the entered character into the char array
			c++;
		}
		pOut->PrintMsg(keys);
		pWind->WaitKeyPress(key);
	}

	return keys;
	///TODO: Implement this Function
	//Read a complete string from the user until the user presses "ENTER".
	//If the user presses "ESCAPE". This function should return an empty string.
	//"BACKSPACE" should be also supported
	//User should see what he is typing at the status bar

}

//This function reads the position where the user clicks to determine the desired action
ActionType Input::GetUserAction()
{
	int x, y;
	pWind->FlushMouseQueue(); //removes any waiting mouse click action from the buffer
	pWind->WaitMouseClick(x, y);	//Get the coordinates of the user click
	px = x;
	py = y;

	if (UI.GateMenuNo == GATE_MODE1) //First gates bar
	{
		if (y >= UI.ToolBarHeight && y < (UI.ToolBarHeight) * 2)
		{
			int ClickedItemOrder = (x / UI.ToolItemWidth);
			switch (ClickedItemOrder)
			{
			case ITM_AND2: return ADD_AND_GATE_2;
			case ITM_OR2: return ADD_OR_GATE_2;
			case ITM_NAND2: return ADD_NAND_GATE_2;
			case ITM_NOR2: return ADD_NOR_GATE_2;
			case ITM_XOR2: return ADD_XOR_GATE_2;
			case ITM_XNOR2: return ADD_XNOR_GATE_2;
			case ITM_AND3: return ADD_AND_GATE_3;
			case ITM_XOR3: return ADD_XOR_GATE_3;
			case ITM_NOR3: return ADD_NOR_GATE_3;
			case ITM_BUFF: return ADD_Buff;
			case ITM_NEXT: return Gate_Menu2;
			}
		}
	}
	if (UI.GateMenuNo == GATE_MODE2) //Second gates bar
	{
		if (y >= UI.ToolBarHeight && y < (UI.ToolBarHeight) * 2)
		{
			int ClickedItemOrder = (x / UI.ToolItemWidth);
			switch (ClickedItemOrder)
			{
			case ITM_PREVIOUS: return Gate_Menu1;
			case ITM_INV: return ADD_INV;
			case ITM_SWITCH: return ADD_Switch;
			case ITM_LED: return ADD_LED;
			case ITM_WIRE: return ADD_CONNECTION;

			default: return  GATE_TOOL;
			}
		}
	}

	if (UI.AppMode == DESIGN)	//application is in design mode
	{
		//[1] If user clicks on the Toolbar
		if (y >= 0 && y < UI.ToolBarHeight)
		{
			//Check whick Menu item was clicked
			//==> This assumes that menu items are lined up horizontally <==
			int ClickedItemOrder = (x / UI.ToolItemWidth);
			//Divide x coord of the point clicked by the menu item width (int division)
			//if division result is 0 ==> first item is clicked, if 1 ==> 2nd item and so on

			switch (ClickedItemOrder)
			{
			case ITM_ADD: return ADD_COMPONENT;
			case ITM_LABEL: return ADD_Label;
			case ITM_EDIT: return EDIT;
			case ITM_DELETE: return DEL;
			case ITM_SAVE: return SAVE;
			case ITM_LOAD: return LOAD;
			case ITM_MOVE: return MOVE;
			case ITM_CUT: return CUT;
			case ITM_COPY:return COPY;
			case ITM_PASTE:return PASTE;
			case ITM_SWITCH_TO_SIM:return SIM_MODE;
			case ITM_EXIT: return EXIT;

			default: return DSN_TOOL;	//A click on empty place in desgin toolbar
			}
		}

		//[2] User clicks on the drawing area
		if (y >= UI.ToolBarHeight && y < UI.height - UI.StatusBarHeight)
		{
			return SELECT;	//user want to select/unselect a component
		}

		//[3] User clicks on the status bar
		return STATUS_BAR;
	}
	else	//Application is in Simulation mode
	{
		//Simulation tool bar
		if (y >= 0 && y < UI.ToolBarHeight)
		{
			//Check whick Menu item was clicked
			//==> This assumes that menu items are lined up horizontally <==
			int ClickedItemOrder = (x / UI.ToolItemWidth);
			//Divide x coord of the point clicked by the menu item width (int division)
			//if division result is 0 ==> first item is clicked, if 1 ==> 2nd item and so on

			switch (ClickedItemOrder)
			{
			//case ITM_ChangeSwitch: return Change_Switch;
			case ITM_TRUTH: return Create_TruthTable;
			case ITM_PROBE: return PROBE;
			case ITM_SWITCH_TO_DSN: return DSN_MODE;
			default: return SIM_TOOL; //empty space in simulation tool bar
			}
		}
		if (y >= UI.ToolBarHeight && y < UI.height - UI.StatusBarHeight) // drawing area
		{
			return SELECT;	//user wants to change the switch status
		}
		return STATUS_BAR;
		//return SIM_MODE;	//This should be changed after creating the compelete simulation bar 
	}

}

void Input::ReturnPointClicked(int& x, int& y)
{
	x = px;
	y = py;
}


Input::~Input()
{
}

buttonstate Input::GetButtonState(const button btMouse, int& iX, int& iY)
{
	return pWind->GetButtonState(btMouse, iX, iY);
}
void Input::GetCurrentClick(int& x, int& y)
{
	pWind->GetMouseClick(x, y);
}
