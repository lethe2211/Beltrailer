#include "DxLib.h"
#include "utility.h"
#include <string>
#include <sstream>

int GetHitKeyStateAll_2(int KeyStateBuf[]){
        char GetHitKeyStateAll_Key[256];
        GetHitKeyStateAll( GetHitKeyStateAll_Key );
        for(int i=0;i<256;i++){
                if(GetHitKeyStateAll_Key[i]==1) KeyStateBuf[i]++;
                else                            KeyStateBuf[i]=0;
        }
        return 0;
}

int GetHitPadStateAll(int PadStateBuf[]) {

	int pad = GetJoypadInputState(DX_INPUT_PAD1);
	int mul = 1;

	for(int i=0;i<16;i++) {

		if(pad & mul) PadStateBuf[i]++;
		else PadStateBuf[i]=0;
		mul *= 2;
	}

	return 0;

}

std::string IntToString(int number) {

  std::ostringstream ss;
  ss << number;

  return ss.str();

}