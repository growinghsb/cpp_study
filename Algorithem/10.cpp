/*
	n �� �Է� �޴´�. Ƚ��.
	n ���� �ڿ����� �ԷµǸ� �� �ڿ����� �ڸ����� ���� ���Ѵ�.
	�� �� �� ���� ū ���� �ڿ����� ����Ѵ�. 
	�� �� �ڸ����� ���� �ߺ��ȴٸ� ū ���� �ڿ����� ����Ѵ�. 

	ex)		 3, 137 460 603 731
	result ) 731 
*/

#include <iostream>

using std::cout;
using std::cin;
using std::endl;

int digit_sum(int x);

int main10(void) 
{
	int count;
	int num;
	int result = 0;
	int max = 0;

	cin >> count;

	for (unsigned int i = 0; i < count; i++)
	{
		cin >> num;
		int tmp = digit_sum(num);

		if (max < tmp)
		{
			max = tmp;
			result = num;
		}
		else if (max == tmp) 
		{	
			if (result < num) 
			{
				result = num;
			}
		}
	}
	cout << result;

	return 0;
}

int digit_sum(int x)
{
	int sum = 0;
	while (x > 0) 
	{
		sum += (x % 10);
		x = x / 10;
	}
	return sum;
}
