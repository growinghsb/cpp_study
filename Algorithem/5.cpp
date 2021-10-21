#include <iostream>

using namespace std;

int main5(void) {
	size_t const LENGTH = 15;
	char idenNum[LENGTH] = {};

	cin >> idenNum;

	char sex = 0;
	size_t age = 0;

	switch (idenNum[7] - 48)
	{
	case 1:
		age = 2020 - (1900 + ((idenNum[0] - 48) * 10) + (idenNum[1] - 48));
		sex = 'M';
		break;
	case 3:
		age = 2020 - (2000 + ((idenNum[0] - 48) * 10) + (idenNum[1] - 48));
		sex = 'M';
		break;
	case 2:
		age = 2020 - (1900 + ((idenNum[0] - 48) * 10) + (idenNum[1] - 48));
		sex = 'W';
		break;
	case 4:
		age = 2020 - (1900 + ((idenNum[0] - 48) * 10) + (idenNum[1] - 48));
		sex = 'W';
		break;
	}
	cout << age << " " << sex;

	return 0;
}