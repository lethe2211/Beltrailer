#include "DxLib.h"
#include "CBox.h"
#include <string>

CBox::CBox(int appear, int x, int y, std::string filename, bool correct) {

	this->x = x;
	this->y = y;

	width = 200;
	height = 100;

	active = 0;
	this->appear = appear;
	locate = 0;
	selected = false;
	this->correct = correct;
	corrected = false;
	through = false;

}

int CBox::get_active() {

	return active;

}

void CBox::debug() {

	DrawFormatString(0, 0, white, "x = %d, y = %d, locate = %d", x, y, locate);

}