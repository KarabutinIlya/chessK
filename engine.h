//---------------------------------------------------------------------------

#ifndef engineH
#define engineH
#include <memory.h>
//---------------------------------------------------------------------------
enum GState
{
	qsWhite,							// ��� �����
	qsBlack,                            // ��� ������
	qsMateWhite,                        // ��� ������
	qsMateBlack,                        // ��� �������
	qsStalemat,                         // �����
	qsCheakWhite,                       // ��� �����
	qsCheakBlack                        // ��� ������
};
//---------------------------------------------------------------------------
enum GType
{
	qsPown,							   // �����
	qsRook,                            // �����
	qsKing,                            // ������
	qsQueen,                           // �����
	qsBishop,                          // ����
	qsKnight,                          // ����
	none,                              // �����
};

//---------------------------------------------------------------------------
class Position
{
	public:
		int Row; //������
		int Col; //�������
		Position(int ARow, int ACol);
};
//---------------------------------------------------------------------------
class Board; //��������������� ����������
//---------------------------------------------------------------------------
class Figure //������� ����� ������
{
		Position pos;    //������� �������
		bool     color;  //���� �������; 1 ����� 0  ������
		GType type;       //��� ������

	public:
		Figure(Position APos, bool AColor, GType pType); // ����������� � �����������
		void Move(Position APos);           // ����������� ������ � ������� APos
		const Position& Pos()const;         // ������� ������
		bool Color()const;                  // ���� ������
        GType Type()const;                   // ��� ������
		virtual bool ChekMove(Position APos, Board *ABoard)const=0;
};
//---------------------------------------------------------------------------
class Rook:public Figure // �����
{
	public:
		bool ChekMove(Position APos,Board *ABoard)const;
		Rook(Position APos, bool AColor);
};
//---------------------------------------------------------------------------
class Pown:public Figure // �����
{
	public:
		bool ChekMove(Position APos, Board *ABoard)const;
		Pown(Position APos, bool AColor);
};
//---------------------------------------------------------------------------
class King:public Figure // ������
{
	public:
		bool ChekMove(Position APos, Board *ABoard)const;
		King(Position APos, bool AColor);
};
//---------------------------------------------------------------------------
class Queen:public Figure // �����
{
	public:
		bool ChekMove(Position APos, Board *ABoard)const;
		Queen(Position APos, bool AColor);
};
//---------------------------------------------------------------------------
class Bishop:public Figure // ����
{
	public:
		bool ChekMove(Position APos, Board *ABoard)const;
		Bishop(Position APos, bool AColor);
};
//---------------------------------------------------------------------------
class Knight:public Figure // ����
{
	public:
		bool ChekMove(Position APos, Board *ABoard)const;
		Knight(Position APos, bool AColor);
};
//---------------------------------------------------------------------------
// ����� ����� � ��������
class Board
{
	private:
		GState state; // ��������� �������
		Figure *board[8][8];
		void ClearBoard(); // ������� ����� (�������� �����)
		void ChangeState(); // �������� ���
		Position BlackKing; // ������� ������� ������
		Position WhiteKing; // ������� ������ ������
		unsigned short int StalematCount; // ������� �����. ������� ���������� ��������� �����
										  // � ������� ���������� ���� ������ ��� ������� ������

	public:
		Board();
		~Board();
		void NewGame(); // ���������� ��������� �������
		bool Move(Position AStart,Position AEnd);
		const Figure* Get(int ARow, int ACol)const;
		bool CheckShah(bool pColor); // ������� �������� ���� ������
		bool CheckStalemat()const; // ������� ��������� ������ ����� �������
								   // ���������� true, ���� �� ���� 2 ������ ���
								   // 2 ������ � 1 ������ ������ (���� ��� ����)
		GState State()const;
};
//---------------------------------------------------------------------------
#endif
