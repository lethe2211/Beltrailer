#ifndef DEF_CBOARD_H

#define DEF_CBOARD_H

#include "utility.h"
#include <string>

// ��ʂ�\���N���X
class CBoard {

public:
	CBoard(); // �R���X�g���N�^
	~CBoard(); // �f�X�g���N�^
	void title(); // �^�C�g����ʂ̕`��
	void select(int select_num); // ���Z���N�g��ʂ̕`��
	void draw(int point, int quota, std::string statement1, std::string statement2); // �Q�[����ʂ̕`��
	void result(int point, int quota); // ���ʕ\����ʂ̕`��

private:

};

#endif