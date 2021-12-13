#pragma once

#include<iostream>
#include<cassert>
#include<queue>
#include<stack>

using std::wcout;
using std::cout;
using std::endl;
using std::wostream;

using std::queue;
using std::stack;

// global variable score
int score = 0;

/*
	enum class Direction
*/
enum class DIRECTION
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

public:
	~Cell() = default;

private:
	Cell() = default;

	int mX;
	int mY;
	wchar_t mFigure;
};

/*
	class Puzzle
*/
class Puzzle
{
public:
	Puzzle();
	~Puzzle() = default;

	void printPuzzle();
	bool isMove(const int x, const int y, DIRECTION direction);
	void move(const int x, const int y, DIRECTION direction);

private:
	void swap(wchar_t& target1, wchar_t& target2)
	{
		wchar_t tmpFigure = target1;
		target1 = target2;
		target2 = tmpFigure;
	}

	void BoardSetting();
	void allCheckAndCrush();

	bool weightCheck(const int x, const int y, stack<Cell>& data);
	bool heightCheck(const int x, const int y, stack<Cell>& data);

	void weightCrush(stack<Cell>& data, const int y);
	void heightCrush(stack<Cell>& data);

	enum { BOARD_SIZE = 5, FIGURE_COUNT = 5 };
	Cell mBoard[BOARD_SIZE][BOARD_SIZE];
	wchar_t mFigures[FIGURE_COUNT];
};

/*
	Puzzle class func
*/
Puzzle::Puzzle()
	: mBoard()
	, mFigures{ L'け', L'し', L'せ', L'ぞ', L'そ', }
{
	BoardSetting();
	allCheckAndCrush();
	score = 0;
}

void Puzzle::printPuzzle()
{
	setlocale(LC_ALL, "");

	for (int i = 0; i < BOARD_SIZE; ++i)
	{
		cout << "----------------" << endl;
		for (int j = 0; j < BOARD_SIZE; ++j)
		{
			wcout << '*' << mBoard[i][j].mFigure;
		}
		cout << '*' << endl;
	}
	cout << "----------------" << endl;
}

bool Puzzle::isMove(const int x, const int y, DIRECTION direction)
{
	bool result = true;

	switch (direction)
	{
	case DIRECTION::UP:
		if (y - 1 < 0)
		{
			result = false;
		}
		break;

	case DIRECTION::DOWN:
		if (y + 1 >= BOARD_SIZE)
		{
			result = false;
		}
		break;

	case DIRECTION::RIGHT:
		if (x + 1 >= BOARD_SIZE)
		{
			result = false;
		}
		break;

	case DIRECTION::LEFT:
		if (x - 1 < 0)
		{
			result = false;
		}
		break;
	}

	return result;
}

void Puzzle::move(const int x, const int y, DIRECTION direction)
{
	stack<Cell> stack;

	switch (direction)
	{
	case DIRECTION::UP:
		swap(mBoard[y][x].mFigure, mBoard[y - 1][x].mFigure);

		if (weightCheck(x, y - 1, stack))
		{
			weightCrush(stack, y - 1);
		}

		if (heightCheck(x, y - 1, stack))
		{
			heightCrush(stack);
		}

		break;

	case DIRECTION::DOWN:
		swap(mBoard[y][x].mFigure, mBoard[y + 1][x].mFigure);

		if (weightCheck(x, y + 1, stack))
		{
			weightCrush(stack, y + 1);
		}

		if (heightCheck(x, y + 1, stack))
		{
			heightCrush(stack);
		}

		break;

	case DIRECTION::RIGHT:
		swap(mBoard[y][x].mFigure, mBoard[y][x + 1].mFigure);

		if (weightCheck(x + 1, y, stack))
		{
			weightCrush(stack, y);
		}

		if (heightCheck(x + 1, y, stack))
		{
			heightCrush(stack);
		}

		break;

	case DIRECTION::LEFT:
		swap(mBoard[y][x].mFigure, mBoard[y][x - 1].mFigure);
		if (weightCheck(x - 1, y, stack))
		{
			weightCrush(stack, y);
		}

		if (heightCheck(x - 1, y, stack))
		{
			heightCrush(stack);
		}

		break;
	}

	allCheckAndCrush();
}

void Puzzle::BoardSetting() 
{
	for (int i = 0; i < BOARD_SIZE; ++i)
	{
		for (int j = 0; j < BOARD_SIZE; ++j)
		{
			mBoard[i][j].mX = j;
			mBoard[i][j].mY = i;
			mBoard[i][j].mFigure = mFigures[rand() % 5];
		}
	}
}

void Puzzle::allCheckAndCrush()
{
	stack<Cell> stack;

	for (int i = 0; i < BOARD_SIZE; ++i) 
	{
		if (weightCheck(i , i, stack)) 
		{
			weightCrush(stack, i);
		}

		if (heightCheck(i , i, stack))
		{
			heightCrush(stack);
		}
	}
}

bool Puzzle::weightCheck(const int x, const int y, stack<Cell>& stack)
{
	for (int i = 0; i < BOARD_SIZE; ++i)
	{
		if (mBoard[y][i].mFigure == mBoard[y][i + 1].mFigure)
		{
			stack.push(mBoard[y][i]);
		}
		else
		{
			if (2 <= stack.size())
			{
				stack.push(mBoard[y][i]);
				return true;
			}
			if (0 != stack.size())
			{
				stack.pop();
			}
		}
	}
	return false;
}

bool Puzzle::heightCheck(const int x, const int y, stack<Cell>& stack)
{
	for (int i = 0; i < BOARD_SIZE; ++i)
	{
		if (mBoard[i][x].mFigure == mBoard[i + 1][x].mFigure)
		{
			stack.push(mBoard[i][x]);
		}
		else
		{
			if (2 <= stack.size())
			{
				stack.push(mBoard[i][x]);
				return true;
			}
			if (0 != stack.size())
			{
				stack.pop();
			}
		}
	}
	return false;
}

void Puzzle::weightCrush(stack<Cell>& stack, const int y)
{
	if (3 <= stack.size())
	{
		score += stack.size();

		while (!stack.empty())
		{
			int i = y;
			for (; i > 0; --i)
			{
				mBoard[i][stack.top().mX].mFigure = mBoard[i - 1][stack.top().mX].mFigure;
			}

			mBoard[i][stack.top().mX].mFigure = mFigures[rand() % 5];
			stack.pop();
		}
	}
}

void Puzzle::heightCrush(stack<Cell>& stack)
{
	if (3 <= stack.size())
	{
		score += stack.size();

		while (!stack.empty())
		{
			if (stack.top().mY - 3 >= 0)
			{
				mBoard[stack.top().mY][stack.top().mX].mFigure = mBoard[stack.top().mY - 3][stack.top().mX].mFigure;
			}
			else
			{
				mBoard[stack.top().mY][stack.top().mX].mFigure = mFigures[rand() % 5];
			}

			stack.pop();
		}
	}
}