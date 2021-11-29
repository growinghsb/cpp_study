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
			cout << "�̸�: ";
			cin.getline((students + i)->name, 9);

			cout << "����: ";
			cin >> (students + i)->kor;

			cout << "����: ";
			cin >> (students + i)->math;

			cout << "����: ";
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
		cout << "�̸�: " << (students + i)->name << " | ";
		cout << "����: " << (students + i)->kor << " | ";
		cout << "����: " << (students + i)->math << " | ";
		cout << "����: " << (students + i)->eng << " | ";
		cout << "���: " << (students + i)->avg;

		cout << endl;
	}
}
