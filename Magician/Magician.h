#pragma once

namespace sample {
	class Attunement;
	class Magician {

	public:
		Magician(const char* name);
		~Magician();

		char* GetName()const;
		void SetAttunement(Attunement* const);
		void Attack()const;
		void UseEliteSkill();
		void OnDeath();

	private:
		char* mName;
		Attunement* mAttunement;
	};
}