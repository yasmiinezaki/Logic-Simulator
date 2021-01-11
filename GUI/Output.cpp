#include "Output.h"

Output::Output()
{
	//Initialize user interface parameters

	UI.AppMode = DESIGN;	//Design Mode is the startup mode
	UI.GateMenuNo = NO_GATE_MENU;
	//Initilaize interface colors
	UI.DrawColor = BLACK;
	UI.SelectColor = RED;
	UI.ConnColor = BLACK;
	UI.MsgColor = BLUE;
	UI.BkGrndColor = WHITE;
	UI.LabelColor = DARKVIOLET;
	UI.HighVoltColor = GREEN;

	//Create the drawing window
	pWind = CreateWind(UI.width, UI.height, UI.wx, UI.wy);	
	ChangeTitle("Programming Techniques Project");

	CreateDesignToolBar();	//Create the desgin toolbar
	CreateStatusBar();		//Create Status bar

}

Input* Output::CreateInput() const
{
	//Create an Input Object & assign it to the Same Window
	Input* pIn = new Input(pWind);
	return pIn;
}


//======================================================================================//
//								Interface Functions										//
//======================================================================================//

window* Output::CreateWind(int wd, int h, int x, int y) const
{
	return new window(wd, h, x, y);
}
//////////////////////////////////////////////////////////////////////////////////
void Output::ChangeTitle(string Title) const
{
	pWind->ChangeTitle(Title);
}
//////////////////////////////////////////////////////////////////////////////////
void Output::CreateStatusBar() const
{
	pWind->SetPen(RED,3);
	pWind->DrawLine(0, UI.height-UI.StatusBarHeight, UI.width, UI.height-UI.StatusBarHeight);
}
//////////////////////////////////////////////////////////////////////////////////
void Output::PrintMsg(string msg) const
{
	ClearStatusBar();	//Clear Status bar to print message on it
	// Set the Message offset from the Status Bar
	int MsgX = 25;
	int MsgY = UI.StatusBarHeight - 10;

	// Print the Message
    pWind->SetFont(20, BOLD | ITALICIZED, BY_NAME, "Arial"); 
	pWind->SetPen(UI.MsgColor); 
	pWind->DrawString(MsgX, UI.height - MsgY, msg);
}
//////////////////////////////////////////////////////////////////////////////////
void Output::ClearStatusBar()const
{
	// Set the Message offset from the Status Bar
	int MsgX = 25;
	int MsgY = UI.StatusBarHeight - 10;

	//Overwrite using bachground color to erase the message
	pWind->SetPen(UI.BkGrndColor);
	pWind->SetBrush(UI.BkGrndColor);
	pWind->DrawRectangle(MsgX, UI.height - MsgY, UI.width, UI.height);
}
//////////////////////////////////////////////////////////////////////////////////////////

//Clears the drawing (degin) area
void Output::ClearDrawingArea() const
{
	pWind->SetPen(WHITE, 1);
	pWind->SetBrush(WHITE);
	pWind->DrawRectangle(0, UI.ToolBarHeight*2, UI.width, UI.height - UI.StatusBarHeight);
	
}

///// clear simulation toolbar
void Output::ClearSimulationBar() const
{
	pWind->SetPen(WHITE, 1);
	pWind->SetBrush(WHITE);
	pWind->DrawRectangle(0, 0,UI.width, UI.ToolBarHeight*2);
}

////// clear gates bar
void Output::ClearGateBar() const
{
	pWind->SetPen(WHITE, 1);
	pWind->SetBrush(WHITE);
	pWind->DrawRectangle(0, UI.ToolBarHeight, UI.width -(UI.ToolItemWidth+UI.ToolItemWidth/2), 2 * UI.ToolBarHeight);
}

