#pragma once

namespace sample {
	class Magician;
	class Attunement {
	public:

		Attunement(Magician* const magician);
		virtual ~Attunement();

		virtual void OnEntry()const = 0;
		virtual void Attack()const = 0;
		virtual void UseEliteSkill(const size_t)const = 0;
		virtual void OnDeath()const = 0;


	protected:
		Magician* mMagician;
	};
}