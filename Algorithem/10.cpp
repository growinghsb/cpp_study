/*
	일의자리부터 나머지 연산과 나눗셈 연산을 통해
	추출해 더해 나간다. int digit_sum(int x) 함수를
	만들어 이를 구현해 놓는다. 
	반환 값은 정수의 각 자릿수를 더한 값이다. 

	반환값을 가지고 이전 반환값과 비교하고, 만약 
	반환값이 같다면, 실제 정수를 비교해서 더 큰 정수를
	가장 큰 값으로 선정한다.
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
