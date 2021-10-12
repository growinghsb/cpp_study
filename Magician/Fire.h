#pragma once

#include "Attunement.h"
#include "Magician.h"

namespace sample {
	class Fire : public Attunement {

	public :
		Fire(Magician* const magician);

		virtual void OnEntry()const;
		virtual void Attack()const;
		virtual void UseEliteSkill(const size_t)const;
		virtual void OnDeath()const;
	};
}
