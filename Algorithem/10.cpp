/*
	n 을 입력 받는다. 횟수.
	n 개의 자연수가 입력되면 각 자연수의 자릿수의 합을 구한다.
	그 합 중 가장 큰 값의 자연수를 출력한다. 
	이 때 자릿수의 합이 중복된다면 큰 값의 자연수를 출력한다. 

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
