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
	int        size; // ������ ������ � ��������
	::Position   start;
	::Position   end;


	void LoadImage(UnicodeString FileName);
	void DrawBoard();
	int GetType(int ARow, int ACol);
	/*
		0 - ������ ������ ������
		1 - ����� ������ ������
		2 - ������ ���� �� ������ ������
		3 - ������ ���� �� ����� ������
		4 - ������ ������
		5 - ...
		6 - ������ ����
		7 - ...
		8 - ������ �����
		9 - ...
		10 - ������ �����
		11 - ...
		12 - ������ �����
		13 - ...
		14 - ����� ���� �� ������ ������
		15 - ����� ���� �� ����� ������
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
