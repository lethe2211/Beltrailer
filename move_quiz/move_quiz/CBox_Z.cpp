#include "CBox_Z.h"

void CBox_Z::init(int count) {

	if(count > appear) active = 1;

}

void CBox_Z::set(int* point) {

	// �ϐ�through��locate��1����2�ɕς��Ƃ��̂�true�ƂȂ�
	if(locate == 1) through = true;

	else through = false;

	// �����錠���������Ԃł�locate��1�ɂ��Ă���
	if((x + width >= 450) && (x <= 600)) {

		locate = 1;

	}

	// �܂������錠�����Ȃ���Ԃł�locate��0�ɂ���
	else if(x + width < 450) {

		locate = 0;

	}

	// �����I�������Ԃł�locate��2�ɂ���
	else {

		locate = 2;

	}

	// ������through�̒l���m�肷��
	if(locate != 2) through = false;  

	// �܂��I������Ă��Ȃ���
	if(selected == false) {

		// locate��1�ŁA����Z�L�[�������ꂽ�Ȃ�(�܂�A�v���C���[�����̔��𐳉����Ɣ��f�����Ȃ�)
		if((locate == 1) && ((CheckHitKey(KEY_INPUT_Z) == 1) /*|| (pad[PAD_INPUT_A] >= 1)*/)) {
			
			// ���ۂ̓����������ł���΁A�_����+10����
			if(correct == true) {
				
				corrected = true;

				*point += 10;

				PlaySoundMem(shandle_right, DX_PLAYTYPE_BACK);

			}

			// ���ۂ̓������s�����ł���΁A�_����-10����
			else {

				*point -= 10;

				PlaySoundMem(shandle_wrong, DX_PLAYTYPE_BACK);

			}

			// �I�����I�����
			selected = true;

		}

		// locate��2�ɂȂ��(�v���C���[�����̔���s�������Ɣ��f������)
		if(locate == 2) {

			// ���ۂ̓����������ł���΁A(through��true�ƂȂ�1�t���[������)�_����-10����
			if(correct == true) {
				
				corrected = false;

				if(through == true) { 
					
					*point -= 10;

					PlaySoundMem(shandle_wrong, DX_PLAYTYPE_BACK);

				}

			}

			// ���ۂ̓������s�����ł���΁A(through��false�ƂȂ�1�t���[������)�_����+10����
			else {

				corrected = true;

				if(through == true) {
					
					*point += 10;

					PlaySoundMem(shandle_right, DX_PLAYTYPE_BACK);

				}

			}

		}

	}

}

void CBox_Z::move() {

	if(CheckHitKey(KEY_INPUT_F) == 1) x += 8;

	else x += 1;

}

void CBox_Z::draw() {

	// ��I�����̏���
	if(selected == false) {

		// �܂������錠�����Ȃ���ԂȂ�
		if(locate == 0) {

			// ���������Â����ĕ`��
			SetDrawBright(100, 100, 100);
			DrawGraph(x, y, ghandle_locate, TRUE);
			SetDrawBright(255, 255, 255);

		}
		
		// �����錠���������ԂȂ�
		else if(locate == 1) {
			
			// ���ʂɕ`��
			DrawGraph(x, y, ghandle_locate, TRUE); 

		}

		// �����錠�����Ȃ��Ȃ�����ԂȂ�(���𖳎�������)
		else {

			// ���ʂɕ`�悵�����
			DrawGraph(x, y, ghandle_locate, TRUE);

			// �v���C���[�̓����������������Ȃ�
			if(corrected == true) {
				
				// ����`�悷��
				DrawGraph((2*x + width)/2 - 50, (2*y + height)/2 - 50, ghandle_right, TRUE);

			}

			// �v���C���[�̓������Ԉ���Ă�����A�~��`�悷��
			else DrawGraph((2*x + width)/2 - 50, (2*y + height)/2 - 50, ghandle_wrong, TRUE);

		}

	}

	// �I�����̏���
	else {

		DrawGraph(x, y, ghandle_locate, TRUE);
		
		if(corrected == true) {
			
			DrawGraph((2*x + width)/2 - 50, (2*y + height)/2 - 50, ghandle_right, TRUE);

		}

		else DrawGraph((2*x + width)/2 - 50, (2*y + height)/2 - 50, ghandle_wrong, TRUE);

	}

}

void CBox_Z::term() {

	// active��1�ł���A�������I��������̂ɂ��āA���ꂪ��ʊO�ɂ����active��2�ɂ���
	if((active == 1) && (locate == 2) && ((x > 800) || (y > 600) || ((x + width) < 0) || (y + height < 0))) {

		active = 2;

	}

}
