#include <iostream>
#include "Magician.h"

using namespace sample;
using namespace std;

int main(void) {
	Magician* magician = new Magician("Wizard of Teemo");
	
	cout << magician->GetName() << endl;
	magician->Attack();
	magician->UseEliteSkill();
	magician->OnDeath();

	delete magician;

	return 0;
}