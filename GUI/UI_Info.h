#ifndef UI_INFO_H
#define UI_INFO_H

#include "..\CMUgraphicsLib\CMUgraphics.h"
#include "..\Defs.h"

//User Interface information file.
//This file contains info that is needed by Input and Output classes to
//handle the user interface

__declspec(selectany) //This line to prevent "redefinition error"

struct UI_Info	//User Interface Info.
{
	MODE AppMode;		//Application Mode (design or simulation)
	GATESMENUMODE GateMenuNo;

	static const int	width = 1000, height = 750,	//Window width and height
		wx = 15, wy = 15,			//Window starting coordinates
		StatusBarHeight = 50,	//Status Bar Height
		ToolBarHeight = 80,		//Tool Bar Height (distance from top of window to bottom line of toolbar)
		ToolItemWidth = 80;  	//Width of each item in toolbar menu
	static const int PinOffSet = 10;  //distance between 2 successive pins




	color DrawColor;		//Drawing color
	color SelectColor;		//Highlighting color
	color ConnColor;		//Connector color
	color MsgColor;			//Messages color
	color BkGrndColor;		//Back ground color
	color LabelColor;
	color HighVoltColor;    //Connector color when connector's status = 1


	//This should be calculated accurately because it will be used later to create connections between gates
	//For now, we will assume that rect width = 50 and height = 50		
	static const int	AND2_Width = 80,	//AND2 Gate Image default width
		AND2_Height = 40,   //AND2 Gate Image default height
		BUFFER_Width = 80,
		BUFFER_Height = 40,
		AND3_Width = 80,
		AND3_Height = 40,
		NAND_Width = 80,
		NAND_Height = 40,
		NOR2_Width = 80,
		NOR2_Height = 40,
		NOR3_Width = 80,
		NOR3_Height = 40,
		OR_Width = 80,
		OR_Height = 40,
		XNOR_Width = 80,
		XNOR_Height = 40,
		XOR2_Width = 80,
		XOR2_Height = 40,
		XOR3_Width = 80,
		XOR3_Height = 40,
		INVERTER_Width = 80,
		INVERTER_Height = 40,
		SWITCH_Width = 80,
		SWITCH_Height = 40,
		BULB_Width = 80,
		BULB_Height = 40;
}UI;	//create a single global object UI

#endif