#include "AddNAND2.h"
#include "ApplicationManager.h"

AddNAND2::AddNAND2(ApplicationManager *pApp) :Action(pApp)
{
}

AddNAND2::~AddNAND2(void)
{
}

void AddNAND2::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	//Print Action Message
	pOut->PrintMsg("2-Input NAND Gate: Click to add the gate");

	//Wait for User Input
	pIn->GetPointClicked(Cx, Cy);

	// calculate the new 

	if (Cx % 15 > 7) Cx = Cx / 15 + 1;
	else if (Cx % 15 <= 7)Cx = Cx / 15 - 1;
	if (Cy % 15 > 7) Cy = Cy / 15 + 1;
	else if (Cy % 15 <= 7)Cy = Cy / 15 - 1;
	Cx *= 15; Cy *= 15;
	while (!pManager->check_matrix(Cx, Cy))
	{
		pOut->PrintMsg("This area is not empty choose another place"); ////hebaaaaa wrbna ystorrrr
		pIn->GetPointClicked(Cx, Cy);
		if (Cx % 15 > 7) Cx = Cx / 15 + 1;
		else if (Cx % 15 <= 7)Cx = Cx / 15 - 1;
		if (Cy % 15 > 7) Cy = Cy / 15 + 1;
		else if (Cy % 15 <= 7)Cy = Cy / 15 - 1;
		Cx *= 15; Cy *= 15;
	}//call fn elahsas

	 //Clear Status Bar
	pOut->ClearStatusBar();

}

void AddNAND2::Execute()
{
	//Get Center point of the Gate
	ReadActionParameters();

	//Calculate the rectangle Corners
	int Len = UI.NAND2_Width;
	int Wdth = UI.NAND2_Height;

	GraphicsInfo GInfo; //Gfx info to be used to construct the NAND2 gate

	GInfo.x1 = Cx - Len / 2;
	GInfo.x2 = Cx + Len / 2;
	GInfo.y1 = Cy - Wdth / 2;
	GInfo.y2 = Cy + Wdth / 2;
	NAND2 *pA = new NAND2(GInfo, NAND2_FANOUT);
	pA->updateMatrix(GInfo, pA->getid(), pA->gettype());
	pManager->AddComponent(pA);
}

void AddNAND2::Undo()
{}

void AddNAND2::Redo()
{}

