#ifndef DEF_CBOARD_H

#define DEF_CBOARD_H

#include "utility.h"
#include <string>

// 画面を表すクラス
class CBoard {

public:
	CBoard(); // コンストラクタ
	~CBoard(); // デストラクタ
	void title(); // タイトル画面の描画
	void select(int select_num); // 問題セレクト画面の描画
	void draw(int point, int quota, std::string statement1, std::string statement2); // ゲーム画面の描画
	void result(int point, int quota); // 結果表示画面の描画

private:

};

#endif