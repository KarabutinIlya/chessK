//---------------------------------------------------------------------------

#ifndef engineH
#define engineH
#include <memory.h>
//---------------------------------------------------------------------------
enum GState
{
	qsWhite,							// ход белых
	qsBlack,                            // ход черных
	qsMateWhite,                        // мат белыми
	qsMateBlack,                        // мат черными
	qsStalemat,                         // ничья
	qsCheakWhite,                       // шах белым
	qsCheakBlack                        // шах черным
};
//---------------------------------------------------------------------------
enum GType
{
	qsPown,							   // пешка
	qsRook,                            // ладья
	qsKing,                            // король
	qsQueen,                           // ферзь
	qsBishop,                          // слон
	qsKnight,                          // конь
	none,                              // пусто
};

//---------------------------------------------------------------------------
class Position
{
	public:
		int Row; //строка
		int Col; //колонка
		Position(int ARow, int ACol);
};
//---------------------------------------------------------------------------
class Board; //предварительное объявление
//---------------------------------------------------------------------------
class Figure //базовый класс фигуры
{
		Position pos;    //позиция фигурки
		bool     color;  //цвет фигурки; 1 белые 0  черные
		GType type;       //тип фигуры

	public:
		Figure(Position APos, bool AColor, GType pType); // Конструктор с параметрами
		void Move(Position APos);           // Перемещение фигуры в позицию APos
		const Position& Pos()const;         // Позиция фигуры
		bool Color()const;                  // Цвет фигуры
        GType Type()const;                   // Тип фигуры
		virtual bool ChekMove(Position APos, Board *ABoard)const=0;
};
//---------------------------------------------------------------------------
class Rook:public Figure // ладья
{
	public:
		bool ChekMove(Position APos,Board *ABoard)const;
		Rook(Position APos, bool AColor);
};
//---------------------------------------------------------------------------
class Pown:public Figure // пешка
{
	public:
		bool ChekMove(Position APos, Board *ABoard)const;
		Pown(Position APos, bool AColor);
};
//---------------------------------------------------------------------------
class King:public Figure // король
{
	public:
		bool ChekMove(Position APos, Board *ABoard)const;
		King(Position APos, bool AColor);
};
//---------------------------------------------------------------------------
class Queen:public Figure // ферзь
{
	public:
		bool ChekMove(Position APos, Board *ABoard)const;
		Queen(Position APos, bool AColor);
};
//---------------------------------------------------------------------------
class Bishop:public Figure // слон
{
	public:
		bool ChekMove(Position APos, Board *ABoard)const;
		Bishop(Position APos, bool AColor);
};
//---------------------------------------------------------------------------
class Knight:public Figure // конь
{
	public:
		bool ChekMove(Position APos, Board *ABoard)const;
		Knight(Position APos, bool AColor);
};
//---------------------------------------------------------------------------
// класс доски с фигурами
class Board
{
	private:
		GState state; // состояние позиции
		Figure *board[8][8];
		void ClearBoard(); // очистка доски (удаление фигур)
		void ChangeState(); // изменить ход
		Position BlackKing; // позиция черного короля
		Position WhiteKing; // позиция белого короля
		unsigned short int StalematCount; // счетчик ничьи. Считает количество прошедших ходов
										  // с момента последнего хода пешкой или размена фигуры

	public:
		Board();
		~Board();
		void NewGame(); // растановка начальной позиции
		bool Move(Position AStart,Position AEnd);
		const Figure* Get(int ARow, int ACol)const;
		bool CheckShah(bool pColor); // функция проверки шаха королю
		bool CheckStalemat()const; // функция проверяет фигуры после размена
								   // возвращает true, если на поле 2 короля или
								   // 2 короля и 1 легкая фигура (слон или конь)
		GState State()const;
};
//---------------------------------------------------------------------------
#endif
