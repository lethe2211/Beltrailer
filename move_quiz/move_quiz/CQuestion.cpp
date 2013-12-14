#include "DxLib.h"
#include "utility.h"
#include "CQuestion.h"
#include "CBox_Z.h"
#include <cstdio>
#include <string>

CQuestion::CQuestion(int q_num, int quota) {

	// データファイルのパス
	std::string path = "dat\\img_";
	path += IntToString(q_num);
	path += ".dat";

	int dat = FileRead_open(path.c_str());
	char statement1_buf[256],statement2_buf[256];

	FileRead_gets(statement1_buf, sizeof(statement1_buf), dat);

	statement1 = std::string(statement1_buf);

	FileRead_gets(statement2_buf, sizeof(statement2_buf), dat);

	statement2 = std::string(statement2_buf);

	FileRead_scanf(dat, "%d", &num);

	for(int i = 0;i < num;i++) {

		int time;
		char filename_buf[256], bool_buf[256];

		FileRead_scanf(dat, "%d%s%s", &time, filename_buf, bool_buf);

		if(std::string(bool_buf) == "true") z[i] = CBox_Z(time, -200, 250, "img\\" + std::string(filename_buf), true);
		
		else z[i] = CBox_Z(time, -200, 250,"img\\" + std::string(filename_buf), false);

	}

	FileRead_close(dat);
	
	this->q_num = q_num;

	count = 0;
	point = 0;
	this->quota = quota;
 
}

void CQuestion::set_statement1(std::string statement1) {

	this->statement1 = statement1;

}

std::string CQuestion::get_statement1() {
	
	return statement1;

}

void CQuestion::set_statement2(std::string statement2) {

	this->statement2 = statement2;

}

std::string CQuestion::get_statement2() {

	return statement2;

}

int CQuestion::get_count() {

	return count;

}

void CQuestion::add_count(int add) {

	count += add;

}

int CQuestion::get_point() {

	return point;

}

int CQuestion::get_quota() {

	return quota;

}

bool CQuestion::draw() {

	for(int i = 0;i < num;i++) {

		z[i].init(count);

		if(z[i].get_active() == 1) {

			z[i].set(&point);
			z[i].move();
			z[i].draw();

		}

		z[i].term();

	}

	bool flag = false;

	for(int i = 0;i < num;i++) {

		if(z[i].get_active() != 2) flag = true;

	}

	if(flag == false) return false;

	return true;

}

void CQuestion::result() {

	if(point >= quota) savedata[q_num] = true;

	FILE *fp;
	
	if((fp = fopen("dat\\savedata.dat", "wb")) == NULL) DxLib_End();

	fwrite(savedata, sizeof(savedata), 1, fp);

	fclose(fp);

}

void CQuestion::debug() {

	DrawFormatString(0, 550, white, "count=%d, point=%d", count, point);

}

CQuestion::~CQuestion() {
	
	for(int i=0;i < num;i++) {

		DeleteGraph(z[i].ghandle_locate);

	}

}
