#include<windows.h>
#include"Puzzle.h"

using std::cin;

extern int score;

int main()
{
	srand(time(nullptr));

	Puzzle puzzle;

	while (true)
	{
		system("cls");

		cout << endl << "현재점수: " << score << "점" << endl << endl;
		puzzle.printPuzzle();

		int x = 0, y = 0;
		char direction = ' ';

		cout << "x: ";
		cin >> x;

		cout << "y: ";
		cin >> y;

		cout << "w: UP | s: DOWN | a: LEFT | d: RIGHT" << endl;
		cin >> direction;

		switch (direction) 
		{
		case 'w':
			if (puzzle.isMove(x, y, DIRECTION::UP)) 
			{
				puzzle.move(x, y, DIRECTION::UP);
			}
			break;

		case 's':
			if (puzzle.isMove(x, y, DIRECTION::DOWN))
			{
				puzzle.move(x, y, DIRECTION::DOWN);
			}
			break;

		case 'a':
			if (puzzle.isMove(x, y, DIRECTION::LEFT))
			{
				puzzle.move(x, y, DIRECTION::LEFT);
			}
			break;

		case 'd':
			if (puzzle.isMove(x, y, DIRECTION::RIGHT))
			{
				puzzle.move(x, y, DIRECTION::RIGHT);
			}
			break;

		default:
			break;
		}
	}

	return 0;
}
