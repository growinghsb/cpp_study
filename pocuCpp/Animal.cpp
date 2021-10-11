#include<iostream>
#include "Animal.h"

namespace sample {
	Animal::Animal(int age) 
		: mAge(age)
	{
	}

	void Animal::Move()const {
		std::cout << "동물이 움직인다" << std::endl;
	}

	void Animal::Speak()const {
		std::cout << "동물이 소리낸다" << std::endl;
	}
	
	int Animal::GetAge()const {
		return mAge;
	}

	Animal::~Animal() {}
}