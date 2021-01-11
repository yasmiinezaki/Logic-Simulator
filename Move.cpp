#include "Move.h"

Move::Move(ApplicationManager* pApp) :Action(pApp)
{
}

Move::~Move(void)
{
}

void Move::ReadActionParameters()
{

    /* Output* pOut = pManager->GetOutput();
     Input* pIn = pManager->GetInput();
     pIn->ReturnPointClicked(x, y);*/
}

void Move::Execute()
{
    //ReadActionParameters();
    Output* pOut = pManager->GetOutput();
    Input* pIn = pManager->GetInput();

    while (pIn->GetButtonState(LEFT_BUTTON, x, y) == BUTTON_DOWN)
    {
        int Len = UI.AND2_Width;
        int Wdth = UI.AND2_Height;

        GraphicsInfo NewGInfo; //Gfx info to be used to construct the AND2 gate

        NewGInfo.x1 = x - Len / 2;
        NewGInfo.x2 = x + Len / 2;
        NewGInfo.y1 = y - Wdth / 2;
        NewGInfo.y2 = y + Wdth / 2;
        pOut->Test(NewGInfo);
    }



    //CompType Type;
    //int Index;
    //Component* SelectedComp =  pManager->FindComp(x, y, Index, Type);
    //if (Type != NoComp && Type != Comp_WIRE)
    //{
    //    GraphicsInfo GInfo = SelectedComp->GetGraphicsInfo();
    //    pOut->Test(GInfo);
    //    pOut->PrintMsg("Now Drag");
    //    //Borders:
    //    int StartX = 0;
    //    int EndX = UI.width;
    //    int startY = UI.ToolBarHeight * 2;
    //    int EndY = UI.StatusBarHeight;
    //    while (pIn->GetButtonState(LEFT_BUTTON, x, y) == BUTTON_DOWN)
    //    {
    //        /*if (x > StartX&& x<EndX && y>startY&& y < EndY)
    //        {*/
    //            int Len = UI.AND2_Width;
    //            int Wdth = UI.AND2_Height;

    //            GraphicsInfo NewGInfo; //Gfx info to be used to construct the AND2 gate

    //            NewGInfo.x1 = x - Len / 2;
    //            NewGInfo.x2 = x + Len / 2;
    //            NewGInfo.y1 = y - Wdth / 2;
    //            NewGInfo.y2 = y + Wdth / 2;
    //            pOut->Test(NewGInfo);
    //        
    //    }
    //}
    //else
    //{
    //    pOut->PrintMsg("You did not select a gate");
    //}

//    int RectULX = 100;
//    int RectULY = 100;
//    int RectWidth = 20;
//
//    bool bDragging = false;
//
//    iX = iY = 0;
//
//    int iXOld = 0;
//    int iYOld = 0;
//
//    // Loop until there escape is pressed
//    while (testWindow.GetKeyPress(cKeyData) != ESCAPE)
//    {
//        testWindow.SetPen(WHITE);
//        testWindow.SetBrush(WHITE);
//        testWindow.DrawRectangle(0, 0, testWindow.GetWidth() - 1, testWindow.GetHeight() - 1);
//
//
//        // Dragging voodoo
//        if (bDragging == false) {
//            if (testWindow.GetButtonState(LEFT_BUTTON, iX, iY) == BUTTON_DOWN) {
//                if (((iX > RectULX) && (iX < (RectULX + RectWidth))) && ((iY > RectULY) && (iY < (RectULY + RectWidth)))) {
//                    bDragging = true;
//                    iXOld = iX; iYOld = iY;
//                }
//            }
//        }
//        else {
//            if (testWindow.GetButtonState(LEFT_BUTTON, iX, iY) == BUTTON_UP) {
//                bDragging = false;
//            }
//            else {
//                if (iX != iXOld) {
//                    RectULX = RectULX + (iX - iXOld);
//                    iXOld = iX;
//                }
//                if (iY != iYOld) {
//                    RectULY = RectULY + (iY - iYOld);
//                    iYOld = iY;
//                }
//            }
//
//        }
//
//        // Draw rectangle
//
//        testWindow.SetPen(ORANGE);
//        testWindow.SetBrush(ORANGE);
//        testWindow.DrawRectangle(RectULX, RectULY, RectULX + RectWidth, RectULY + RectWidth);
//
//        // Draw some info 
//        testWindow.SetPen(BLACK);
//        testWindow.DrawString(5, 5, "MouseState Demo. Drag the orange box around. Press \"Escape\" to quit");
//
//        // Update the screen buffer
//        testWindow.UpdateBuffer();
//
//    }
//
//    testWindow.SetBuffering(false);
//
//    return 0;
//}
}

void Move::Undo()
{
}

void Move::Redo()
{
}

