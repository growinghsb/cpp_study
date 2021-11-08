#include <iostream>

using namespace std;

int main2(void) {
	size_t first;
	size_t second;
	size_t sum = 0;

	cout << "두 수를 입력 하세요: ";
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