//////////////////////////////////////////////////////////////////////////////////////////
//Draws the menu (toolbar) in the Design mode
void Output::CreateDesignToolBar() const
{
	UI.AppMode = DESIGN;	//Design Mode

	//You can draw the tool bar icons in any way you want.

	//First prepare List of images for each menu item
	string MenuItemImages[ITM_DSN_CNT];
	MenuItemImages[ITM_ADD] = "images\\Menu\\add.jpg";
	MenuItemImages[ITM_LABEL] = "images\\Menu\\label.jpg";
	MenuItemImages[ITM_EDIT] = "images\\Menu\\edit.jpg";
	MenuItemImages[ITM_DELETE] = "images\\Menu\\delete.jpg";
	MenuItemImages[ITM_SAVE] = "images\\Menu\\save.jpg";
	MenuItemImages[ITM_LOAD] = "images\\Menu\\load.jpg";
	MenuItemImages[ITM_MOVE] = "images\\Menu\\move.jpg";
	MenuItemImages[ITM_CUT] = "images\\Menu\\cut.jpg";
	MenuItemImages[ITM_COPY] = "images\\Menu\\copy.jpg";
	MenuItemImages[ITM_PASTE] = "images\\Menu\\paste.jpg";

	MenuItemImages[ITM_SWITCH_TO_SIM] = "images\\Menu\\play.jpg";

	MenuItemImages[ITM_EXIT] = "images\\Menu\\exit.jpg";

	//TODO: Prepare image for each menu item and add it to the list

	//Draw menu item one image at a time
	for(int i=0; i<ITM_DSN_CNT; i++)
		pWind->DrawImage(MenuItemImages[i],i*UI.ToolItemWidth,0,UI.ToolItemWidth, UI.ToolBarHeight);


	//Draw a line under the toolbar
	pWind->SetPen(RED,3);
	pWind->DrawLine(0, UI.ToolBarHeight, UI.ToolItemWidth*12, UI.ToolBarHeight);


}
//////////////////////////////////////////////////////////////////////////////////////////
//Draws the menu (toolbar) in the simulation mode
void Output::CreateSimulationToolBar() const
{
	UI.AppMode = SIMULATION;	//Simulation Mode

	string MenuItemImages[ITM_SIM_CNT];
	//MenuItemImages[ITM_ChangeSwitch] = "images\\Menu\\simulate.jpg";
	MenuItemImages[ITM_PROBE] = "images\\Menu\\probing.jpg";
	MenuItemImages[ITM_TRUTH] = "images\\Menu\\truth.jpg";

	MenuItemImages[ITM_SWITCH_TO_DSN] = "images\\Menu\\pause.jpg";


	for (int i = 0; i < ITM_SIM_CNT; i++)
		pWind->DrawImage(MenuItemImages[i], i * UI.ToolItemWidth, 0, UI.ToolItemWidth, UI.ToolBarHeight);

	pWind->SetPen(RED, 3);
	pWind->DrawLine(0, UI.ToolBarHeight, UI.ToolItemWidth*3, UI.ToolBarHeight);


	//TODO: Write code to draw the simualtion toolbar (similar to that of design toolbar drawing)


}

void Output::CreateGate1ToolBar() const
{
	UI.GateMenuNo = GATE_MODE1;
	//UI.AppMode = GATES;
	string MenuItemImages[ITM_GATES1_CNT];
	MenuItemImages[ITM_AND2] = "images\\Menu\\and2.jpg";
	MenuItemImages[ITM_OR2] = "images\\Menu\\or.jpg";
	MenuItemImages[ITM_NAND2] = "images\\Menu\\nand.jpg";
	MenuItemImages[ITM_NOR2] = "images\\Menu\\nor.jpg";
	MenuItemImages[ITM_XOR2] = "images\\Menu\\xor2.jpg";
	MenuItemImages[ITM_XNOR2] = "images\\Menu\\xnor.jpg";
	MenuItemImages[ITM_AND3] = "images\\Menu\\and3.jpg";
	MenuItemImages[ITM_XOR3] = "images\\Menu\\xor3.jpg";
	MenuItemImages[ITM_NOR3] = "images\\Menu\\nor3.jpg";
	MenuItemImages[ITM_BUFF] = "images\\Menu\\buffer.jpg";
	MenuItemImages[ITM_NEXT] = "images\\Menu\\dots1.jpg";


	for (int i = 0; i < ITM_GATES1_CNT; i++)
		pWind->DrawImage(MenuItemImages[i], i * UI.ToolItemWidth, UI.ToolItemWidth, UI.ToolItemWidth, UI.ToolBarHeight);

	pWind->SetPen(RED, 3);
	pWind->DrawLine(0, 2 * UI.ToolBarHeight, UI.width - (UI.ToolItemWidth+UI.ToolItemWidth/2), 2 * UI.ToolBarHeight);


}

void Output::CreateGate2ToolBar() const
{
	ClearGateBar();
	UI.GateMenuNo = GATE_MODE2;
	//UI.AppMode = GATES;
	string MenuItemImages[ITM_GATES2_CNT];
	MenuItemImages[ITM_PREVIOUS] = "images\\Menu\\dots.jpg";
	MenuItemImages[ITM_INV] = "images\\Menu\\inverter.jpg";
	MenuItemImages[ITM_SWITCH] = "images\\Menu\\switch.jpg";
	MenuItemImages[ITM_LED] = "images\\Menu\\bulb.jpg";
	MenuItemImages[ITM_WIRE] = "images\\Menu\\wire.jpg";

	for (int i = 0; i < ITM_GATES2_CNT; i++)
		pWind->DrawImage(MenuItemImages[i], i * UI.ToolItemWidth, UI.ToolItemWidth, UI.ToolItemWidth, UI.ToolBarHeight);

	pWind->SetPen(RED, 3);
	pWind->DrawLine(0, 2 * UI.ToolBarHeight, ITM_GATES2_CNT * UI.ToolItemWidth, 2 * UI.ToolBarHeight);
}

