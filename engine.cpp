//---------------------------------------------------------------------------

#pragma hdrstop

#include "engine.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
//---------------------------------------------------------------------------
Position::Position(int ARow, int ACol) : Row(ARow), Col(ACol){}
//---------------------------------------------------------------------------
void Figure::Move(Position APos)//ростановка
{
	pos = APos;
}
//---------------------------------------------------------------------------
const Position &Figure::Pos()const //Позиция фигуры
{
	return pos;
}
//---------------------------------------------------------------------------
bool Figure::Color()const//возврат цвета
{
	return color;
}
//---------------------------------------------------------------------------
GType Figure::Type()const//возврат типа
{
	return type;
}
//---------------------------------------------------------------------------
Figure::Figure(Position APos, bool AColor, GType pType)//конструктор с параметрами
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
void Board::ClearBoard() // очистка доски (удаление фигур)
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
	// проверка на ничью
	if (StalematCount >= 50)
	{
		// ничья
		state = qsStalemat;
		return;
	}

	// проверка ходов
	switch(state)
	{
		// если ход белых
		case qsWhite:
			// проверяем шах черным
			if (CheckShah(true))
				state = qsCheakBlack;
			else
				state = qsBlack;
		break;
		// если ход черных
		case qsBlack:
			// проверяем шах белым
			if (CheckShah(true))
				state = qsCheakWhite;
			else
				state = qsWhite;
		break;
		// если черным шах
		case qsCheakBlack:
			// проверяем мат
			if (CheckShah(true))
				state = qsMateBlack;
			else
				state = qsWhite;
		break;
		// если белым шах
		case qsCheakWhite:
			// проверяем мат
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
	// убрать
	return false;
	for (int row = 0; row < 8; row++)
		for (int col = 0; col < 8; col++)
			if (board[row][col] != NULL)
				// если это наша фигура
				if (board[row][col]->Color() == pColor)
					// пробуем сделать шах королю противника
					if (pColor == true)
						if (board[row][col]->ChekMove(BlackKing, this))
							return true;
					else
						if (board[row][col]->ChekMove(WhiteKing, this))
							return true;

	return false;
}
//---------------------------------------------------------------------------
void Board::NewGame() // растановка начальной позиции
{
	// обнуление матрицы
	for(int i = 0; i < 8; i++)
		for(int j = 0; j < 8; j++)
			board[i][j] = NULL;

	// расстановка фигур
	// ****************************
	// пешки
	for (int i = 0; i < 8; i++) {
		// белые
		board[6][i] = new Pown(Position(6, i), true);
		// черные
		board[1][i] = new Pown(Position(1, i), false);
	}
	// ладья
	// ****************************
	// белая
	board[7][0] = new Rook(Position(7,0), true);
	board[7][7] = new Rook(Position(7,7), true);
	// черная
	board[0][0] = new Rook(Position(0,0), false);
	board[0][7] = new Rook(Position(0,7), false);
	// ****************************
	// конь
	// ****************************
	// белый
	board[7][1] = new Knight(Position(7,1), true);
	board[7][6] = new Knight(Position(7,6), true);
	// черный
	board[0][1] = new Knight(Position(0,1), false);
	board[0][6] = new Knight(Position(0,6), false);
	// ****************************
	// слон
	// ****************************
	// белый
	board[7][2] = new Bishop(Position(7,2), true);
	board[7][5] = new Bishop(Position(7,5), true);
	// черный
	board[0][2] = new Bishop(Position(0,2), false);
	board[0][5] = new Bishop(Position(0,5), false);
	// ****************************
	// ферзь
	// ****************************
	// белый
	board[7][3] = new Queen(Position(7,3), true);
	// черный
	board[0][4] = new Queen(Position(0,4), false);
	// ****************************
	// король
	// ****************************
	// белый
	board[7][4] = new King(BlackKing, true);
	// черный
	board[0][3] = new King(WhiteKing, false);
	// ****************************
	// ****************************

	// установка очередности хода
	state = qsWhite;
}
//---------------------------------------------------------------------------
bool Board::CheckStalemat()const
{
	unsigned short int Count = 0;

	for (int row = 0; row < 8; row++)
		for (int col = 0; col < 8; col++)
			// если в клетке находится фигура
			if (board[row][col] != NULL)
			{
				// король, пропускаем
				if (board[row][col]->Type() == qsKing)
					continue;
				// слон, увеличиваем счетчик на 1
				// если счетчик больше 1, возвращаем false
				else if (board[row][col]->Type() == qsBishop)
				{
					Count++;
					if (Count > 1)
						return false;
				}
				// ладья, увеличиваем счетчик на 1
				// если счетчик больше 1, возвращаем false
				else if (board[row][col]->Type() == qsRook)
				{
					Count++;
					if (Count > 1)
						return false;
                }
				// любая другая фигура, возвращаем false
				else
					return false;
            }
    // ничья (2 короля и 1 легкая фигура)
	return true;
}
//---------------------------------------------------------------------------
bool Board::Move(Position AStart, Position AEnd)
{
	// проверка на мат, ничью
	// ?
	if (state == qsMateWhite || state == qsMateBlack || state == qsStalemat)
		return true;

	// выбор фигуры
	// ****************************
	if(board[AStart.Row][AStart.Col] != NULL)
	{
		// если координаты совпадают, фигуру не перемещаем
		if (AStart.Row == AEnd.Row && AStart.Col == AEnd.Col)
			return true;
		// перемещаем только свои фигуры
		// ****************************
		if ((state == qsWhite || state == qsCheakWhite) 
			&& board[AStart.Row][AStart.Col]->Color() == false)
			return true;
		else if ((state == qsBlack || state == qsCheakBlack) 
				 && board[AStart.Row][AStart.Col]->Color() == true)
			return true;
		// ****************************

		// если выбрали короля
		if (board[AStart.Row][AStart.Col]->Type() == qsKing)
			if (board[AEnd.Row][AEnd.Col] != NULL)
				// и свою ладью
				if (board[AEnd.Row][AEnd.Col]->Type() == qsRook
					&& board[AStart.Row][AStart.Col]->Color() == board[AEnd.Row][AEnd.Col]->Color())
				{
                    // проверка на первый ход
					// делаем рокировку
				}

		// проверяем может ли фигура переместиться в указанную позицию
		if (board[AStart.Row][AStart.Col]->ChekMove(AEnd, this))
		{
			// если конечная позиция содержит фигуру
			if(board[AEnd.Row][AEnd.Col] != NULL)
			{
				// свою фигуру бить нельзя
				// ?
				if (board[AStart.Row][AStart.Col]->Color() == board[AEnd.Row][AEnd.Col]->Color())
					return true;
				// короля тоже
				if (board[AEnd.Row][AEnd.Col]->Type() == qsKing)
					return true;
				delete board[AEnd.Row][AEnd.Col];

				// разменяли фигуру
				// сбрасываем счетчик ничьи
				StalematCount = 0;

				// Если осталось 2 короля и 1 легкая фигура, ничья
				if (CheckStalemat()) {
					state = qsStalemat;
				}
			}

			// если переместили короля, меняем координаты WhiteKing, BlackKing
			// координаты нужны для проверки шаха королю после хода
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

			// если походили пешкой
			// сбрасываем счетчик ничьи
			if (board[AStart.Row][AStart.Col]->Type() == qsPown)
				StalematCount = 0;
			else
				StalematCount++;

			// перемещение фигуры
			board[AStart.Row][AStart.Col]->Move(AEnd);
			board[AEnd.Row][AEnd.Col] = board[AStart.Row][AStart.Col];
			board[AStart.Row][AStart.Col] = NULL;
		}
		// пустая клетка
		else
		{
			return true;
		}

		// меняем ход
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
