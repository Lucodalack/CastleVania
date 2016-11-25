#ifndef __TRAP_H__
#define __TRAP_H__

//Bẫy

#include "Item.h"
#define _trapWIDTH	32
#define _trapHEIGHT	32
#define _SPRITE L"ground/7.png"
#define TYPE TypeGame::Ground_Trap

class Trap : public Item {
private:

public:
	Trap(int x, int y);

	void SetFrame(float deltattime);

	Trap();
	~Trap();
};

#endif
