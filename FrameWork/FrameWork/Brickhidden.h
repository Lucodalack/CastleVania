#ifndef __HIDDENBRICK_H__
#define __HIDDENBRICK_H__

//Đất ẩn

#include "Ground.h"
#define _WIDTH	32
#define _HEIGHT	32
#define _SPRITE L"ground/2-3.png"
#define TYPE TypeGame::Ground_Hidden

class Brickhidden : public Ground {
private:

public:
	Brickhidden(int x, int y);

	void SetFrame(float deltattime);

	Brickhidden();
	~Brickhidden();
};

#endif
