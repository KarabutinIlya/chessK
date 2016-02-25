//---------------------------------------------------------------------------

#ifndef mainH
#define mainH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.Menus.hpp>
#include <Vcl.ImgList.hpp>
#include <jpeg.hpp>
#include <gifimg.hpp>
#include "engine.h">


//---------------------------------------------------------------------------
class TMainForm : public TForm
{
__published:	// IDE-managed Components
	TImage *Image;
	TMainMenu *MainMenu1;
	TMenuItem *Game1;
	TImageList *ImageList;
	void __fastcall FormShow(TObject *Sender);
	void __fastcall Game1Click(TObject *Sender);
	void __fastcall ImageMouseDown(TObject *Sender, TMouseButton Button, TShiftState Shift,
          int X, int Y);

private:	// User declarations
	TJPEGImage *jpgImage;
	TBitmap    *bitmap;
	Board      board;
	int        size; // размер ячейки в пикселях
	::Position   start;
	::Position   end;


	void LoadImage(UnicodeString FileName);
	void DrawBoard();
	int GetType(int ARow, int ACol);
	/*
		0 - черная пустая клетка
		1 - белая пустая клетка
		2 - черный слон на черной клетке
		3 - черный слон на белой клетке
		4 - черный король
		5 - ...
		6 - черный конь
		7 - ...
		8 - черная пешка
		9 - ...
		10 - черный ферзь
		11 - ...
		12 - черная ладья
		13 - ...
		14 - белый слон на черной клетке
		15 - белый слон на белой клетке
		16 - ...
		...
	*/

public:		// User declarations
	__fastcall TMainForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TMainForm *MainForm;
//---------------------------------------------------------------------------
#endif
