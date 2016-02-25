//---------------------------------------------------------------------------

#pragma hdrstop

#include "engine.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
//---------------------------------------------------------------------------
Position::Position(int ARow, int ACol) : Row(ARow), Col(ACol){}
//---------------------------------------------------------------------------
void Figure::Move(Position APos)//����������
{
	pos = APos;
}
//---------------------------------------------------------------------------
const Position &Figure::Pos()const //������� ������
{
	return pos;
}
//---------------------------------------------------------------------------
bool Figure::Color()const//������� �����
{
	return color;
}
//---------------------------------------------------------------------------
GType Figure::Type()const//������� ����
{
	return type;
}
//---------------------------------------------------------------------------
Figure::Figure(Position APos, bool AColor, GType pType)//����������� � �����������
   : pos(APos), color(AColor), type(pType) {}
//---------------------------------------------------------------------------
Rook :: Rook(Position APos, bool AColor) : Figure(APos, AColor, qsRook){}
//---------------------------------------------------------------------------
Pown :: Pown(Position APos, bool AColor) : Figure(APos, AColor, qsPown){}
//---------------------------------------------------------------------------
King :: King(Position APos, bool AColor) : Figure(APos, AColor, qsKing) {}
//---------------------------------------------------------------------------
Queen :: Queen(Position APos, bool AColor) : Figure(APos, AColor, qsQueen) {}
//---------------------------------------------------------------------------
Bishop :: Bishop(Position APos, bool AColor) : Figure(APos, AColor, qsBishop) {}
//---------------------------------------------------------------------------
Knight :: Knight(Position APos, bool AColor) : Figure(APos, AColor, qsKnight) {}
//---------------------------------------------------------------------------
void Board::ClearBoard() // ������� ����� (�������� �����)
{
	for(int i = 0; i < 8; i++)
		for(int j = 0; j < 8; j++)
			if(board[i] != NULL)
			{
				delete board[i][j];
				board[i][j] = NULL;
			}
}
//---------------------------------------------------------------------------
bool Rook::ChekMove(Position APos,Board *ABoard)const
{

	return true;
}
//---------------------------------------------------------------------------
bool Pown::ChekMove(Position APos,Board *ABoard)const
{
if (Color()==true)
{
	if (APos.Row==Pos().Row-1&&APos.Col==Pos().Col)
	{

	}
}
	return true;
}
//---------------------------------------------------------------------------
bool King::ChekMove(Position APos, Board *ABoard)const
{
	return true;
}
//---------------------------------------------------------------------------
bool Queen::ChekMove(Position APos, Board *ABoard)const
{
	return true;
}
//---------------------------------------------------------------------------
bool Bishop::ChekMove(Position APos, Board *ABoard)const
{
	return true;
}
//---------------------------------------------------------------------------
bool Knight::ChekMove(Position APos, Board *ABoard)const
{
	return true;
}
//---------------------------------------------------------------------------
Board::Board() : BlackKing(0, 3), WhiteKing(7, 4), StalematCount(0)
{
	NewGame();
}
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
Board::~Board()
{
	ClearBoard();
}
//---------------------------------------------------------------------------
void Board::ChangeState()
{
	// �������� �� �����
	if (StalematCount >= 50)
	{
		// �����
		state = qsStalemat;
		return;
	}

	// �������� �����
	switch(state)
	{
		// ���� ��� �����
		case qsWhite:
			// ��������� ��� ������
			if (CheckShah(true))
				state = qsCheakBlack;
			else
				state = qsBlack;
		break;
		// ���� ��� ������
		case qsBlack:
			// ��������� ��� �����
			if (CheckShah(true))
				state = qsCheakWhite;
			else
				state = qsWhite;
		break;
		// ���� ������ ���
		case qsCheakBlack:
			// ��������� ���
			if (CheckShah(true))
				state = qsMateBlack;
			else
				state = qsWhite;
		break;
		// ���� ����� ���
		case qsCheakWhite:
			// ��������� ���
			if (CheckShah(false))
				state = qsMateWhite;
			else
				state = qsBlack;
		break;
	}
}
//---------------------------------------------------------------------------
//
bool Board::CheckShah(bool pColor)
{
	// ������
	return false;
	for (int row = 0; row < 8; row++)
		for (int col = 0; col < 8; col++)
			if (board[row][col] != NULL)
				// ���� ��� ���� ������
				if (board[row][col]->Color() == pColor)
					// ������� ������� ��� ������ ����������
					if (pColor == true)
						if (board[row][col]->ChekMove(BlackKing, this))
							return true;
					else
						if (board[row][col]->ChekMove(WhiteKing, this))
							return true;

	return false;
}
//---------------------------------------------------------------------------
void Board::NewGame() // ���������� ��������� �������
{
	// ��������� �������
	for(int i = 0; i < 8; i++)
		for(int j = 0; j < 8; j++)
			board[i][j] = NULL;

	// ����������� �����
	// ****************************
	// �����
	for (int i = 0; i < 8; i++) {
		// �����
		board[6][i] = new Pown(Position(6, i), true);
		// ������
		board[1][i] = new Pown(Position(1, i), false);
	}
	// �����
	// ****************************
	// �����
	board[7][0] = new Rook(Position(7,0), true);
	board[7][7] = new Rook(Position(7,7), true);
	// ������
	board[0][0] = new Rook(Position(0,0), false);
	board[0][7] = new Rook(Position(0,7), false);
	// ****************************
	// ����
	// ****************************
	// �����
	board[7][1] = new Knight(Position(7,1), true);
	board[7][6] = new Knight(Position(7,6), true);
	// ������
	board[0][1] = new Knight(Position(0,1), false);
	board[0][6] = new Knight(Position(0,6), false);
	// ****************************
	// ����
	// ****************************
	// �����
	board[7][2] = new Bishop(Position(7,2), true);
	board[7][5] = new Bishop(Position(7,5), true);
	// ������
	board[0][2] = new Bishop(Position(0,2), false);
	board[0][5] = new Bishop(Position(0,5), false);
	// ****************************
	// �����
	// ****************************
	// �����
	board[7][3] = new Queen(Position(7,3), true);
	// ������
	board[0][4] = new Queen(Position(0,4), false);
	// ****************************
	// ������
	// ****************************
	// �����
	board[7][4] = new King(BlackKing, true);
	// ������
	board[0][3] = new King(WhiteKing, false);
	// ****************************
	// ****************************

	// ��������� ����������� ����
	state = qsWhite;
}
//---------------------------------------------------------------------------
bool Board::CheckStalemat()const
{
	unsigned short int Count = 0;

	for (int row = 0; row < 8; row++)
		for (int col = 0; col < 8; col++)
			// ���� � ������ ��������� ������
			if (board[row][col] != NULL)
			{
				// ������, ����������
				if (board[row][col]->Type() == qsKing)
					continue;
				// ����, ����������� ������� �� 1
				// ���� ������� ������ 1, ���������� false
				else if (board[row][col]->Type() == qsBishop)
				{
					Count++;
					if (Count > 1)
						return false;
				}
				// �����, ����������� ������� �� 1
				// ���� ������� ������ 1, ���������� false
				else if (board[row][col]->Type() == qsRook)
				{
					Count++;
					if (Count > 1)
						return false;
                }
				// ����� ������ ������, ���������� false
				else
					return false;
            }
    // ����� (2 ������ � 1 ������ ������)
	return true;
}
//---------------------------------------------------------------------------
bool Board::Move(Position AStart, Position AEnd)
{
	// �������� �� ���, �����
	// ?
	if (state == qsMateWhite || state == qsMateBlack || state == qsStalemat)
		return true;

	// ����� ������
	// ****************************
	if(board[AStart.Row][AStart.Col] != NULL)
	{
		// ���� ���������� ���������, ������ �� ����������
		if (AStart.Row == AEnd.Row && AStart.Col == AEnd.Col)
			return true;
		// ���������� ������ ���� ������
		// ****************************
		if ((state == qsWhite || state == qsCheakWhite) 
			&& board[AStart.Row][AStart.Col]->Color() == false)
			return true;
		else if ((state == qsBlack || state == qsCheakBlack) 
				 && board[AStart.Row][AStart.Col]->Color() == true)
			return true;
		// ****************************

		// ���� ������� ������
		if (board[AStart.Row][AStart.Col]->Type() == qsKing)
			if (board[AEnd.Row][AEnd.Col] != NULL)
				// � ���� �����
				if (board[AEnd.Row][AEnd.Col]->Type() == qsRook
					&& board[AStart.Row][AStart.Col]->Color() == board[AEnd.Row][AEnd.Col]->Color())
				{
                    // �������� �� ������ ���
					// ������ ���������
				}

		// ��������� ����� �� ������ ������������� � ��������� �������
		if (board[AStart.Row][AStart.Col]->ChekMove(AEnd, this))
		{
			// ���� �������� ������� �������� ������
			if(board[AEnd.Row][AEnd.Col] != NULL)
			{
				// ���� ������ ���� ������
				// ?
				if (board[AStart.Row][AStart.Col]->Color() == board[AEnd.Row][AEnd.Col]->Color())
					return true;
				// ������ ����
				if (board[AEnd.Row][AEnd.Col]->Type() == qsKing)
					return true;
				delete board[AEnd.Row][AEnd.Col];

				// ��������� ������
				// ���������� ������� �����
				StalematCount = 0;

				// ���� �������� 2 ������ � 1 ������ ������, �����
				if (CheckStalemat()) {
					state = qsStalemat;
				}
			}

			// ���� ����������� ������, ������ ���������� WhiteKing, BlackKing
			// ���������� ����� ��� �������� ���� ������ ����� ����
			if (board[AStart.Row][AStart.Col]->Type() == qsKing)
			{
				if (board[AStart.Row][AStart.Col]->Color() == true)
				{
					WhiteKing.Row = AEnd.Row;
					WhiteKing.Col = AEnd.Col;
				}
				else
				{
					BlackKing.Row = AEnd.Row;
					BlackKing.Col = AEnd.Col;
                }
			}

			// ���� �������� ������
			// ���������� ������� �����
			if (board[AStart.Row][AStart.Col]->Type() == qsPown)
				StalematCount = 0;
			else
				StalematCount++;

			// ����������� ������
			board[AStart.Row][AStart.Col]->Move(AEnd);
			board[AEnd.Row][AEnd.Col] = board[AStart.Row][AStart.Col];
			board[AStart.Row][AStart.Col] = NULL;
		}
		// ������ ������
		else
		{
			return true;
		}

		// ������ ���
		ChangeState();
	}
	// ****************************
	return true;
}
//---------------------------------------------------------------------------
const Figure* Board::Get(int ARow, int ACol)const
{
	return board[ARow][ACol];
}
//---------------------------------------------------------------------------
GState Board::State()const { return state; }
//---------------------------------------------------------------------------
