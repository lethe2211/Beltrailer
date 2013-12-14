#ifndef DEF_UTILITY_H

#define DEF_UTILITY_H

#include <string>

extern bool savedata[8];

extern int selected;
extern int quota[8];

extern int key[256];
extern int pad[16];

extern int white; // ”’
extern int black; // •H
extern int red; // Ô
extern int light_red; // ”–‚¢Ô
extern int green; // —Î
extern int blue; // Â
extern int light_blue; // ”–‚¢Â

extern int font1;
extern int font2;
extern int font3;

extern int ghandle_title;
extern int ghandle_background;
extern int ghandle_result_background;
extern int ghandle_right;
extern int ghandle_wrong;

extern int shandle_bgm;
extern int shandle_select;
extern int shandle_right;
extern int shandle_wrong;

int GetHitKeyStateAll_2(int KeyStateBuf[]);
int GetHitPadStateAll(int PadStateBuf[]);

std::string IntToString(int number);


#endif