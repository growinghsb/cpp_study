#include <iostream>
#include "Date.h"

using namespace std;
using namespace exam;

int main(void) {
	int year;
	int month;
	int day;

	cout << "�⵵�� �Է��ϼ���: ";
	cin >> year;

	cout << "���� �Է��ϼ���: ";
	cin >> month;

	cout << "���� �Է��ϼ���: ";
	cin >> day;

	cout << endl;

	Date date(year, month, day);
	date.ShowDate();
	
	date.AddDay(10);
	date.ShowDate();

	date.AddDay(9);
	date.ShowDate();

	date.AddDay(1);
	date.ShowDate();

	date.AddDay(29);
	date.ShowDate();

	date.AddDay(1);
	date.ShowDate();

	date.AddDay(30);
	date.ShowDate();

	date.AddDay(1);
	date.ShowDate();

	for (size_t i = 0; i < 100; i++)
	{
		date.AddDay(1);
		date.ShowDate();
	}

	return 0;
}