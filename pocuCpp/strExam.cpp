#include <iostream>
#include <iomanip>
#include "strFunc.h"

using namespace std;
static const size_t LENGTH = 128u;

size_t inputChoice(void) {
	size_t inputNum;

	while (true) {
		cout << "��ȣ�� �����ϼ���: ";
		cin >> inputNum;
		cout << endl;
		cin.get();

		if (inputNum > 0 && inputNum < 5 || cin.eof()) {
			break;
		}

		cin.setstate(ios::failbit);
		if (cin.fail())
		{
			cout << "�߸��� �Է� �Դϴ�. �ٽ� �Է��ϼ���." << endl << endl;
			choice();
			cin.clear();
			cin.ignore(LLONG_MAX, '\n');
			continue;
		}
	}
	return inputNum;
}

void choice(void) {
	cout << "���ڿ� ���� ���α׷� �Դϴ�." << endl;
	cout << "1. �Է¹��� ���ڿ� ��, �ҹ��� ����" << endl;
	cout << "2. �� ���ڿ� �Է� �� ��" << endl;
	cout << "3. ���ڿ� �Է� �޾Ƽ� ���� ����" << endl;
	cout << "4. ���ڿ� �Է� ���� �� ������" << endl;
	cout << "������(EOF): ctrl + z + enter" << endl;
	cout << endl;
}
void changeUpperandLower(void) {
	char str[LENGTH];

	cout << "���ڿ��� �Է��ϼ���: ";
	cin.getline(str, LENGTH);
	cout << endl;

	char* p = str;

	while (*p != '\0')
	{
		if (*p > 64 && *p < 91)
		{
			*p = *p + 32; // �빮�� -> �ҹ���
		}
		else if(*p > 96 && *p < 123)
		{
			*p = *p - 32; // �ҹ��� -> �빮��
		}
		p++;
	}

	cout << "����� ���ڿ� : " << str << endl << endl;
}

void strCompare(void) {
	char str1[LENGTH];
	char str2[LENGTH];

	cout << "ù ��° ���ڿ��� �Է��ϼ���: ";
	cin.getline(str1, LENGTH);
	cout << endl;

	cout << "�� ��° ���ڿ��� �Է��ϼ���: ";
	cin.getline(str2, LENGTH);
	cout << endl;

	char* p1 = str1;
	char* p2 = str2;

	while (true) {
		if (*p1 != *p2) {
			cout << *p1 << "�� " << *p2 << "�� �ٸ����� ���� �ٸ� ���ڿ� �Դϴ�." << endl << endl;
			return;
		}

		if (*p1 == '\0' && *p2 == '\0')
		{
			cout << str1 << "�� " << str2 << " ��" << "���� ���ڿ� �Դϴ�." << endl << endl;
			return;
		}
		p1++;
		p2++;
	}
}

void strCounting(void) {
	char str[LENGTH];

	cout << "���ڿ��� �Է��ϼ���: ";
	cin.getline(str, LENGTH);
	cout << endl;

	size_t length = 0;
	char* p = str;

	while (*p != '\0') {
		length++;
		p++;
	}

	cout << str << "�� ���� ������ " << length << "�� �Դϴ�." << endl << endl;
}

void strReverse(void) {
	char str[LENGTH];

	cout << "���ڿ��� �Է��ϼ���: ";
	cin.getline(str, LENGTH);
	cout << endl;

	char* start = str;
	char* end = start + (strlen(str) - 1);

	while (start < end) {
		char tmp = *start;
		*start = *end;
		*end = tmp;

		start++;
		end--;
	}

	cout << "���� �� => " << str << endl << endl;
}