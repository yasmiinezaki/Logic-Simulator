#include "GUI\Input.h"
#include "GUI\Output.h"

//This is a test code to test the Input and Output classes

int main()
{
	int x,y;

	//Create Input and Output objects to test
	Output *pOut = new Output();;
	Input *pIn = pOut->CreateInput();

	//Starting the test
	pOut->PrintMsg("This demo is to test input and output classes, Click anywhere to start the test");
	pIn->GetPointClicked(x,y);	//Wait for any click


	///////////////////////////////////////////////////////////////////////////////////
	// TEST 1:	Create The FULL Tool bar, the drawing area and the status bar	
	//			This has already been done through the constrcutor of class Output
	///////////////////////////////////////////////////////////////////////////////////

	pOut->PrintMsg("TEST1: Drawing Tool bar and Status bar, Click anywhere to continue");
	pIn->GetPointClicked(x,y);	//Wait for any click

	
	///////////////////////////////////////////////////////////////////////////////////
	// TEST 2:	Drawing all the Components with all possible states: Normal, highlighted
	//			
	///////////////////////////////////////////////////////////////////////////////////
	
	pOut->PrintMsg("TEST2: Now we will show that Output class can draw any Component in any state, Click anywhere to continue");
	pIn->GetPointClicked(x,y);	//Wait for any click

	GraphicsInfo GfxInfo, GfxInfo1, GfxInfo2;  //to be used with draw function of the class Ouput

	/// 2.1- AND2 Gate test
	pOut->PrintMsg("Drawing 2-input AND gate, Normal and Highlighted,  Click to continue");
	
	GfxInfo1.x1 = 100;	GfxInfo1.y1 = 100; // Normal gates
	GfxInfo2.x1 = 100;	GfxInfo2.y1 = 200; // highlighted gates

	//Drawing Normal AND2 gate
	pOut->DrawAND2(GfxInfo1);

	//Drawing Highlighted AND2 gate
	pOut->DrawAND2(GfxInfo2, true);

	pIn->GetPointClicked(x,y);	//Wait for any click
	pOut->ClearDrawingArea();

	/// 2.2- NAND2 Gate test
	pOut->PrintMsg("Drawing 2-input NAND gate, Normal and Highlighted,  Click to continue");
	// Normal NAND
	pOut->DrawNAND(GfxInfo1);
	// Highlighted NAND
	pOut->DrawNAND(GfxInfo2, true);

	///TODO: Add code to draw 2-input NAND gate, Normal and Highlighted

	pIn->GetPointClicked(x,y);	//Wait for any click
	pOut->ClearDrawingArea();

	/// 2.3- OR2 and NOR2 Gates test
	pOut->PrintMsg("Drawing 2-input OR and NOR gates, Normal and Highlighted,  Click to continue");
	// Normal OR
	pOut->DrawOR(GfxInfo1);
	// Highlighted OR
	pOut->DrawOR(GfxInfo2, true);

	pIn->GetPointClicked(x, y);	//Wait for any click
	pOut->ClearDrawingArea();

	// Normal NOR
	pOut->DrawNOR2(GfxInfo1);
	// Highlighted NOR
	pOut->DrawNOR2(GfxInfo2, true);

	///TODO: Add code to draw 2-input OR and NOR gates, Normal and Highlighted for each

	pIn->GetPointClicked(x,y);	//Wait for any click
	pOut->ClearDrawingArea();

	/// 2.4- XOR2 and XNOR2 Gates test
	pOut->PrintMsg("Drawing 2-input XOR and XNOR gates, Normal and Highlighted,  Click to continue");
	// Normal XOR
	pOut->DrawXOR2(GfxInfo1);
	// Highlighted XOR
	pOut->DrawXOR2(GfxInfo2, true);

	pIn->GetPointClicked(x, y);	//Wait for any click
	pOut->ClearDrawingArea();

	// Normal XNOR
	pOut->DrawXNOR(GfxInfo1);
	// Highlighted XNOR
	pOut->DrawXNOR(GfxInfo2, true);

	///TODO: Add code to draw 2-input XOR and XNOR gates, Normal and Highlighted for each

	pIn->GetPointClicked(x,y);	//Wait for any click
	pOut->ClearDrawingArea();

	/// 2.5- Buffer and Inverter Gates test
	pOut->PrintMsg("Drawing Buffer and Inverter Gates, Normal and Highlighted,  Click to continue");
	
	// Normal Buffer
	pOut->DrawBUFFER(GfxInfo1);
	// Highlighted Buffer
	pOut->DrawBUFFER(GfxInfo2, true);

	pIn->GetPointClicked(x, y);	//Wait for any click
	pOut->ClearDrawingArea();

	// Normal Inverter
	pOut->DrawINVERTER(GfxInfo1);
	// Highlighed Inverter
	pOut->DrawINVERTER(GfxInfo2, true);

	///TODO: Add code to draw Buffer and Inverter Gates, Normal and Highlighted for each

	pIn->GetPointClicked(x,y);	//Wait for any click
	pOut->ClearDrawingArea();


	/// 2.6- AND3, NOR3, and XOR3 Gates test
	pOut->PrintMsg("Drawing 3-input AND, NOR, XOR Gates, Normal and Highlighted,  Click to continue");
	
	// Normal AND3
	pOut->DrawAND3(GfxInfo1);
	// Highlighted AND3
	pOut->DrawAND3(GfxInfo2, true);

	pIn->GetPointClicked(x, y);	//Wait for any click
	pOut->ClearDrawingArea();

	// Normal NOR3
	pOut->DrawNOR3(GfxInfo1);
	// Highlighted NOR3
	pOut->DrawNOR3(GfxInfo2, true);

	pIn->GetPointClicked(x, y);	//Wait for any click
	pOut->ClearDrawingArea();

	// Normal XOR3
	pOut->DrawXOR3(GfxInfo1);
	// Highlighted XOR3
	pOut->DrawXOR3(GfxInfo2, true);

	///TODO: Add code to draw 3-input AND, NOR, and XOR Gates, Normal and Highlighted for each

	pIn->GetPointClicked(x,y);	//Wait for any click
	pOut->ClearDrawingArea();

	/// 2.7- Switch and LED test
	pOut->PrintMsg("Drawing Switch and LED, Normal and Highlighted,  Click to continue");
	
	// Normal Switch
	pOut->DrawSWITCH(GfxInfo1);
	// Highlighted Switch
	pOut->DrawSWITCH(GfxInfo2, true);

	pIn->GetPointClicked(x, y);	//Wait for any click
	pOut->ClearDrawingArea();

	// Normal Bulb
	pOut->DrawBULB(GfxInfo1);
	// Highlighted Bulb
	pOut->DrawBULB(GfxInfo2, true);

	///TODO: Add code to draw Switch and LED, Normal and Highlighted for each

	pIn->GetPointClicked(x,y);	//Wait for any click
	pOut->ClearDrawingArea();


	/// 2.8- Connections
	pOut->PrintMsg("Drawing connections, Normal, Highlighted, straight, and broken,  Click to continue");
	
	pIn->GetPointClicked(x, y);
	GfxInfo.x1 = x; GfxInfo.y1 = y;
	pIn->GetPointClicked(x, y);
	GfxInfo.x2 = x; GfxInfo.y2 = y;
	pOut->DrawConnection(GfxInfo, false);

	GfxInfo.x1 = 200;	GfxInfo.y1 = 100;
	pOut->DrawAND2(GfxInfo);

	GfxInfo.x1 = 300;	GfxInfo.y1 = 100;
	pOut->DrawAND2(GfxInfo, true);

	pIn->GetPointClicked(x, y);
	GfxInfo.x1 = x; GfxInfo.y1 = y;
	pIn->GetPointClicked(x, y);
	GfxInfo.x2 = x; GfxInfo.y2 = y;
	pOut->DrawConnection(GfxInfo, false);

	GfxInfo.x1 = 400;	GfxInfo.y1 = 100;
	pOut->DrawAND2(GfxInfo);

	GfxInfo.x1 = 350;	GfxInfo.y1 = 200;
	pOut->DrawAND2(GfxInfo, true);

	pIn->GetPointClicked(x, y);
	GfxInfo.x1 = x; GfxInfo.y1 = y;
	pIn->GetPointClicked(x, y);
	GfxInfo.x2 = x; GfxInfo.y2 = y;
	pOut->DrawConnection(GfxInfo, false);

	GfxInfo.x1 = 500;	GfxInfo.y1 = 100;
	pOut->DrawAND2(GfxInfo);

	GfxInfo.x1 = 550;	GfxInfo.y1 = 200;
	pOut->DrawAND2(GfxInfo, true);

	pIn->GetPointClicked(x, y);
	GfxInfo.x1 = x; GfxInfo.y1 = y;
	pIn->GetPointClicked(x, y);
	GfxInfo.x2 = x; GfxInfo.y2 = y;
	pOut->DrawConnection(GfxInfo, false);
	///TODO: Add code to draw connections, Normal, Highlighted, straight, and broken (all combinations) 

	pIn->GetPointClicked(x, y);
	GfxInfo.x1 = x; GfxInfo.y1 = y;
	pIn->GetPointClicked(x, y);
	GfxInfo.x2 = x; GfxInfo.y2 = y;
	pOut->DrawConnection(GfxInfo, true);

	GfxInfo.x1 = 200;	GfxInfo.y1 = 300;
	pOut->DrawAND2(GfxInfo);

	GfxInfo.x1 = 300;	GfxInfo.y1 = 300;
	pOut->DrawAND2(GfxInfo, true);

	pIn->GetPointClicked(x, y);
	GfxInfo.x1 = x; GfxInfo.y1 = y;
	pIn->GetPointClicked(x, y);
	GfxInfo.x2 = x; GfxInfo.y2 = y;
	pOut->DrawConnection(GfxInfo, true);

	GfxInfo.x1 = 400;	GfxInfo.y1 = 300;
	pOut->DrawAND2(GfxInfo);

	GfxInfo.x1 = 350;	GfxInfo.y1 = 400;
	pOut->DrawAND2(GfxInfo, true);

	pIn->GetPointClicked(x, y);
	GfxInfo.x1 = x; GfxInfo.y1 = y;
	pIn->GetPointClicked(x, y);
	GfxInfo.x2 = x; GfxInfo.y2 = y;
	pOut->DrawConnection(GfxInfo, true);

	GfxInfo.x1 = 500;	GfxInfo.y1 = 300;
	pOut->DrawAND2(GfxInfo);

	GfxInfo.x1 = 550;	GfxInfo.y1 = 400;
	pOut->DrawAND2(GfxInfo, true);

	pIn->GetPointClicked(x, y);
	GfxInfo.x1 = x; GfxInfo.y1 = y;
	pIn->GetPointClicked(x, y);
	GfxInfo.x2 = x; GfxInfo.y2 = y;
	pOut->DrawConnection(GfxInfo, true);



	pIn->GetPointClicked(x,y);	//Wait for any click
	pOut->ClearDrawingArea();



	


	///////////////////////////////////////////////////////////////////////////////////
	// TEST 3: Read strings from the user
	///////////////////////////////////////////////////////////////////////////////////
	pOut->PrintMsg("TEST3: Now Time to test class Input, Click anywhere to continue");
	pIn->GetPointClicked(x,y);	//Wait for any click
	
	pOut->PrintMsg("Testing Input ability to read strings");
	//pOut->PrintInDrawingArea(pIn->GetSrting(pOut));


	string str = pIn->GetSrting(pOut);
	if (str != "")
	{
		//Drawing Normal AND2 gate
		GraphicsInfo GfxInfo;
		GfxInfo.x1 = 500;
		GfxInfo.y1 = 500;
		pOut->DrawAND2(GfxInfo);
		pOut->PrintLabelInDrawingArea(str, GfxInfo);
		pOut->ClearStatusBar();
	}

	///TODO: Add code here to 
	// 1- Read a string from the user on the status bar and print it inside the drawing area

	pOut->PrintMsg("Click anywhere to continue");


	pIn->GetPointClicked(x,y);	//Wait for any click
	pOut->ClearDrawingArea();

	///////////////////////////////////////////////////////////////////////////////////
	// TEST 4: Check for the user action
	///////////////////////////////////////////////////////////////////////////////////
	pOut->PrintMsg("TEST4: Testing Input ability to detect User Action, click anywhere");

	ActionType ActType;
	
	///TODO:  You must add a case for each action
	//Add cases for the missing actions below
	do
	{
		ActType = pIn->GetUserAction();

		switch (ActType)
		{
		case ADD_COMPONENT:
			pOut->PrintMsg("Action: Add a component, creating the gates bar");
			pOut->CreateGate1ToolBar();
			break;

		case ADD_Buff:
			pOut->PrintMsg("Action: add a buffer gate , Click anywhere");
			break;

		case ADD_INV:
			pOut->PrintMsg("Action: add an inverter gate , Click anywhere");
			break;

		case ADD_AND_GATE_2:
			pOut->PrintMsg("Action: add 2-input AND gate , Click anywhere");
			break;

		case ADD_OR_GATE_2:
			pOut->PrintMsg("Action: add 2-input OR gate , Click anywhere");
			break;

		case ADD_NAND_GATE_2:
			pOut->PrintMsg("Action: add 2-input NAND gate , Click anywhere");
			break;

		case ADD_NOR_GATE_2:
			pOut->PrintMsg("Action: add 2-input NOR gate , Click anywhere");
			break;

		case ADD_XOR_GATE_2:
			pOut->PrintMsg("Action: add 2-input XOR gate , Click anywhere");
			break;

		case ADD_XNOR_GATE_2:
			pOut->PrintMsg("Action: add 2-input XNOR gate , Click anywhere");
			break;

		case ADD_AND_GATE_3:
			pOut->PrintMsg("Action: add 3-input AND gate , Click anywhere");
			break;

		case ADD_NOR_GATE_3:
			pOut->PrintMsg("Action: add 3-input NOR gate , Click anywhere");
			break;

		case ADD_XOR_GATE_3:
			pOut->PrintMsg("Action: add 3-input XOR gate , Click anywhere");
			break;

		case ADD_Switch:
			pOut->PrintMsg("Action: add switch , Click anywhere");
			break;

		case ADD_LED:
			pOut->PrintMsg("Action: add LED , Click anywhere");
			break;

		case ADD_CONNECTION:
			pOut->PrintMsg("Action: add a wire, Click anywhere");
			break;	

		case Gate_Menu1:
			pOut->PrintMsg("Action: switch to first gates bar , creating first gates bar");
			pOut->CreateGate1ToolBar();
			break;

		case Gate_Menu2:
			pOut->PrintMsg("Action: switch to second gates bar , Creating second gates bar");
			pOut->CreateGate2ToolBar();
			break;

		case ADD_Label:
			pOut->PrintMsg("Action: Add label for the selected component, click anywhere");
			break;

		case EDIT_Label:
			pOut->PrintMsg("Action: Edit label of the component, click anywhere");
			break;

		case Create_TruthTable:
			pOut->PrintMsg("Action: Create truth table, click anywhere");
			break;

		case Change_Switch:
			pOut->PrintMsg("Action: a click on the drawing area, change switch status, click anywhere");
			break;

		case SELECT:
			pOut->PrintMsg("Action: a click on the Drawing area, Click anywhere");
			break;

		case DEL:
			pOut->PrintMsg("Action: delete a component, click anywhere");
			break;
			
		case MOVE:
			pOut->PrintMsg("Action: Move, click anywhere");
			break;

		case SAVE:
			pOut->PrintMsg("Action: Save, click anywhere");
			break;

		case LOAD:
			pOut->PrintMsg("Action: Load, click anywhere");
			break;

		case UNDO:
			pOut->PrintMsg("Action: Undo, Click anywhere");
			break;

		case REDO:
			pOut->PrintMsg("Action: Redo , click anywhere");
			break;

		case DSN_MODE:
			pOut->PrintMsg("Action: Switch to Design Mode, creating Design tool bar");
			pOut->CreateDesignToolBar();
			break;

		case SIM_MODE:
			pOut->PrintMsg("Action: Switch to Simulation Mode, creating simualtion tool bar");
			pOut->CreateSimulationToolBar();
			break;

		case SIMULATE:
			pOut->PrintMsg("Action: Simulate the circuit, Click anywhere");
			break;

		case PROBE:
			pOut->PrintMsg("Action: Probing, Click anywhere");
			break;

		case STATUS_BAR:
			pOut->PrintMsg("Action: a click on the Status Bar, Click anywhere");
			break;
 
		case DSN_TOOL:
			pOut->PrintMsg("Action: a click on empty area in the Design Tool Bar, Click anywhere");
			break;

		case GATE_TOOL:
			pOut->PrintMsg("Action: a click on an empty space in gates Bar 2, Click anywhere");
			break;

		case SIM_TOOL:
			pOut->PrintMsg("Action: a click on an empty space in the simulation Bar, Click anywhere");
			break;

		case EXIT:	
			break;
		}
	}while(ActType != EXIT);



	/// Exiting
	pOut->PrintMsg("Action: EXIT, test is finished, click anywhere to exit");
	pIn->GetPointClicked(x,y);

	
	delete pIn;
	delete pOut;	
	return 0;
}


