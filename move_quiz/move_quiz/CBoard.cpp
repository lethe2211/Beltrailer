#include "DxLib.h"
#include "CBoard.h"
#include <string>

CBoard::CBoard() {

}

void CBoard::title() {

	DrawGraph(0, 0, ghandle_title, TRUE);

}

void CBoard::select(int select_num) {

	int cursole[8] = {100, 140, 180, 220, 260, 300, 340, 380};

	// �w�i�摜
	DrawGraph(0, 0, ghandle_background, TRUE);

	if(savedata[0] == true) DrawFormatStringToHandle(10, 110, light_blue, font3, "Cleared!");
    if(select_num == 0) DrawFormatStringToHandle(100, 100, light_red, font1, "���1  �W������: ���n  �m���}: %d", quota[0]);
	else DrawFormatStringToHandle(100, 100, white, font1, "���1  �W������: ���n  �m���}: %d", quota[0]);

	if(savedata[1] == true) DrawFormatStringToHandle(10, 150, light_blue, font3, "Cleared!");
    if(select_num == 1) DrawFormatStringToHandle(100, 140, light_red, font1, "���2  �W������: ���n  �m���}: %d", quota[1]);
	else DrawFormatStringToHandle(100, 140, white, font1, "���2  �W������: ���n  �m���}: %d", quota[1]);

	if(savedata[2] == true) DrawFormatStringToHandle(10, 190, light_blue, font3, "Cleared!");
    if(select_num == 2) DrawFormatStringToHandle(100, 180, light_red, font1, "���3  �W������: ���n  �m���}: %d", quota[2]);
	else DrawFormatStringToHandle(100, 180, white, font1, "���3  �W������: ���n  �m���}: %d", quota[2]);

	if(savedata[3] == true) DrawFormatStringToHandle(10, 230, light_blue, font3, "Cleared!");
    if(select_num == 3) DrawFormatStringToHandle(100, 220, light_red, font1, "���4  �W������: ���n  �m���}: %d", quota[3]);
	else DrawFormatStringToHandle(100, 220, white, font1, "���4  �W������: ���n  �m���}: %d", quota[3]);

	if(savedata[4] == true) DrawFormatStringToHandle(10, 270, light_blue, font3, "Cleared!");
    if(select_num == 4) DrawFormatStringToHandle(100, 260, light_red, font1, "���5  �W������: �A�j���E�Q�[��  �m���}: %d", quota[4]);
	else DrawFormatStringToHandle(100, 260, white, font1, "���5  �W������: �A�j���E�Q�[��  �m���}: %d", quota[4]);

	if(savedata[5] == true) DrawFormatStringToHandle(10, 310, light_blue, font3, "Cleared!");
    if(select_num == 5) DrawFormatStringToHandle(100, 300, light_red, font1, "���6  �W������: �A�j���E�Q�[��  �m���}: %d", quota[5]);
	else DrawFormatStringToHandle(100, 300, white, font1, "���6  �W������: �A�j���E�Q�[��  �m���}: %d", quota[5]);

	if(savedata[6] == true) DrawFormatStringToHandle(10, 350, light_blue, font3, "Cleared!");
    if(select_num == 6) DrawFormatStringToHandle(100, 340, light_red, font1, "���7  �W������: �m���W������  �m���}: %d", quota[6]);
	else DrawFormatStringToHandle(100, 340, white, font1, "���7  �W������: �m���W������  �m���}: %d", quota[6]);

	if(savedata[7] == true) DrawFormatStringToHandle(10, 390, light_blue, font3, "Cleared!");
    if(select_num == 7) DrawFormatStringToHandle(100, 380, light_red, font1, "���8  �W������: ���n  �m���}: %d", quota[7]);
	else DrawFormatStringToHandle(100, 380, white, font1, "���8  �W������: ���n  �m���}: %d", quota[7]);

}

void CBoard::draw(int point, int quota, std::string statement1, std::string statement2) {

	// �w�i�摜
	DrawGraph(0, 0, ghandle_background, TRUE);

	// �����ʂ��
	DrawBox(0, 295, 800, 305, blue, TRUE);
	DrawBox(450, 295, 600, 305, red, TRUE);

	// ������
	DrawFormatStringToHandle(30, 120, white, font3, "�x���g���[���[�������Ă��鎞�C");
	DrawFormatStringToHandle(30, 150, white, font3, "�������������Ǝv������Z�L�[���������B");
	DrawFormatStringToHandle(30, 180, white, font3, "�Ⴄ�Ǝv������X���[���I");

	// ���_�\��
	DrawFormatStringToHandle(600, 500, white, font1, "���_:");

	if(point > quota) DrawFormatStringToHandle(690, 500, light_blue, font1, "%d", point);

	else if(point == quota) DrawFormatStringToHandle(690, 500, white, font1, "%d", point);

	else DrawFormatStringToHandle(690, 500, light_red, font1, "%d", point);
		
	// �m���}�\��
	DrawFormatStringToHandle(50, 500, white, font1, "�m���}: %d", quota);

	// ��蕶�\��
	DrawFormatStringToHandle(50, 50, white, font1, statement1.c_str());
	DrawFormatStringToHandle(50, 80, white, font1, statement2.c_str());

}

void CBoard::result(int point, int quota) {

	// ���ʔ��\��ʂ̕\��(�������ɂ���)
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, 10);
	DrawGraph(0, 250, ghandle_result_background, TRUE);
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);

	// �m���}�N���A�������łȂ���
	if(point >= quota) DrawFormatStringToHandle(250, 275, white, font2, "�m���}�N���A�I"); 

	else DrawFormatStringToHandle(250, 275, white, font2, "�Ē��킵�悤�I");

}

CBoard::~CBoard() {

}