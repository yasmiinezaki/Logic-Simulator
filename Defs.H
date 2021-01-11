#ifndef CONST_H
#define CONST_H

//This header file contains some defenitions to be used all over the application

//All possible actions
enum ActionType
{
	ADD_COMPONENT,      //Open the gates bar
	ADD_Buff,			//Add 1-input Buffer gate
	ADD_INV,			//Add 1-input Inverter gate
	ADD_AND_GATE_2,		//Add 2-input AND gate
	ADD_OR_GATE_2,		//Add 2-input OR gate
	ADD_NAND_GATE_2,	//Add 2-input NAND gate
	ADD_NOR_GATE_2,		//Add 2-input NOR gate
	ADD_XOR_GATE_2,		//Add 2-input XOR gate
	ADD_XNOR_GATE_2,	//Add 2-input XNOR gate
	ADD_AND_GATE_3,		//Add 3-input AND gate
	ADD_NOR_GATE_3,		//Add 3-input NOR gate
	ADD_XOR_GATE_3,		//Add 3-input XOR gate
	ADD_Switch,			//Add Switch
	ADD_LED,			//Add LED
	ADD_CONNECTION,		//Add Wire Connection

	CUT,
	COPY,
	PASTE,

	Gate_Menu1,         //Switch to the first gate menu
	Gate_Menu2,         //Switch to the second gate menu

	ADD_Label,			//Add Label to a Component, a Connection
	EDIT,			//Edit Label of a Component, or edit a Connection

	Create_TruthTable,	//Create Truth Table of the Circuit

	Change_Switch,		//Change Switch Status in Simulation Mode

	SELECT,		//Select a Component, a Connection
	DEL,		//Delete a Component, a Connection
	MOVE,		//Move a Component, a Connection

	SAVE,		//Save the whole Circuit to a file
	LOAD,		//Load a Circuit from a file

	//UNDO,		//Undo the last Action preformed
	//REDO,		//Redo the last Action canceled

	DSN_MODE,	//Switch to Design mode
	SIM_MODE,	//Switch to Simulatiom mode

	SIMULATE,   //simulate the circuit by showing the output results
	PROBE,

	STATUS_BAR,		//A click on the status bar
	DSN_TOOL,	//A click on an empty place in the design tool bar or simulation tool bar
	GATE_TOOL,   //A click on an empty place in the second gates menu 
	SIM_TOOL,   //A click on an empty place in the simulation toolbar

	EXIT		//Exit the application


};

//Possible Status for the pin
enum STATUS
{
	LOW,
	HIGH,
	NOTAssigned
};

enum  MODE	//Modes of operation
{
	DESIGN,
	SIMULATION
};

enum GATESMENUMODE
{
	NO_GATE_MENU,
	GATE_MODE1,
	GATE_MODE2
};

enum DsgnMenuItem //The items of the design menu (you should add more items)
{
	//Note: Items are ordered here as they appear in menu
	//If you want to change the menu items order, change the order here
	ITM_ADD,
	ITM_LABEL,
	ITM_EDIT,
	ITM_DELETE,
	ITM_SAVE,
	ITM_LOAD,
	ITM_MOVE,
	ITM_CUT,
	ITM_COPY,
	ITM_PASTE,
	ITM_SWITCH_TO_SIM,
	ITM_EXIT,		//Exit item

	//TODO: Add more items names here
	
	ITM_DSN_CNT		//no. of design menu items ==> This should be the last line in this enum
	
};


enum SimMenuItem //The items of the simulation menu (you should add more items)
{
	//Note: Items are ordered here as they appear in menu
	//ITM_ChangeSwitch,
    ITM_PROBE,
	ITM_TRUTH,	//Truth table menu item
	
	ITM_SWITCH_TO_DSN,

	//TODO:Add more items names here
	
	ITM_SIM_CNT		//no. of simulation menu items ==> This should be the last line in this enum
	
};

enum GatesMenuItem1
{
	ITM_AND2,		//AND gate item in menu
	ITM_OR2,		//OR gate item in menu
	ITM_NAND2,
	ITM_NOR2,
	ITM_XOR2,
	ITM_XNOR2,
	ITM_AND3,
	ITM_XOR3,
	ITM_NOR3,
	ITM_BUFF,
	ITM_NEXT,

	ITM_GATES1_CNT
};

enum GatesMenuItem2
{
	ITM_PREVIOUS,
	ITM_INV,
	ITM_SWITCH,
	ITM_LED,
	ITM_WIRE,

	ITM_GATES2_CNT
};

//Maximum number of input pins that can be connected to any output pin
#define MAX_CONNS 20

//assume fan out is 5 for now it can be read from the user or can be predefined as const
enum FANOUT
{
	AND2_FANOUT = 5	//Default fan out of 2-input AND gate
};

//A structure to contain drawing parameters for each component
//Each component occupies a rectangluar area so it needs 2 points to represent that area
//this structure can be extended if desired
struct GraphicsInfo
{
	int x1,y1, x2, y2;
};

enum CompType
{
	Comp_AND2,		//AND gate item in menu
	Comp_OR2,		//OR gate item in menu
	Comp_NAND2,
	Comp_NOR2,
	Comp_XOR2,
	Comp_XNOR2,
	Comp_AND3,
	Comp_XOR3,
	Comp_NOR3,
	Comp_BUFF,
	Comp_INV,
	Comp_SWITCH,
	Comp_LED,
	Comp_WIRE,

	NoComp //when there is no component
};

#ifndef NULL
#define NULL 0
#endif

#endif