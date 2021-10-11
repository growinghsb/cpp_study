#include <iostream>

#include "None.h"

using namespace std;

namespace sample {
	None::None(Magician* const magician)
		: Attunement(magician)
	{
	}

	void None::OnEntry()const {
		cout << "속성 없이 어떻게 싸워, 개오바야!!" << endl;
	}

	void None::Attack()const {
		cout << "냥냥펀치!!" << endl;
	}

	void None::UseEliteSkill(const size_t)const {
		cout << "지금 나 놀려? 스킬은 무슨. 뒤지게 생겼구만" << endl;
	}

	void None::OnDeath()const {
		cout << "에휴,,죽었네" << endl;
	}
}