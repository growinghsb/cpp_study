/*
	���ڸ� �ϳ� �Է� �޴´�. 
	1 ~ �Է� ���� ���ھȿ� �� ���� ���ڰ� ������� ����.
	�̸� ��ȯ�Ѵ�. 

	ex)		15: 1,2,3,4,5,6,7,8,9,1,0,1,1,1,2,1,3,1,4,1,5
	result) 21
*/

#include <iostream>

using std::cout;
using std::cin;

int main11(void)
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