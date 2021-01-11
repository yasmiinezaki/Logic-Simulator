#include "Load.h"
#include <fstream>

Load::Load(ApplicationManager* pApp) :Action(pApp)
{
}

Load::~Load(void)
{
}

void Load::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	//Print Action Message
	pOut->PrintMsg("Load: write the name of the file: ");

	//Wait for User text
	FileName = pIn->GetSrting(pOut);
	//adding .txt to the file name
	FileName = FileName + ".txt";
	//Clear Status Bar
	pOut->ClearStatusBar();
}

void Load::Execute()
{
	Output* pOut = pManager->GetOutput();

	//get user file name
	ReadActionParameters();

	ifstream LoadFile;
	LoadFile.open(FileName);
	if (LoadFile.is_open())
	{
		pManager->LoadAll(LoadFile);
		LoadFile.close();
		pOut->PrintMsg("Loaded");
	}
	else
	{
		pOut->PrintMsg("There is no file with this name.");
	}
}

void Load::Undo()
{
}

void Load::Redo()
{
}



