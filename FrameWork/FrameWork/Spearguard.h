#ifndef __SPEARGUARD_H__
#define __SPEARGUARD_H__


#include "Enemy.h"

#define _guardWIDTH	32
#define _guardHEIGHT	64
#define _guardSPEED	0.2f
#define SPEARGAURD_SPRITE L"enemy/5.png"
#define TYPE TypeGame::Enemy_Spearguard

class Spearguard : public Enemy {
private:

public:
	Spearguard(int x, int y, int x2, int y2);
	void SetFrame(float deltaTime);
	Spearguard();
	~Spearguard();
};

#endif