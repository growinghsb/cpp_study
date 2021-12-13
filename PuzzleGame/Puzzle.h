#pragma once

#include<iostream>
#include<cassert>
#include<queue>

using std::wcout;
using std::cout;
using std::endl;
using std::queue;
using std::wostream;

/*
	enum class Direction
*/
enum class Direction
{
	UP,
	DOWN,
	RIGHT,
	LEFT,
};

/*
	class Cell
*/
class Cell
{
	friend class Puzzle;
	friend wostream& operator<<(wostream& os, Cell& rhs);

private:
	Cell() = default;
	~Cell() = default;

	int mX;
	int mY;
	wchar_t mFigure;
};

/*
	operator << func
*/
wostream& operator<<(wostream& os, Cell& rhs)
{
	return os << rhs.mFigure;
}

/*
	class Puzzle
*/
class Puzzle
{
public:
	Puzzle();

	void move(const int x, const int y, Direction direction);
	void printBoard();

private:
	bool isPossible(const int x, const int y)
	{
		if (x >= PUZZLE_BOARD_SIZE) 
		{
			return false;
		}
		
		if (x < 0) 
		{
			return false;
		}

		if (y >= PUZZLE_BOARD_SIZE) 
		{
			return false;
		}

		if (y < 0) 
		{
			return false;
		}

		return true;
	}
	
	void swap(Cell& target1, Cell& target2)
	{
		Cell tmp = target1;
		target1 = target2;
		target2 = tmp;
	}

	void figureCrossCheak(const int x, const int y);

	enum
	{
		PUZZLE_BOARD_SIZE = 5,
		FiGURE_SIZE = 5
	};

	Cell mBoard[PUZZLE_BOARD_SIZE][PUZZLE_BOARD_SIZE];
	wchar_t mFigure[FiGURE_SIZE];
};

Puzzle::Puzzle()
	: mBoard()
	, mFigure{ L'★',L'♥', L'◆', L'■', L'▲' }
{
	for (int i = 0; i < PUZZLE_BOARD_SIZE; ++i)
	{
		for (int j = 0; j < PUZZLE_BOARD_SIZE; ++j)
		{
			mBoard[j][i].mX = i;
			mBoard[j][i].mY = j;
			mBoard[j][i].mFigure = mFigure[rand() % 5];
		}
	}
}

void Puzzle::move(const int x, const int y, Direction direction)
{
	assert(x < PUZZLE_BOARD_SIZE&& y < PUZZLE_BOARD_SIZE&& x >= 0 && y >= 0);

	switch (direction)
	{
	case Direction::UP:

		if (isPossible(x, y - 1))
		{
			swap(mBoard[x][y], mBoard[x][y - 1]);
			figureCrossCheak(x, y - 1);
		}
		break;
	case Direction::DOWN:

		if (isPossible(x, y + 1))
		{
			swap(mBoard[x][y], mBoard[x][y + 1]);
			figureCrossCheak(x, y + 1);
		}
		break;
	case Direction::RIGHT:

		if (isPossible(x + 1, y))
		{
			swap(mBoard[x][y], mBoard[x + 1][y]);
			figureCrossCheak(x + 1, y);
		}
		break;
	case Direction::LEFT:

		if (isPossible(x - 1, y))
		{
			swap(mBoard[x][y], mBoard[x - 1][y]);
			figureCrossCheak(x - 1, y);
		}
		break;
	}
}

void Puzzle::printBoard()
{
	setlocale(LC_ALL, "");

	for (int i = 0; i < PUZZLE_BOARD_SIZE; ++i)
	{
		cout << "----------------" << endl;
		for (int j = 0; j < PUZZLE_BOARD_SIZE; ++j)
		{
			wcout << '|' << mBoard[j][i];
		}
		cout << '|' << endl;
	}
	cout << "----------------" << endl;
}

void Puzzle::figureCrossCheak(const int x, const int y)
{
	struct queueData 
	{
		Cell cell;
		Direction direction;
	};
	
	Cell cell = mBoard[x][y];
	queue<queueData> queue;

	/*
		자신을 기준으로 x + 1, x - 1, y + 1, y - 1
		값을 한 번씩 비교 후 같은 모양만 넣는다. 
		
		이 때 조건은 
		x or y 가 PUZZLE_SIZE 보다 작고
		0 보다 크며
		같은 도형만
		큐에 집어 넣는다. 
	*/
}
