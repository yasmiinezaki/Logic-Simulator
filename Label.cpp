#include "Label.h"

Label::Label(ApplicationManager* pApp) :Action(pApp)
{
}

Label::~Label(void)
{
}

void Label::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	//Print Action Message
	pOut->PrintMsg("Label: Choose the component to label");

	//Wait for User Input
	pIn->GetPointClicked(Cx, Cy);

	//Clear Status Bar
	pOut->ClearStatusBar();

}

void Label::Execute()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();


	//Get Center point of the Gate
	ReadActionParameters();
	int FoundCompCount;

	//Find the component
	CompType FoundCompType;
	Component* CompLabel= pManager->FindComp(Cx, Cy, FoundCompCount, FoundCompType);

	if (FoundCompType != NoComp)
	{
		Component* Comp = pManager->GetComp(FoundCompCount);
		pOut->PrintMsg("Write the label");
		string Label = pIn->GetSrting(pOut);
		Comp->SetLabel(Label);
		pOut->PrintLabelInDrawingArea(Label, Comp->GetGraphicsInfo());
		pOut->ClearStatusBar();
	}
	else
	{
		pOut->PrintMsg("You did not click on a component. Try again");
	}
}

void Label::Undo()
{
}

void Label::Redo()
{
}

