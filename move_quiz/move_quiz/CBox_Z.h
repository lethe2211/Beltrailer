#ifndef DEF_CBOX_Z_H

#define DEF_CBOX_Z_H

#include "DxLib.h"
#include "utility.h"
#include "CBox.h"

class CBox_Z : public CBox {

public:
	CBox_Z(int appear=0, int x=0, int y=0, std::string filename="hoge.png", bool correct=false) : CBox(appear, x, y, filename, correct) {

		ghandle_locate = LoadGraph(filename.c_str()); 

	}; // �R���X�g���N�^(�C�����C���֐�)

	void init(int count); // �Q�[���J�E���g��appear�ȏ�ɂȂ����甠����ʏ�ɕ\��
	void set(int* point); // �Q�[�����[�v���Ƃɍs���e��ϐ��̐ݒ�
	void move(); // ���𓮂���
	void draw(); // �w�肵���ϐ��ɉ����Ĕ���`�悷��
	void term(); // �I������

private:

};

#endif