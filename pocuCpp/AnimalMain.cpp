#include <iostream>

#include "Animal.h"
#include "Cat.h"

using namespace sample;
using namespace std;

int main(void) {
	Animal* animal = new Animal(6);

	Animal* myCat = new Cat(2);
	Cat* meCat = new Cat(4);
	
	cout << animal->GetAge() << endl;
	animal->Move();
	animal->Speak();

	cout << myCat->GetAge() << endl;
	myCat->Move();
	myCat->Speak();

	cout << meCat->GetAge() << endl;
	meCat->Move();
	meCat->Speak();

	delete myCat;
	delete meCat;
	delete animal;

	return 0;
}