//======================================================================================//
//								Components Drawing Functions							//
//======================================================================================//

void Output::DrawAND2(GraphicsInfo r_GfxInfo, bool selected) const
{
	string GateImage;
	if(selected)	//use image in the highlighted case
		GateImage="Images\\Gates\\Gate_AND2_Hi.jpg";
	else  
		GateImage = "Images\\Gates\\Gate_AND2.jpg";

	//Draw AND2 Gate at Gfx_Info (1st corner)
	//Set the Image Width & Height by AND2 Image Parameter in UI_Info
	pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1, UI.AND2_Width, UI.AND2_Height);
}

void Output::DrawOR(GraphicsInfo r_GfxInfo, bool selected) const
{
	string GateImage;
	if (selected)
		GateImage = "Images\\Gates\\Gate_OR_Hi.jpg";
	else
		GateImage = "Images\\Gates\\Gate_OR.jpg";
	pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1, UI.BUFFER_Width, UI.BUFFER_Height);
}

void Output::DrawNOR3(GraphicsInfo r_GfxInfo, bool selected) const
{
	string GateImage;
	if (selected)
		GateImage = "Images\\Gates\\Gate_NOR3_Hi.jpg";
	else
		GateImage = "Images\\Gates\\Gate_NOR3.jpg";
	pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1, UI.BUFFER_Width, UI.BUFFER_Height);
}

void Output::DrawBUFFER(GraphicsInfo r_GfxInfo, bool selected) const
{
	string GateImage;
	if (selected)
		GateImage = "Images\\Gates\\BUFFER_Hi.jpg";
	else
		GateImage = "Images\\Gates\\BUFFER.jpg";
	pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1, UI.BUFFER_Width, UI.BUFFER_Height);
}
void Output::DrawAND3(GraphicsInfo r_GfxInfo, bool selected) const
{
	string GateImage;
	if (selected)
		GateImage = "Images\\Gates\\Gate_AND3_Hi.jpg";
	else
		GateImage = "Images\\Gates\\Gate_AND3.jpg";

	pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1, UI.AND3_Width, UI.AND3_Height);
}

void Output::DrawNAND(GraphicsInfo r_GfxInfo, bool selected) const
{
	string GateImage;
	if (selected)
		GateImage = "Images\\Gates\\Gate_NAND_Hi.jpg";
	else
		GateImage = "Images\\Gates\\Gate_NAND.jpg";

	pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1, UI.NAND_Width, UI.NAND_Height);
}
void Output::DrawNOR2(GraphicsInfo r_GfxInfo, bool selected) const
{
	string GateImage;
	if (selected)
		GateImage = "Images\\Gates\\Gate_NOR2_Hi.jpg";
	else
		GateImage = "Images\\Gates\\Gate_NOR2.jpg";

	pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1, UI.NOR2_Width, UI.NOR2_Height);
}

void Output::DrawXNOR(GraphicsInfo r_GfxInfo, bool selected) const
{
	string GateImage;
	if (selected)
		GateImage = "Images\\Gates\\Gate_XNOR_Hi.jpg";
	else
		GateImage = "Images\\Gates\\Gate_XNOR.jpg";

	pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1, UI.XNOR_Width, UI.XNOR_Height);
}
void Output::DrawXOR2(GraphicsInfo r_GfxInfo, bool selected) const
{
	string GateImage;
	if (selected)
		GateImage = "Images\\Gates\\Gate_XOR2_Hi.jpg";
	else
		GateImage = "Images\\Gates\\Gate_XOR2.jpg";

	pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1, UI.XOR2_Width, UI.XOR2_Height);
}
void Output::DrawXOR3(GraphicsInfo r_GfxInfo, bool selected) const
{
	string GateImage;
	if (selected)
		GateImage = "Images\\Gates\\Gate_XOR3_Hi.jpg";
	else
		GateImage = "Images\\Gates\\Gate_XOR3.jpg";

	pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1, UI.XOR3_Width, UI.XOR3_Height);
}
void Output::DrawINVERTER(GraphicsInfo r_GfxInfo, bool selected) const
{
	string GateImage;
	if (selected)
		GateImage = "Images\\Gates\\INVERTER_Hi.jpg";
	else
		GateImage = "Images\\Gates\\INVERTER.jpg";

	pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1, UI.INVERTER_Width, UI.INVERTER_Height);
}

