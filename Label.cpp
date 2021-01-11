#include "Label.h"
#include <string>
Label::Label(ApplicationManager* pMang) : Action(pMang)
{
	x = 0;
	y = 0;
	Index = -1;
	CompLabeled = NULL;

	//Get a Pointer to the Input / Output Interfaces
	pOut = pManager->GetOutput();
	pIn = pManager->GetInput();

}
Label::~Label(void)
{}
void Label::ReadActionParameters()
{
	int Index = -1;
	CompLabeled = pManager->GetSelectedComp(Index);

	if (CompLabeled)
	{
		pOut->PrintMsg("Please enter label: ");
		UserLabel = pIn->GetSrting(pOut);
		std::string str = UserLabel;
		std::string first_ten = str.substr(0, 10);
		UserLabel = first_ten;
		pOut->ClearStatusBar();
		CompLabeled->setLabel(first_ten);
	}
	else
	{
		pOut->PrintMsg("Action unsuccessful. Please Try again.");
	}

}
void Label::Execute()
{
	ReadActionParameters();
	if (CompLabeled)
	{
		pOut->PrintLabelInDrawingArea(UserLabel, CompLabeled->GetGraphicsInfo());
	}
}
void Label::Undo()
{}
void Label::Redo()
{}