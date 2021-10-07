#include <iostream>
#include <iomanip>
#include "strFunc.h"

using namespace std;
static const size_t LENGTH = 128u;

size_t inputChoice(void) {
	size_t inputNum;

	while (true) {
		cout << "번호를 선택하세요: ";
		cin >> inputNum;
		cout << endl;
		cin.get();

		if (inputNum > 0 && inputNum < 5 || cin.eof()) {
			break;
		}

		cin.setstate(ios::failbit);
		if (cin.fail())
		{
			cout << "잘못된 입력 입니다. 다시 입력하세요." << endl << endl;
			choice();
			cin.clear();
			cin.ignore(LLONG_MAX, '\n');
			continue;
		}
	}
	return inputNum;
}

void choice(void) {
	cout << "문자열 관련 프로그램 입니다." << endl;
	cout << "1. 입력받은 문자열 대, 소문자 변경" << endl;
	cout << "2. 두 문자열 입력 후 비교" << endl;
	cout << "3. 문자열 입력 받아서 개수 세기" << endl;
	cout << "4. 문자열 입력 받은 후 뒤집기" << endl;
	cout << "끝내기(EOF): ctrl + z + enter" << endl;
	cout << endl;
}
void changeUpperandLower(void) {
	char str[LENGTH];

	cout << "문자열을 입력하세요: ";
	cin.getline(str, LENGTH);
	cout << endl;

	char* p = str;

	while (*p != '\0')
	{
		if (*p > 64 && *p < 91)
		{
			*p = *p + 32; // 대문자 -> 소문자
		}
		else if(*p > 96 && *p < 123)
		{
			*p = *p - 32; // 소문자 -> 대문자
		}
		p++;
	}

	cout << "변경된 문자열 : " << str << endl << endl;
}

void strCompare(void) {
	char str1[LENGTH];
	char str2[LENGTH];

	cout << "첫 번째 문자열을 입력하세요: ";
	cin.getline(str1, LENGTH);
	cout << endl;

	cout << "두 번째 문자열을 입력하세요: ";
	cin.getline(str2, LENGTH);
	cout << endl;

	char* p1 = str1;
	char* p2 = str2;

	while (true) {
		if (*p1 != *p2) {
			cout << *p1 << "과 " << *p2 << "가 다름으로 서로 다른 문자열 입니다." << endl << endl;
			return;
		}

		if (*p1 == '\0' && *p2 == '\0')
		{
			cout << str1 << "과 " << str2 << " 는" << "같은 문자열 입니다." << endl << endl;
			return;
		}
		p1++;
		p2++;
	}
}

void strCounting(void) {
	char str[LENGTH];

	cout << "문자열을 입력하세요: ";
	cin.getline(str, LENGTH);
	cout << endl;

	size_t length = 0;
	char* p = str;

	while (*p != '\0') {
		length++;
		p++;
	}

	cout << str << "의 문자 개수는 " << length << "개 입니다." << endl << endl;
}

void strReverse(void) {
	char str[LENGTH];

	cout << "문자열을 입력하세요: ";
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

	cout << "변경 후 => " << str << endl << endl;
}