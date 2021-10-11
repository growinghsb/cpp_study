#pragma once

#include "Attunement.h"
#include "Magician.h"

namespace sample {
	class None : public Attunement {

	public :
		None(Magician* const magician);
		
		virtual void OnEntry()const;
		virtual void Attack()const;
		virtual void UseEliteSkill(const size_t)const;
		virtual void OnDeath()const;
	};
}