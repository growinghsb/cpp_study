/*
�Է�:
���ڿ��� �Է� �޴´�. 
���� ���� 100 ���ڰ� ���� �ʵ��� �Ѵ�. 
���ĺ� ��, �ҹ���, ������ �Է� �޴´�.

���: 
�Է� ���� ���ڿ����� ������ �����ϰ� �빮�ڸ� �ҹ��ڷ� �����Ѵ�.
�ϼ��� ���ڿ��� ����Ѵ�.

����:
�Է� - B  e  A     uT   I    FU  L
��� - beautiful
*/

#include <iostream>

using namespace std;

int main7(void) {
	size_t const LENGTH = 100;
	char input[LENGTH] = {};
	char* bp = input;
	char* cp = input;

	cin.getline(input, LENGTH - 1, '\n');

	while (*bp != '\0') {
		if (*cp == ' ') {
			cp++;
			continue;
		}

		*bp = *cp;
		*bp = *bp | 0x20; // �빮�ڸ� �ҹ��ڷ� �ٲٴ� ��Ʈ����ŷ? ��Ʈ ����?
		/*
			*bp = A = 65 = 0100 0001(64 + 1 = 65)
			0x20 = 32 = 0010 0000

			65 = 0100 0001
			32 = 0010 0000
			     0110 0001
			1 + 32 + 64 = 97 = 'a'				
		*/

		bp++;
		cp++;
	}
	cout << input;
	return 0;
}