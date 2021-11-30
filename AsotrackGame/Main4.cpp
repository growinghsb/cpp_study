#include <iostream>
#include <cstring>
#include <conio.h>

struct player {
	int x = 0;
	int y = 0;
	size_t count = 0;
	bool finish = false;
};

typedef player PLAYER;
typedef player* PPOINTER;

using namespace std;
static const size_t ROW = 20;
static const size_t COL = 21;

void SetMaze(char[][COL], PPOINTER);
void PrintMaze(const char[][COL], PPOINTER);
void Move(char, PPOINTER, const char[][COL]);
void MoveRight(PPOINTER, const char[][COL]);
void MoveLeft(PPOINTER, const char[][COL]);
void MoveUp(PPOINTER, const char[][COL]);
void MoveDown(PPOINTER, const char[][COL]);



int main4(void) {
	PLAYER player;
	char maze[ROW][COL] = {};
	
	SetMaze(maze, &player);

	while (true) {
		system("cls");

		PrintMaze(maze, &player);
		char input = _getch();
		player.count++;

		if (input == 'q') {
			cout << "게임을 종료 합니다." << endl;
			break;
		}

		if (player.finish == true) {
			cout << player.count <<"번 시도, 탈출 성공!!! 게임 끝!!!";
			break;
		}

		Move(input, &player, maze);
	}
	return 0;
}

void Move(char input, PPOINTER player, const char maze[][COL]) {
	switch (input)
	{
	case 'a':
	case 'A':
		MoveLeft(player, maze);
		break;
	case 'w':
	case 'W':
		MoveUp(player, maze);
		break;
	case 's':
	case 'S':
		MoveDown(player, maze);
		break;
	case 'd':
	case 'D':
		MoveRight(player, maze);
		break;
	}
}

void MoveRight(PPOINTER player, const char maze[][COL]) {
	if (player->x + 1 < COL - 1 && maze[player->y][player->x + 1] != '0') {
		player->x += 1;
	}
}

void MoveLeft(PPOINTER player, const char maze[][COL]) {
	if (player->x - 1 > -1 && maze[player->y][player->x - 1] != '0') {
		player->x -= 1;
	}
}

void MoveUp(PPOINTER player, const char maze[][COL]) {
	if (player->y - 1 > -1 && maze[player->y - 1][player->x] != '0') {
		player->y -= 1;
	}
}

void MoveDown(PPOINTER player, const char maze[][COL]) {
	if (player->y + 1 < ROW && maze[player->y + 1][player->x] != '0') {
		player->y += 1;
	}
}

void PrintMaze(const char maze[][COL], PPOINTER player) {
	for (size_t i = 0; i < ROW; i++)
	{
		for (size_t j = 0; j < ROW; j++)
		{
			if (*(*(maze + i) + j) == '0') {
				cout << "■";
				continue;
			}
			if (*(*(maze + i) + j) == '1') {
				if (i == player->y && j == player->x) {
					cout << "＠";
				}
				else {
					cout << "  ";
				}
				continue;
			}
			if (*(*(maze + i) + j) == '2') {
				cout << "☆";
				continue;
			}
			if (*(*(maze + i) + j) == '3') {
				if (i == player->y && j == player->x) {
					player->finish = true;
				}
				cout << "○";
				continue;
			}
		}
		cout << endl;
	}
	cout << endl;
	cout << "a 왼쪽, w 위, d 오른쪽, s 아래, q 종료" << endl;
}

// 0 - 벽
// 1 - 길
// 2 - 유저
// 3 - 도착점
void SetMaze(char maze[][COL], PPOINTER player) {
	player->x = 0;
	player->y = 0;

	strncpy_s(*(maze + 0),  "21111111111000000000", COL);
	strncpy_s(*(maze + 1),  "00101001001111110000", COL);
	strncpy_s(*(maze + 2),  "00101101111100010000", COL);
	strncpy_s(*(maze + 3),  "00100001000000010000", COL);
	strncpy_s(*(maze + 4),  "00100001111000011111", COL);
	strncpy_s(*(maze + 5),  "00100000001000010000", COL);
	strncpy_s(*(maze + 6),  "00100000101110010000", COL);
	strncpy_s(*(maze + 7),  "00100000101010010000", COL);
	strncpy_s(*(maze + 8),  "00111000101000000000", COL);
	strncpy_s(*(maze + 9),  "00001100111111110000", COL);
	strncpy_s(*(maze + 10), "00001000101001000000", COL);
	strncpy_s(*(maze + 11), "00111000101001111100", COL);
	strncpy_s(*(maze + 12), "00001111100000001000", COL);
	strncpy_s(*(maze + 13), "00001000100011111000", COL);
	strncpy_s(*(maze + 14), "11111000111000001000", COL);
	strncpy_s(*(maze + 15), "00001000000000001000", COL);
	strncpy_s(*(maze + 16), "00001111100110001111", COL);
	strncpy_s(*(maze + 17), "00000100000010000001", COL);
	strncpy_s(*(maze + 18), "00000000111110000001", COL);
	strncpy_s(*(maze + 19), "00000011100000001113", COL);
}