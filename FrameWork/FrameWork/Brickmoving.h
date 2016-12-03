#ifndef __MOVINGBRICK_H__
#define __MOVINGBRICK_H__


#include "Enemy.h"

#define _mvbWIDTH	32
#define _mvbHEIGHT	64
#define _mvbSPEED	0.2f
#define _SPRITE L"ground/9.png"
#define TYPE TypeGame::Enemy_Bat


class Brickmoving : public Enemy {

public:
	Brickmoving(int x, int y, int x2, int y2);
	void MoveUpdate(float deltatime);
	void SetFrame(float deltattime);
	void Update(float deltatime);
	Brickmoving();
	~Brickmoving();
};

#endif