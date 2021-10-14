#define _CRT_NONSTDC_NO_WARNINGS

#include <iostream>
#include <time.h>
#include <conio.h>

using namespace std;

int main(void) {
	int starLoc = 24; // * 의 위치값, 처음은 24
	int pre = 24;
	srand(static_cast<unsigned int>(time(0)));

	const size_t LENGTH = 25u;
	size_t arr[LENGTH] = {};
	size_t idx1, idx2, tmp;

	for (size_t i = 0; i < LENGTH - 1; i++)
	{
		arr[i] = i + 1;
	}

	while (true) {
		system("cls");
		cout << "위치: " << starLoc << endl << endl;

		for (size_t i = 0; i < 100; i++)
		{
			idx1 = rand() % 24;
			idx2 = rand() % 24;

			if (idx1 != pre && idx2 != pre) {
				tmp = arr[idx1];
				arr[idx1] = arr[idx2];
				arr[idx2] = tmp;
			}
		}
		tmp = arr[starLoc];
		arr[starLoc] = arr[pre];
		arr[pre] = tmp;

		pre = starLoc;

		for (size_t i = 0; i < 25; i++)
		{
			if (i != 0 && i % 5 == 0) {
				cout << endl;
				cout << endl;
			}

			if (i == starLoc) {
				cout << '*' << '\t';
				continue;
			}
			cout << arr[i] << '\t';
		}
		cout << endl;
		cout << endl;

		cout << "w 위, a 좌, d 우, s 아래, q 종료" << endl;
		char input = getch();

		if (input == 'q') {
			break;
		}

		switch (input) {
		case 'a':
		case 'A':
			if (starLoc - 1 >= 0) {
				starLoc -= 1;
			}
			break;
		case 'w':
		case 'W':
			if (starLoc - 5 >= 0) {
				starLoc -= 5;
			}
			break;
		case 'd':
		case 'D':
			if (starLoc + 1 <= 24) {
				starLoc += 1;
			}
			break;
		case 's':
		case 'S':
			if (starLoc + 5 <= 24) {
				starLoc += 5;
			}
			break;
		default:
			cout << "다시 입력하세요" << endl;
			break;
		}
	}
	return 0;
}