#include <iostream>

using namespace std;

int main2(void) {
	size_t first;
	size_t second;
	size_t sum = 0;

	cout << "�� ���� �Է� �ϼ���: ";
	cin >> first >> second;

	for (size_t i = first; i < second + 1; i++)
	{	
		sum += i;

		if (i == second) {
			cout << i;
			continue;
		}
		
		cout << i << " + ";
	}
	cout << " = " << sum;
	return 0;
}