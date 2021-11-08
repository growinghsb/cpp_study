#include <iostream>

using std::cout;
using std::cin;

int main(void)
{
	int num;
	cin >> num;

	int count = 0;
	for (unsigned int i = 1; i < num + 1; ++i)
	{
		int tmp = i; 

		while (tmp >= 1)
		{
			tmp *= 0.1f;
			++count;
		}
	}

	cout << count;
	return 0;
}