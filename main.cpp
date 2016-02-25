//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "main.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TMainForm *MainForm;
//---------------------------------------------------------------------------
__fastcall TMainForm::TMainForm(TComponent* Owner)
	: TForm(Owner),
	jpgImage(new TJPEGImage),
	bitmap(new TBitmap),
	start(-1,-1),
	end(-1,-1)
{
}
//---------------------------------------------------------------------------
// Загрузка изображения из jpeg-файла и добавление в список изображений ImageList
void TMainForm::LoadImage(UnicodeString FileName)
{
	jpgImage->LoadFromFile("bitmap/" + FileName + ".jpg");
	size = jpgImage->Width;
	ImageList->Width = size;
	ImageList->Height = size;
	bitmap->Assign(jpgImage);
	ImageList->Add(bitmap, bitmap);
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::FormShow(TObject *Sender)
{
	// Загрузка изображений фигур
	LoadImage("b");
	LoadImage("w");
	LoadImage("bbb");
	LoadImage("bbw");
	LoadImage("bkb");
	LoadImage("bkw");
	LoadImage("bnb");
	LoadImage("bnw");
	LoadImage("bpb");
	LoadImage("bpw");
	LoadImage("bqb");
	LoadImage("bqw");
	LoadImage("brb");
	LoadImage("brw");
	LoadImage("wbb");
	LoadImage("wbw");
	LoadImage("wkb");
	LoadImage("wkw");
	LoadImage("wnb");
	LoadImage("wnw");
	LoadImage("wpb");
	LoadImage("wpw");
	LoadImage("wqb");
	LoadImage("wqw");
	LoadImage("wrb");
	LoadImage("wrw");
	// Задание размеров формы
	MainForm->Width = size * 8 + 4;
	MainForm->Height = MainForm->Width + 41;
	// Рисование доски
    DrawBoard();
}
//---------------------------------------------------------------------------
int TMainForm::GetType(int ARow, int ACol)
{
	int colorCell = !((ARow + ACol)%2); // цвет ячейки
	int type; // тип фигуры
	if(dynamic_cast<const Bishop*>(board.Get(ARow, ACol)) )
		type = 2;
	else if(dynamic_cast<const King*>(board.Get(ARow, ACol)) )
		type = 4;
	else if(dynamic_cast<const Knight*>(board.Get(ARow, ACol)) )
		type = 6;
	else if(dynamic_cast<const Pown*>(board.Get(ARow, ACol)) )
		type = 8;
	else if(dynamic_cast<const Queen*>(board.Get(ARow, ACol)) )
		type = 10;
	else if(dynamic_cast<const Rook*>(board.Get(ARow, ACol)) )
		type = 12;
	else
	   return colorCell; // пустая клетка

	int colorFigure = board.Get(ARow, ACol)->Color(); // цвет фигуры
	if(colorFigure)
		return 	type + 12 + colorCell;
	else return  type + colorCell;

}
//---------------------------------------------------------------------------
// рисование доски
void TMainForm::DrawBoard()
{
	for(int i = 0; i < 8; i++)
		for(int j = 0; j < 8; j++)
		{
			ImageList->GetBitmap(GetType(i,j), bitmap);
			Image->Canvas->Draw(j*size, i*size, bitmap);
		}
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::Game1Click(TObject *Sender)
{
	 board.NewGame();
	 DrawBoard();
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::ImageMouseDown(TObject *Sender, TMouseButton Button, TShiftState Shift,
          int X, int Y)
{
	 if(start.Row == -1) // если выбирается начальная позиция фигуры
	 {
		 start.Row = Y/size;
		 start.Col = X/size;
	 }
	 else // выбрана конечная позиция фигуры
	 {
		 end.Row = Y/size;
		 end.Col = X/size;
		 board.Move(start, end);
		 start.Row = -1;
		 DrawBoard();
	 }
}
//---------------------------------------------------------------------------

