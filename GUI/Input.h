#pragma once

#include "..\CMUgraphicsLib\CMUgraphics.h"
#include "UI_Info.h"

class Output;
class Input		//The application manager should have a pointer to this class
{
private:
	window* pWind;	//Pointer to the Graphics Window
	int px;
	int py; // el private data members fi el input.h
public:
	Input(window*);
	void GetPointClicked(int &, int &);	//Get coordinate where user clicks
	string GetSrting(Output*);		//Returns a string entered by the user
	ActionType GetUserAction() ; //Reads the user click and maps it to an action
	void ReturnPointClicked(int& x, int& y);
	buttonstate GetButtonState(const button btMouse, int& iX, int& iY);
	void GetCurrentClick(int&, int&);
	~Input();
};
