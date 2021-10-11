#include<cstring>

#include "None.h"

namespace sample {
	Magician::Magician(const char* name) 
	{
		size_t len = strlen(name) + 1;
		mName = new char[len];
		strcpy_s(mName, len, name);

		mAttunement = new None(this);
	}

	Magician::~Magician() {
		delete[] mName;
		delete mAttunement;
	}

	char* Magician::GetName()const {
		return mName;
	}

	void Magician::SetAttunement(Attunement* const attunement) 
	{
		mAttunement = attunement;
		attunement->OnEntry();
	}

	void Magician::Attack()const 
	{
		mAttunement->Attack();
	}

	void Magician::UseEliteSkill() {
		mAttunement->UseEliteSkill(90);
	}

	void Magician::OnDeath() {
		mAttunement->OnDeath();
	}
}