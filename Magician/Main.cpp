#include <iostream>

#include "Magician.h"
#include "Fire.h"
#include "None.h"

using namespace sample;
using namespace std;

int main(void) {
	Magician* noneMagician = new Magician("Wizard of Teemo");
	noneMagician->SetAttunement(new None(noneMagician));

	Magician* fireMagician = new Magician("Wizard of Anie");
	fireMagician->SetAttunement(new Fire(fireMagician));

	Magician** magicians = new Magician*[2];
	magicians[0] = noneMagician;
	magicians[1] = fireMagician;

	for (size_t i = 0; i < 2; i++)
	{
		cout << (*(magicians + i))->GetName() << endl;
		(*(magicians + i))->Attack();
		(*(magicians + i))->UseEliteSkill();
		(*(magicians + i))->OnDeath();
	}

	delete noneMagician;
	delete fireMagician;
	delete[] magicians;

	return 0;
}