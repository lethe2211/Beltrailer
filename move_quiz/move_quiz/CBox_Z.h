#ifndef DEF_CBOX_Z_H

#define DEF_CBOX_Z_H

#include "DxLib.h"
#include "utility.h"
#include "CBox.h"

class CBox_Z : public CBox {

public:
	CBox_Z(int appear=0, int x=0, int y=0, std::string filename="hoge.png", bool correct=false) : CBox(appear, x, y, filename, correct) {

		ghandle_locate = LoadGraph(filename.c_str()); 

	}; // コンストラクタ(インライン関数)

	void init(int count); // ゲームカウントがappear以上になったら箱を画面上に表示
	void set(int* point); // ゲームループごとに行う各種変数の設定
	void move(); // 箱を動かす
	void draw(); // 指定した変数に応じて箱を描画する
	void term(); // 終了処理

private:

};

#endif