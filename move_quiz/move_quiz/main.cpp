#include "DxLib.h"
#include "utility.h"
#include "main.h"
#include "CBoard.h"
#include "CBox.h"
#include "CBox_Z.h"
#include "CQuestion.h"
#include <shlwapi.h>
#include <string>
#pragma comment(lib, "shlwapi.lib")
#include <cstdio>

int WINAPI WinMain(HINSTANCE,HINSTANCE,LPSTR,int){
	
	game_init();

	CBoard board;
		
	game_title(&board);

	while(ProcessMessage() == 0) {

		selected = game_select(&board);

		if(selected == -1) break;

		CQuestion question(selected, quota[selected]);

		game_start();

		game_execute(&board, &question);

		game_end(&board, &question);

	}

    DxLib_End(); // DXライブラリ終了処理
    return 0;
}

void game_init() {

	SetGraphMode(800, 600, 16);
	ChangeWindowMode(TRUE);
	SetMainWindowText("クイズ！ベルトレーラー");
	DxLib_Init();
	SetDrawScreen( DX_SCREEN_BACK ); //ウィンドウモード変更と初期化と裏画面設定

	font1 = CreateFontToHandle(NULL, 30, 9, DX_FONTTYPE_ANTIALIASING);
	font2 = CreateFontToHandle(NULL, 45, 9, DX_FONTTYPE_ANTIALIASING);
	font3 = CreateFontToHandle(NULL, 20, 9, DX_FONTTYPE_ANTIALIASING);

	ghandle_title = LoadGraph("img\\title.png");
	ghandle_background = LoadGraph("img\\background.png");
	ghandle_result_background = LoadGraph("img\\result_background.png");
	ghandle_right = LoadGraph("img\\right.png");
	ghandle_wrong = LoadGraph("img\\wrong.png");

	shandle_bgm = LoadSoundMem("sound\\bgm.mp3");
	shandle_select = LoadSoundMem("sound\\select.wav");
	shandle_right = LoadSoundMem("sound\\right.wav");
	shandle_wrong = LoadSoundMem("sound\\wrong.wav");

	if(PathFileExists("dat\\savedata.dat")) {

		FILE* fp;

		if((fp = fopen("dat\\savedata.dat", "rb")) == NULL) DxLib_End();

		fread(savedata, sizeof(savedata), 1, fp);

		fclose(fp);

	}

	else {

		FILE* fp;

		if((fp = fopen("dat\\savedata.dat", "wb")) == NULL) DxLib_End();

		for(int i = 0;i < 8;i++) savedata[i] = false;

		fwrite(savedata, sizeof(savedata), 1, fp);

		fclose(fp);

	}

}

void game_title(CBoard* board) {

	bool neutral = false;

	while(ScreenFlip() == 0 && ProcessMessage() == 0 && ClearDrawScreen() == 0 && GetHitKeyStateAll_2(key) == 0) {

		int pad1 = GetJoypadInputState(DX_INPUT_KEY_PAD1);

		// if((key[KEY_INPUT_Z] == 0) && !(pad1 & PAD_INPUT_1)) neutral = true;
		if(!(pad1 & PAD_INPUT_A)) neutral = true;

		if(neutral == true) {
			
			if(pad1 & PAD_INPUT_A) {
			
				PlaySoundMem(shandle_select, DX_PLAYTYPE_BACK);
					
				break;

			}

		}
		
		board->title();

	}

}

int game_select(CBoard* board) {

	int select = 0;
	int select_num;
	
	bool neutral = false;

	while(ScreenFlip() == 0 && ClearDrawScreen() == 0 && GetHitKeyStateAll_2(key) == 0 && GetHitPadStateAll(pad) == 0) {

		int pad1 = GetJoypadInputState(DX_INPUT_KEY_PAD1);

		if(ProcessMessage() == -1) return -1;

		if(!(pad1 & PAD_INPUT_A)) neutral = true;

		if(neutral == true) {
			
			if(((key[KEY_INPUT_UP] == 1) || ((key[KEY_INPUT_UP] % 5 == 0) && (key[KEY_INPUT_UP] > 30))) || ((pad[3] == 1) || ((pad[3] % 5 == 0) && (pad[3] > 30)))) {

				select--;

				PlaySoundMem(shandle_select, DX_PLAYTYPE_BACK);

			}

			// たった今押したか、30カウンター以上押しっぱなしかつ5回に一度
			if(((key[KEY_INPUT_DOWN] == 1) || ((key[KEY_INPUT_DOWN] % 5 == 0) && (key[KEY_INPUT_DOWN] > 30))) || ((pad[PAD_INPUT_DOWN] == 1) || ((pad[PAD_INPUT_DOWN] % 5 == 0) && (pad[PAD_INPUT_DOWN] > 30)))) {

				select++;

				PlaySoundMem(shandle_select, DX_PLAYTYPE_BACK);

			}

			select_num = select % 8;

			if(select_num < 0) select_num += 8;
			
			board->select(select_num);

			if((CheckHitKey(KEY_INPUT_Z) != 0) || (pad1 & PAD_INPUT_A)) {

				return select_num;

			}

        }

	}

	return -1;

}

void game_start() {

	PlaySoundMem(shandle_bgm, DX_PLAYTYPE_LOOP);

}

void game_execute(CBoard* board, CQuestion* question) {

	// while( 裏画面を表画面に反映, メッセージ処理, 画面クリア )
    while( ScreenFlip()==0 && ProcessMessage() == 0 && ClearDrawScreen()==0 && GetHitKeyStateAll_2(key) == 0 && GetHitPadStateAll(pad) == 0){

		board->draw(question->get_point(), question->get_quota(), question->get_statement1(), question->get_statement2());

		if(question->draw() == false) break;

		if(CheckHitKey(KEY_INPUT_F) == 1) question->add_count(8);

		else question->add_count(1);

		// question->debug();

    }

}

void game_end(CBoard* board, CQuestion* question) {

	question->result();

	do {

		board->result(question->get_point(), question->get_quota());

		if(CheckHitKey(KEY_INPUT_Z) == 1) break;

	} while(ScreenFlip() == 0 && ProcessMessage() == 0);

	StopSoundMem(shandle_bgm);

}



