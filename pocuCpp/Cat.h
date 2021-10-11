#pragma once

#include "Animal.h"

namespace sample {
	class Cat : public Animal {
	public:
		Cat(int age);

		virtual void Move()const;
		virtual void Speak() const;
	};

}