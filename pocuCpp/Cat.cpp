#include<iostream>
#include "Cat.h"

namespace sample {
	Cat::Cat(int age) 
		: Animal(age) 
	{
	}

	void Cat::Move() const {
		std::cout << "고양이가 움직인다." << std::endl;
	}

	void Cat::Speak() const {
		std::cout << "고양이가 말을 한다." << std::endl;
	}
}