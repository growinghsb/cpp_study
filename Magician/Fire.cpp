#include <iostream>

#include "Fire.h"

using namespace std;

namespace sample {
	Fire::Fire(Magician* const magician)
		: Attunement(magician)
	{

	}

	void Fire::OnEntry()const {
		cout << "I am fire! �� ���̾�!! �� �¿ﲱ" << endl;
	}

	void Fire::Attack() const {
		cout << "���̾�̴� ¥�ľ�!!" << endl;
	}

	void Fire::UseEliteSkill(const size_t coolTime) const {
		cout << "���̾��!!!" << endl;
		cout << "��Ÿ�� : " << coolTime << "��" << endl;
	}

	void Fire::OnDeath() const {
		cout << "��..�� ���ƿ�!!" << endl;
	}
}