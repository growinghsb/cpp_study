#include <iostream>

#include "Fire.h"

using namespace std;

namespace sample {
	Fire::Fire(Magician* const magician)
		: Attunement(magician)
	{

	}

	void Fire::OnEntry()const {
		cout << "I am fire! 나 불이야!! 다 태울껑" << endl;
	}

	void Fire::Attack() const {
		cout << "파이어볼이다 짜식아!!" << endl;
	}

	void Fire::UseEliteSkill(const size_t coolTime) const {
		cout << "파이어스톰!!!" << endl;
		cout << "쿨타임 : " << coolTime << "초" << endl;
	}

	void Fire::OnDeath() const {
		cout << "나..나 돌아와!!" << endl;
	}
}