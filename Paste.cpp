#include "Paste.h"

Paste::Paste(ApplicationManager* pApp) :Action(pApp)
{
}

Paste::~Paste(void)
{
}

void Paste::ReadActionParameters()
{
}

void Paste::Execute()
{
	Output* pOut = pManager->GetOutput();

	CopiedComp = pManager->GetCopiedComp();

	//Execute the action of adding the copied component
	switch (CopiedComp)
	{
	case Comp_AND2:
		pManager->ExecuteAction(ADD_AND_GATE_2);
		break;

	case Comp_OR2:
		pManager->ExecuteAction(ADD_OR_GATE_2);
		break;

	case Comp_NAND2:
		pManager->ExecuteAction(ADD_NAND_GATE_2);
		break;

	case Comp_NOR2:
		pManager->ExecuteAction(ADD_NOR_GATE_2);
		break;

	case Comp_XOR2:
		pManager->ExecuteAction(ADD_XOR_GATE_2);
		break;

	case Comp_XNOR2:
		pManager->ExecuteAction(ADD_XNOR_GATE_2);
		break;

	case Comp_AND3:
		pManager->ExecuteAction(ADD_AND_GATE_3);
		break;

	case Comp_XOR3:
		pManager->ExecuteAction(ADD_XOR_GATE_3);
		break;

	case Comp_NOR3:
		pManager->ExecuteAction(ADD_NOR_GATE_3);
		break;

	case Comp_BUFF:
		pManager->ExecuteAction(ADD_Buff);
		break;

	case Comp_INV:
		pManager->ExecuteAction(ADD_INV);
		break;

	case Comp_SWITCH:
		pManager->ExecuteAction(ADD_Switch);
		break;

	case Comp_LED:
		pManager->ExecuteAction(ADD_LED);
		break;

	default:
		pOut->PrintMsg("No copied component to paste");
		break;
	}
}

void Paste::Undo()
{
}

void Paste::Redo()
{
}
