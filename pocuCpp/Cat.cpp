#include<iostream>
#include "Cat.h"

namespace sample {
	Cat::Cat(int age) 
		: Animal(age) 
	{
	}

	void Cat::Move() const {
		std::cout << "����̰� �����δ�." << std::endl;
	}

	void Cat::Speak() const {
		std::cout << "����̰� ���� �Ѵ�." << std::endl;
	}
}