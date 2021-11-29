#include <iostream>

using std::cout;
using std::cin;
using std::endl;

struct Student {
	char name[10] = {};
	unsigned int kor;
	unsigned int math;
	unsigned int eng;
	unsigned int avg;
};

void Print(Student* students, int count);

int mainSSort()
{
	int count;
	cin >> count;
	cin.ignore(UINT_MAX, '\n');

	Student* students = (Student*)malloc(sizeof(Student) * count);

	if (students != nullptr)
	{
		for (unsigned int i = 0; i < count; ++i)
		{
			cout << "이름: ";
			cin.getline((students + i)->name, 9);

			cout << "국어: ";
			cin >> (students + i)->kor;

			cout << "수학: ";
			cin >> (students + i)->math;

			cout << "영어: ";
			cin >> (students + i)->eng;

			cin.ignore(UINT_MAX, '\n');
			cout << endl;

			(students + i)->avg = ((students + i)->kor + (students + i)->math + (students + i)->eng) / 3;
		}
		Print(students, count);
	}
	else
	{
		exit(0);
	}
	return 0;
}

void Print(Student* students, int count)
{
	for (unsigned int i = 0; i < count; ++i)
	{
		cout << "이름: " << (students + i)->name << " | ";
		cout << "국어: " << (students + i)->kor << " | ";
		cout << "수학: " << (students + i)->math << " | ";
		cout << "영어: " << (students + i)->eng << " | ";
		cout << "평균: " << (students + i)->avg;

		cout << endl;
	}
}
