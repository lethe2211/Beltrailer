#ifndef DEF_MAIN_H

#define DEF_MAIN_H

#include "CBoard.h"
#include "CQuestion.h"

bool savedata[8]; // �Z�[�u�f�[�^�Dbool�l�ŃN���A���ꂽ���ǂ���������

int selected; // �I�΂ꂽ���ԍ�
int quota[8] = {40, 60, 60, 60, 60, 60, 60, 60}; // �e���̓��_�m���}

int key[256];
int pad[16];

int white = GetColor(255, 255, 255); // ��
int black = GetColor(100, 100, 100); // ���H
int red = GetColor(255, 0, 0); // ��
int light_red = GetColor(255, 100, 100); // ������
int green = GetColor(0, 255, 0); // ��
int blue = GetColor(0, 0, 200); // ��
int light_blue = GetColor(180, 180, 200); // ������

int font1; // �����߂̃t�H���g
int font2; // �傫�߂̃t�H���g
int font3; // ��菬���߂̃t�H���g

int ghandle_title; // �^�C�g����ʂ̃t�H���g�n���h��
int ghandle_background; // �w�i�摜�̃t�H���g�n���h��
int ghandle_result_background; // ���ʔ��\��ʂ̃t�H���g�n���h��
int ghandle_right; // ���̃t�H���g�n���h��
int ghandle_wrong; // �~�̃t�H���g�n���h��

int shandle_bgm; // BGM�̃T�E���h�n���h��
int shandle_right; // �������̃T�E���h�n���h��
int shandle_wrong; // �s�������̃T�E���h�n���h��
int shandle_select; // �I�����̃T�E���h�n���h��

void game_init(); // �Q�[���N�����̏���������
int game_select(CBoard* board);
void game_title(CBoard* board); // �^�C�g����ʂ̏���
void game_start(); // �Q�[���J�n���̏���
void game_execute(CBoard* board, CQuestion* question); // �Q�[����ʂ̏���
void game_end(CBoard* board, CQuestion* question); // �Q�[���I�����̏���

#endif