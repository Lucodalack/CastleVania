#ifndef __STAIR_H__
#define __STAIR_H__

//Cầu thang

#include "Ground.h"
#define _stairWIDTH	32
#define _stairHEIGHT	32
#define _SPRITE L"ground/3.png"
#define TYPE TypeGame::Ground_Stair_Up

class Stair : public Ground {
private:

public:
	Stair(int x, int y);

	void SetFrame(float deltattime);

	Stair();
	~Stair();
};

#endif
