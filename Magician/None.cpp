#include <iostream>

#include "None.h"

using namespace std;

namespace sample {
	None::None(Magician* const magician)
		: Attunement(magician)
	{
	}

	void None::OnEntry()const {
		cout << "�Ӽ� ���� ��� �ο�, �����پ�!!" << endl;
	}

	void None::Attack()const {
		cout << "�ɳ���ġ!!" << endl;
	}

	void None::UseEliteSkill(const size_t)const {
		cout << "���� �� ���? ��ų�� ����. ������ ���屸��" << endl;
	}

	void None::OnDeath()const {
		cout << "����,,�׾���" << endl;
	}
}