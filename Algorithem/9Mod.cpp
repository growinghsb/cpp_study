#include <iostream>
#include <cstring>

using namespace std;

int main09(void) {
	size_t num;
	cin >> num;

	int* p = new int[num];
	memset(p, 0, sizeof(int) * num);

	int* tmp;
	for (size_t i = 1; i < num + 1; i++)
	{
		tmp = p + i - 1;
		for (size_t j = i; j < num + 1; j += i)
		{
			*tmp += 1;
			tmp += i;
		}
	}

	for (size_t i = 0; i < num; i++)
	{
		cout << *(p + i) << ' ';
	}
	delete[] p;

	return 0;
}