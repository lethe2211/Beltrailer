#include "CBox_Z.h"

void CBox_Z::init(int count) {

	if(count > appear) active = 1;

}

void CBox_Z::set(int* point) {

	// 変数throughはlocateが1から2に変わるときのみtrueとなる
	if(locate == 1) through = true;

	else through = false;

	// 答える権利がある区間ではlocateを1にしておく
	if((x + width >= 450) && (x <= 600)) {

		locate = 1;

	}

	// まだ答える権利がない区間ではlocateを0にする
	else if(x + width < 450) {

		locate = 0;

	}

	// 答え終わった区間ではlocateを2にする
	else {

		locate = 2;

	}

	// ここでthroughの値が確定する
	if(locate != 2) through = false;  

	// まだ選択されていない時
	if(selected == false) {

		// locateが1で、かつZキーが押されたなら(つまり、プレイヤーがその箱を正解だと判断したなら)
		if((locate == 1) && ((CheckHitKey(KEY_INPUT_Z) == 1) /*|| (pad[PAD_INPUT_A] >= 1)*/)) {
			
			// 実際の答えが正解であれば、点数を+10する
			if(correct == true) {
				
				corrected = true;

				*point += 10;

				PlaySoundMem(shandle_right, DX_PLAYTYPE_BACK);

			}

			// 実際の答えが不正解であれば、点数を-10する
			else {

				*point -= 10;

				PlaySoundMem(shandle_wrong, DX_PLAYTYPE_BACK);

			}

			// 選択し終わった
			selected = true;

		}

		// locateが2になれば(プレイヤーがその箱を不正解だと判断したら)
		if(locate == 2) {

			// 実際の答えが正解であれば、(throughがtrueとなる1フレームだけ)点数を-10する
			if(correct == true) {
				
				corrected = false;

				if(through == true) { 
					
					*point -= 10;

					PlaySoundMem(shandle_wrong, DX_PLAYTYPE_BACK);

				}

			}

			// 実際の答えが不正解であれば、(throughがfalseとなる1フレームだけ)点数を+10する
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

	// 非選択時の処理
	if(selected == false) {

		// まだ答える権利がない状態なら
		if(locate == 0) {

			// 箱を少し暗くして描画
			SetDrawBright(100, 100, 100);
			DrawGraph(x, y, ghandle_locate, TRUE);
			SetDrawBright(255, 255, 255);

		}
		
		// 答える権利がある状態なら
		else if(locate == 1) {
			
			// 普通に描画
			DrawGraph(x, y, ghandle_locate, TRUE); 

		}

		// 答える権利がなくなった状態なら(箱を無視したら)
		else {

			// 普通に描画した上で
			DrawGraph(x, y, ghandle_locate, TRUE);

			// プレイヤーの答えが正しかったなら
			if(corrected == true) {
				
				// ○を描画する
				DrawGraph((2*x + width)/2 - 50, (2*y + height)/2 - 50, ghandle_right, TRUE);

			}

			// プレイヤーの答えが間違っていたら、×を描画する
			else DrawGraph((2*x + width)/2 - 50, (2*y + height)/2 - 50, ghandle_wrong, TRUE);

		}

	}

	// 選択時の処理
	else {

		DrawGraph(x, y, ghandle_locate, TRUE);
		
		if(corrected == true) {
			
			DrawGraph((2*x + width)/2 - 50, (2*y + height)/2 - 50, ghandle_right, TRUE);

		}

		else DrawGraph((2*x + width)/2 - 50, (2*y + height)/2 - 50, ghandle_wrong, TRUE);

	}

}

void CBox_Z::term() {

	// activeが1であり、かつ答え終わったものについて、それが画面外にあればactiveを2にする
	if((active == 1) && (locate == 2) && ((x > 800) || (y > 600) || ((x + width) < 0) || (y + height < 0))) {

		active = 2;

	}

}
