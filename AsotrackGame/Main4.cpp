#include <iostream>
#include <cstring>
#include <conio.h>

using namespace std;
static const size_t ROW = 20;
static const size_t COL = 21;

void setMaze(char[][COL]);

int main(void) {
	char maze[ROW][COL] = {}; // \0
	setMaze(maze);

	for (size_t i = 0; i < ROW; i++)
	{
		for (size_t j = 0; j < ROW; j++)
		{
			if (*(*(maze + i) + j) == '0') { 
				cout << "■";
				continue; 
			}
			if (*(*(maze + i) + j) == '1') {
				cout << "  ";
				continue;
			}
			if (*(*(maze + i) + j) == '2') {
				cout << "☆";
				continue;
			}
			if (*(*(maze + i) + j) == '3') {
				cout << "○";
				continue;
			}
		}
		cout << endl;
	}
	return 0;
}

// 0 - 벽
// 1 - 길
// 2 - 유저
// 3 - 도착점
void setMaze(char maze[][COL]) {
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
	strncpy_s(*(maze + 10), "00001000100001000000", COL);
	strncpy_s(*(maze + 11), "00001000100001111100", COL);
	strncpy_s(*(maze + 12), "00001111100000000100", COL);
	strncpy_s(*(maze + 13), "00001000000011111000", COL);
	strncpy_s(*(maze + 14), "11111000000010001000", COL);
	strncpy_s(*(maze + 15), "00001000000010000000", COL);
	strncpy_s(*(maze + 16), "00001111100110001000", COL);
	strncpy_s(*(maze + 17), "00000100000010000000", COL);
	strncpy_s(*(maze + 18), "00000100111111100000", COL);
	strncpy_s(*(maze + 19), "00000111100000111113", COL);
}