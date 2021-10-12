#include <iostream>
#include "Date.h"

using namespace std;
using namespace exam;

int main(void) {
	int year;
	int month;
	int day;

	cout << "년도를 입력하세요: ";
	cin >> year;

	cout << "월을 입력하세요: ";
	cin >> month;

	cout << "일을 입력하세요: ";
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