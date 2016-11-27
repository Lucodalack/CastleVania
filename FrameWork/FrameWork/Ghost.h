#ifndef __GHOST_H__
#define __GHOST_H__

#include "Enemy.h"

#define _ghostWIDTH	32
#define _ghostHEIGHT	64
#define _ghostSPEED	0.2f
#define GHOST_SPRITE L"enemy/1.png"
#define TYPE TypeGame::Enemy_Ghost

class Ghost : public Enemy {
private:

public:
	Ghost(int x, int y,int x2, int y2);
	void SetFrame(float deltaTime);
	Ghost();
	~Ghost();
};

#endif