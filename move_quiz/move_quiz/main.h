#ifndef DEF_MAIN_H

#define DEF_MAIN_H

#include "CBoard.h"
#include "CQuestion.h"

bool savedata[8]; // セーブデータ．bool値でクリアされたかどうかを持つ

int selected; // 選ばれた問題番号
int quota[8] = {40, 60, 60, 60, 60, 60, 60, 60}; // 各問題の得点ノルマ

int key[256];
int pad[16];

int white = GetColor(255, 255, 255); // 白
int black = GetColor(100, 100, 100); // 黒？
int red = GetColor(255, 0, 0); // 赤
int light_red = GetColor(255, 100, 100); // 薄い赤
int green = GetColor(0, 255, 0); // 緑
int blue = GetColor(0, 0, 200); // 青
int light_blue = GetColor(180, 180, 200); // 薄い赤

int font1; // 小さめのフォント
int font2; // 大きめのフォント
int font3; // より小さめのフォント

int ghandle_title; // タイトル画面のフォントハンドル
int ghandle_background; // 背景画像のフォントハンドル
int ghandle_result_background; // 結果発表画面のフォントハンドル
int ghandle_right; // ○のフォントハンドル
int ghandle_wrong; // ×のフォントハンドル

int shandle_bgm; // BGMのサウンドハンドル
int shandle_right; // 正解音のサウンドハンドル
int shandle_wrong; // 不正解音のサウンドハンドル
int shandle_select; // 選択音のサウンドハンドル

void game_init(); // ゲーム起動時の初期化処理
int game_select(CBoard* board);
void game_title(CBoard* board); // タイトル画面の処理
void game_start(); // ゲーム開始時の処理
void game_execute(CBoard* board, CQuestion* question); // ゲーム画面の処理
void game_end(CBoard* board, CQuestion* question); // ゲーム終了時の処理

#endif