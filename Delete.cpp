#include "Delete.h"


Delete::Delete(ApplicationManager* pMang) : Action(pMang)
{
	x = 0;
	y = 0;
	CompToDelete = NULL;
	Index = -1;
}
Delete::~Delete(void)
{}
void Delete::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	CompToDelete=pManager->GetSelectedComp(Index);
}
	
void Delete::Execute()
{
	//get point clicked
	ReadActionParameters();
	if (CompToDelete)
	{
		CompType TypeToDelete = CompToDelete->GetCompType();
		if (TypeToDelete != Comp_WIRE)
		{
			Gate* GateDeleted = (Gate*)CompToDelete;

			
			InputPin* pInPin[3] = { NULL,NULL,NULL }; // get input pins of gate
			Connection* DstConns[3] = { NULL,NULL,NULL }; //get connection pointers connected to input pins
			
			int nOfInputPins = GateDeleted->get_m_Inputs();
			for (int i = 0; i < nOfInputPins; i++)
			{
				GateDeleted->getDestPinPointer(pInPin[i], i);
				if (pInPin[i])
				{
					DstConns[i]=pInPin[i]->getConnection();
					if (DstConns[i])
					{
 						Component* CompConnected=DstConns[i]->getSrcCmpnt();
						Gate* GateConnected = (Gate*)CompConnected;
						if (GateConnected)
						{
							GateConnected->ResetSrcPinValidity();
						}
						int j = -1;
						j = pManager->ReturnIndex(DstConns[i]);
						if (j != -1)
						{
							pManager->RemoveComp(j);
						}
					}
				}
			}
			OutputPin* pOutPin;
			GateDeleted->getSourcePinPointer(pOutPin);
			Connection* SrcConns[20]; // Array to store all connections connected to output pin of the gate
			for (int i = 0; i < MAX_CONNS; i++)
			{
				SrcConns[i] = NULL;
			}
			for (int i = 0; i < MAX_CONNS ; i++)
			{
				SrcConns[i] = pOutPin->get_m_Connections(i);
				if (SrcConns[i])
				{
					Component* CompConnected = SrcConns[i]->getDstCmpnt();
					Gate* GateConnected = (Gate*)CompConnected;
					if (GateConnected)
					{
						int c = SrcConns[i]->getIndexDstPin();
						GateConnected->ResetDstPinValidity(c);
					}
					int j = -1;
					j = pManager->ReturnIndex(SrcConns[i]);
					if (j != -1)
					{
						pManager->RemoveComp(j);
					}
				}
			}
			pManager->RemoveComp(Index);
			pManager->SetSelectedComp(NULL);
			pManager->RemoveSelectedIndex();
		}
		else
		{
			Connection* ConnToDelete = (Connection*)CompToDelete;
			Component* CompConnected1 = ConnToDelete->getDstCmpnt();
			Component* CompConnected2 = ConnToDelete->getSrcCmpnt();

			Gate* GateConnected1 = (Gate*)CompConnected1;
			Gate* GateConnected2 = (Gate*)CompConnected2;

			int c = ConnToDelete->getIndexDstPin();
			GateConnected1->ResetDstPinValidity(c);
			GateConnected2->ResetSrcPinValidity();

			pManager->RemoveComp(Index);
			pManager->SetSelectedComp(NULL);
			pManager->RemoveSelectedIndex();
		}
	}
}
void Delete::Undo()
{}
void Delete::Redo()
{}