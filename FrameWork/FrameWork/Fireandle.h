#ifndef __FIREANDLE_H__
#define __FIREANDLE_H__

//Cây nến bự

#include "Ground.h"
#define _WIDTH	32
#define _HEIGHT	64
#define _SPRITE L"ground/0.png"
#define TYPE TypeGame::Ground_Fireandle

class Fireandle : public Ground {
private:

public:
	Fireandle(int x, int y);

	void SetFrame(float deltattime);

	Fireandle();
	~Fireandle();
};

#endif
