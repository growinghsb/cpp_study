#include<windows.h>
#include"Puzzle.h"

using std::cin;

int main()
{
	srand(time(nullptr));

	Puzzle puzzle;

	while (true)
	{
		system("cls");

		puzzle.printBoard();

		int x = 0, y = 0;
		char direction = ' ';

		cout << "x: ";
		cin >> x;

		cout << "y: ";
		cin >> y;

		cout << "w: UP | s: DOWN | a: LEFT | d: RIGHT" << endl;
		cin >> direction;

		if (direction == 'w')
		{
			puzzle.move(x, y, Direction::UP);
		}

		if (direction == 's')
		{
			puzzle.move(x, y, Direction::DOWN);
		}

		if (direction == 'd')
		{
			puzzle.move(x, y, Direction::RIGHT);
		}

		if (direction == 'a')
		{
			puzzle.move(x, y, Direction::LEFT);
		}

	}

	return 0;
}
