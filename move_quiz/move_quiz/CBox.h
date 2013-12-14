#ifndef DEF_CBOX_H

#define DEF_CBOX_H

#include "utility.h"
#include <string>

// 名前を書いた箱を表すクラス
class CBox {

public:
	int x, y; // 箱の左上の座標位置
	int width, height; // 箱の幅，高さ
	int ghandle_locate; // 箱の画像のハンドル

	int active; // 箱が画面上にあるかどうか．0ならまだ現れていない．1なら現れている．2なら画面上から消えている
	int appear; // 画面上に現れるゲームカウント
	int locate; // 箱がどの位置にあるか．0なら答えるべき場所の前．1なら答えるべき場所．2なら答えるべき場所の後
	bool selected; // 箱を選択したか
	bool correct; // 箱の表す答えが正しいか(正しい答え)
	bool corrected; // プレイヤーが正しい答えを選択したか
	bool through; // 箱が答えるべき場所を通り過ぎた瞬間のみtrueを取る

	CBox(int appear, int x, int y, std::string filename, bool correct); // コンストラクタ．引数は箱の初期位置
	int get_active(); 
	void debug(); // メンバ変数を表示する

private:

};

#endif