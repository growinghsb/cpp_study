/*
	ó�� �Է��� �� �� ���� �Է��� ���� �� ����� �Է� �޴´�
	
	�� ��° �Է� ���ʹ� �� ������ ��ŭ ���̸� �Է� �޴´�

	��) 10
	    13 45 23 87 25 54 55 12 21 76

	�׸��� �� �� ���� �������̰� ���� ���� ��� �� ����
	���̰� ������ ����ϴ� ���α׷��� �ۼ��ϸ� �˴ϴ�. 

	�� ���� � ���̴� 12���̰�, ���� ���� ���̴� 87 �̹Ƿ�
	87 - 12 �ϸ� 75 ��� ���� ��� �Ǹ� �˴ϴ�.
*/

#include <iostream>

using std::cout;
using std::cin;
using std::endl;

int main4(void) {
	size_t const LENGTH = 100;
	size_t arr[LENGTH] = {};
	size_t size;

	cin >> size;

	for (size_t i = 0; i < size; i++)
	{
		cin >> arr[i];
	}

	size_t min = arr[0];
	size_t max = arr[0];

	for (size_t i = 1; i < size; i++) {
		if (arr[i] < min) {
			min = arr[i];
			continue;
		}

		if (arr[i] > max) {
			max = arr[i];
		}
	}
	cout << max - min << endl;
	return 0;
}