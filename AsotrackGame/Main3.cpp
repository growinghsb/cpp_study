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

	for (size_t i = 0; i < 5; i++)
	{
		for (size_t j = 0; j < 5; j++)
		{
			// i * 5 = ������������ ���� ����, j = �ϳ��ϳ� ���� �ϸ鼭 �ش� ���� ���
			cout << board[i * 5 + j] << '\t';
		}
		cout << endl << endl;
	}
	cout << endl;
	// ������� �ʱ� ����

	while (true) {
		size_t inputNum;
		cout << "������� �Դϴ�." << endl << "1 ~ 25������ ������ �ϳ��� �Է��ϼ���!" << endl
			<< "���� �Ͻ÷��� '0' or ctrl + z �� �Է��ϼ���." << endl;
		cin >> inputNum;

		if (inputNum == 0 || cin.eof()) {
			cout << "������ ���� �մϴ�." << endl;
			break;
		}

		if (inputNum > 25 || cin.fail()) {
			cin.setstate(ios::failbit);
			cout << "�߸��� �Է� �Դϴ�. �ٽ� �Է��ϼ���" << endl;
			cin.clear();
			cin.ignore(LLONG_MAX, '/n');
			continue;
		}
	}

	return 0;
}