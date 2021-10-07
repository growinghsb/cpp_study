#include <iostream>
using namespace std;

int mainHello()
{
	int num;
	int sum = 0;

	while (true)
	{
		std::cout << "input number and EOF is quit:";
		std::cin >> num;

		if (std::cin.eof())
		{
			break;
		}

		if (std::cin.fail())
		{
			cout << "invalid input" << endl;
			cin.clear();
			cin.ignore(LLONG_MAX, '\n');
			continue;
		}
		sum += num;
	}
	cin.clear();
	
	cout << "sum is " << sum;
	
	return 0;
}


