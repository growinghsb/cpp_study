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

	Magician* magicians[] = { noneMagician, fireMagician };
	size_t len = sizeof(magicians) / sizeof(Magician*);

	for (size_t i = 0; i < len; i++)
	{
		cout << magicians[i]->GetName() << endl;
		magicians[i]->Attack();
		magicians[i]->UseEliteSkill();
		magicians[i]->OnDeath();
	}

	delete noneMagician;

	return 0;
}