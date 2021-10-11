#include<iostream>
#include "Animal.h"

namespace sample {
	Animal::Animal(int age) 
		: mAge(age)
	{
	}

	void Animal::Move()const {
		std::cout << "������ �����δ�" << std::endl;
	}

	void Animal::Speak()const {
		std::cout << "������ �Ҹ�����" << std::endl;
	}
	
	int Animal::GetAge()const {
		return mAge;
	}

	Animal::~Animal() {}
}