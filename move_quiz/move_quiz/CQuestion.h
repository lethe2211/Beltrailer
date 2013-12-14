#ifndef DEF_CQUESTION_H

#define DEF_CQUESTION_H

#include "utility.h"
#include "CBox_Z.h"
#include <string>

// 問題1問を表すクラス
class CQuestion {

public:

	CBox_Z z[30]; // 問題

	CQuestion(int q_num, int quota); // コンストラクタ
	~CQuestion(); // デストラクタ

	void set_statement1(std::string statement1); 
	std::string get_statement1();
	void set_statement2(std::string statement2);
	std::string get_statement2();
	int get_count();
	void add_count(int add); // ゲームカウントの追加
	int get_point();
	int get_quota();

	bool draw(); // 問題の描画とゲームの終了判定
	void result(); // 結果発表時の処理

	void debug();

private:
	
	int q_num; // 何番目の問題か
	std::string statement1; // 問題文
	std::string statement2;

	int num; // 1問あたりの流れてくる箱の数
	int count; // ゲームカウント．問題が始まると0に初期化され，1フレームごとに1増加させる
	int point; // 得点
	int quota; // 得点ノルマ

};

#endif