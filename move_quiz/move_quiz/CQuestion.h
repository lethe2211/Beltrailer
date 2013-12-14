#ifndef DEF_CQUESTION_H

#define DEF_CQUESTION_H

#include "utility.h"
#include "CBox_Z.h"
#include <string>

// ���1���\���N���X
class CQuestion {

public:

	CBox_Z z[30]; // ���

	CQuestion(int q_num, int quota); // �R���X�g���N�^
	~CQuestion(); // �f�X�g���N�^

	void set_statement1(std::string statement1); 
	std::string get_statement1();
	void set_statement2(std::string statement2);
	std::string get_statement2();
	int get_count();
	void add_count(int add); // �Q�[���J�E���g�̒ǉ�
	int get_point();
	int get_quota();

	bool draw(); // ���̕`��ƃQ�[���̏I������
	void result(); // ���ʔ��\���̏���

	void debug();

private:
	
	int q_num; // ���Ԗڂ̖�肩
	std::string statement1; // ��蕶
	std::string statement2;

	int num; // 1�₠����̗���Ă��锠�̐�
	int count; // �Q�[���J�E���g�D��肪�n�܂��0�ɏ���������C1�t���[�����Ƃ�1����������
	int point; // ���_
	int quota; // ���_�m���}

};

#endif