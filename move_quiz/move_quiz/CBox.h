#ifndef DEF_CBOX_H

#define DEF_CBOX_H

#include "utility.h"
#include <string>

// ���O������������\���N���X
class CBox {

public:
	int x, y; // ���̍���̍��W�ʒu
	int width, height; // ���̕��C����
	int ghandle_locate; // ���̉摜�̃n���h��

	int active; // ������ʏ�ɂ��邩�ǂ����D0�Ȃ�܂�����Ă��Ȃ��D1�Ȃ猻��Ă���D2�Ȃ��ʏォ������Ă���
	int appear; // ��ʏ�Ɍ����Q�[���J�E���g
	int locate; // �����ǂ̈ʒu�ɂ��邩�D0�Ȃ瓚����ׂ��ꏊ�̑O�D1�Ȃ瓚����ׂ��ꏊ�D2�Ȃ瓚����ׂ��ꏊ�̌�
	bool selected; // ����I��������
	bool correct; // ���̕\����������������(����������)
	bool corrected; // �v���C���[��������������I��������
	bool through; // ����������ׂ��ꏊ��ʂ�߂����u�Ԃ̂�true�����

	CBox(int appear, int x, int y, std::string filename, bool correct); // �R���X�g���N�^�D�����͔��̏����ʒu
	int get_active(); 
	void debug(); // �����o�ϐ���\������

private:

};

#endif