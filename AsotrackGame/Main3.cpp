#include <iostream>
#include <time.h>

using namespace std;

int main(void) {
	const size_t LENGTH = 25;
	size_t board[LENGTH] = {};

	for (size_t i = 0; i < LENGTH; i++)
	{
		board[i] = i + 1;
	}

	srand(static_cast<unsigned int> (time(0)));
	size_t idx1, idx2, tmp;

	for (size_t i = 0; i < 100; i++)
	{
		idx1 = rand() % 25;
		idx2 = rand() % 25;

		tmp = board[idx1];
		board[idx1] = board[idx2];
		board[idx2] = tmp;
	}

	while (true) {
		system("cls");

		for (size_t i = 0; i < 5; i++)
		{
			for (size_t j = 0; j < 5; j++)
			{
				if (board[i * 5 + j] == 42) {
					cout << '*' << '\t';
					continue;
				}
				// i * 5 = 시작지점이자 행을 지정, j = 하나하나 증가 하면서 해당 열을 출력
				cout << board[i * 5 + j] << '\t';
			}
			cout << endl << endl;
		}
		cout << endl;
		// 여기까지 초기 세팅
		
		size_t inputNum;
		cout << "빙고게임 입니다." << endl << "1 ~ 25까지의 숫자중 하나를 입력하세요!" << endl
			<< "종료 하시려면 ctrl + z 를 입력하세요." << endl;
		cin >> inputNum;

		if (cin.eof()) {
			cout << "게임을 종료 합니다." << endl;
			break;
		}

		if (inputNum == 0 || inputNum > 25) {
			cin.setstate(ios::failbit);
			cin.clear();
			cin.ignore(UINT32_MAX, '\n'); // 첫 번째 매개변수 값이 너무 크면 에러가 난다. ULLONG_MAX 값으로 했을 때 에러가 났다.
			continue;
		}
		cout << endl;

		for (size_t i = 0; i < LENGTH; i++)
		{
			if (inputNum == board[i]) {
				board[i] = '*';
				break;
			}
		}
	}
	return 0;
}