void Output::DrawSWITCH(GraphicsInfo r_GfxInfo, bool selected, bool Opened) const
{
	string GateImage;
	if (selected && Opened) //use image in the highlighted case with the switch opened
	{
		GateImage = "Images\\Gates\\SWITCH_OPEN_Hi.jpg";
	}
	else if (selected && !Opened) //use image in highlighted case with switch closed
	{
		GateImage = "Images\\Gates\\SWITCH_CLOSE_Hi.jpg";
	}
	else if(!selected && Opened) // use image in normal case with switch opened
	{
		GateImage = "Images\\Gates\\SWITCH_OPEN.jpg";
	}
	else //use image in normal case with switch closed
	{
		GateImage = "Images\\Gates\\SWITCH_CLOSE.jpg";
	}

	pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1, UI.SWITCH_Width, UI.SWITCH_Height);
}

void Output::DrawBULB(GraphicsInfo r_GfxInfo, bool selected, bool ON) const
{
	string GateImage;
	if (selected && ON) //use image in the highlighted case with the bulb ON
	{
		GateImage = "Images\\Gates\\BULB_ON_Hi.jpg";
	}
	else if (selected && !ON) //use image in highlighted case with bulb OFF
	{
		GateImage = "Images\\Gates\\BULB_OFF_Hi.jpg";
	}
	else if (!selected && ON) // use image in normal case with bulb ON
	{
		GateImage = "Images\\Gates\\BULB_ON.jpg";
	}
	else //use image in normal case with bulb OFF
	{
		GateImage = "Images\\Gates\\BULB_OFF.jpg";
	}

	pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1, UI.BULB_Width, UI.BULB_Height);
}

//TODO: Add similar functions to draw all components


void Output::DrawConnection(GraphicsInfo r_GfxInfo, bool selected, STATUS s) const
{
	//Determining the pen's color used to draw the connection 
	color c;
	if (UI.AppMode == SIMULATION)
	{
		if (s == HIGH)
		{
			c = UI.HighVoltColor;
		}
		else if (selected)
		{
			c = UI.SelectColor;
		}
		else
		{
			c = UI.ConnColor;
		}
	}
	else
	{
		if (selected)
		{
			c = UI.SelectColor;
		}
		else
		{
			c = UI.ConnColor;
		}
	}
	pWind->SetPen(c, 2);
	if (r_GfxInfo.y1 != r_GfxInfo.y2 && r_GfxInfo.x1 != r_GfxInfo.x2)
	{
		pWind->DrawLine(r_GfxInfo.x1, r_GfxInfo.y1, r_GfxInfo.x1, r_GfxInfo.y2);
		pWind->DrawLine(r_GfxInfo.x1, r_GfxInfo.y2, r_GfxInfo.x2, r_GfxInfo.y2);
	}
	/*else if (r_GfxInfo.x1 != r_GfxInfo.x2)
	{
		pWind->DrawLine(r_GfxInfo.x1, r_GfxInfo.y1, r_GfxInfo.x1, r_GfxInfo.y1 + 50);
		pWind->DrawLine(r_GfxInfo.x1, r_GfxInfo.y1 + 50, r_GfxInfo.x2, r_GfxInfo.y1 + 50);
		pWind->DrawLine(r_GfxInfo.x2, r_GfxInfo.y1 + 50, r_GfxInfo.x2, r_GfxInfo.y2);
	}*/
	else
	{
		pWind->DrawLine(r_GfxInfo.x1, r_GfxInfo.y1, r_GfxInfo.x2, r_GfxInfo.y2);
	}
	//TODO: Add code to draw connection
}

void Output::PrintLabelInDrawingArea(string label, GraphicsInfo CmpInfo) const
{
	// Set the Message offset from the
	int LblX = CmpInfo.x1; //CMPX --> x of the selected component
	int LblY = CmpInfo.y1 - 15; // CMPY --> y of the selected component

	// Print the Message
	pWind->SetFont(15, BOLD | ITALICIZED, BY_NAME, "Arial");
	pWind->SetPen(UI.LabelColor);
	pWind->DrawString(LblX, LblY, label);
}

Output::~Output()
{
	delete pWind;
}
void Output::TestFunction(int x, int y, int r)
{
	pWind->DrawCircle(x, y, r);
}

void Output::Test(GraphicsInfo GInfo)
{
	pWind->SetPen(MIDNIGHTBLUE);
	pWind->SetBrush(MIDNIGHTBLUE);
	pWind->DrawRectangle(GInfo.x1 + 100, GInfo.y1 + 100, GInfo.x2 + 100, GInfo.y2 + 100);
}