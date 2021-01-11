#include "Save.h"
#include <fstream>

Save::Save(ApplicationManager* pApp) :Action(pApp)
{
}

Save::~Save(void)
{
}

void Save::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	//Print Action Message
	pOut->PrintMsg("Save: write the name of the file: ");

	//Wait for User text
	FileName = pIn->GetSrting(pOut);
	//adding .txt to the file name
	FileName = FileName + ".txt";
	//Clear Status Bar
	pOut->ClearStatusBar();
}

void Save::Execute()
{
	Output* pOut = pManager->GetOutput();
	//get user file name
	ReadActionParameters();

	//clear any existing data in the file
	ofstream SaveFile;
	SaveFile.open(FileName);
	SaveFile.clear();
	SaveFile.close();

	//writing to a text file, adding the new data
	SaveFile.open(FileName, ios::app);
	pManager->SaveAll(SaveFile);
	SaveFile.close();
	pOut->PrintMsg("Saved");
}

void Save::Undo()
{
}

void Save::Redo()
{
}
