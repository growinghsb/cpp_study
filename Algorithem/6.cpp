/*
	���ڿ� ���ڰ� ���� �ִ� ���ڿ��� �Է� �޽��ϴ�. 
	
	�� �� ���ڸ� ���� �ؼ� ���ڸ� ���� �մϴ�. 

	�� �� ù �ڸ��� 0�̶�� �� 0�� ������ �� �����մϴ�. 

	����� �� ������ ���ڸ� ù ��° �ٿ� ����ϰ�
	�̷��� ��µ� ������ ����� �� ��° �ٿ� ����մϴ�. 

	�Է�) effsnfo0dfoif1lkfjinc2odcnso 
	���) 12
		  6
*/

#include <iostream>

using std::cout;
using std::cin;
using std::endl;

int main6(void) {
	unsigned int const LENGTH = 50;
	char chArr[LENGTH + 1] = {0, };
	char* p = chArr;

	cin >> chArr;

	unsigned int result = 0;
	while (*p != '\0') {

		if (*p >= 48 && *p <= 57) { // 57 - 48 + 1 = 10 / 0 ~ 9
			result = result * 10 + (*p - 48);
		}
		p++;
	}

	unsigned int count = 0;
	for (unsigned int i = 1; i < result + 1; i++)
	{
		if (result % i == 0) {
			count++;
		}
	}

	cout << result << endl;
	cout << count;

	return 0;
}