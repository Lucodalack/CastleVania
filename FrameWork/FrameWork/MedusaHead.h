#ifndef __MEDUSAHEAD_H__
#define __MEDUSAHEAD_H__


#include "Enemy.h"

#define _medusaheadWIDTH	32
#define _medusaheadHEIGHT	32
#define _medusaheadSPEED	0.2f
#define MEDUSAHEAD_SPRITE L"enemy/6.png"
#define TYPE TypeGame::Enemy_Bat

class MedusaHead : public Enemy {
private:

public:
	MedusaHead(int x, int y, int x2, int y2);
	void MoveUpdate(float deltatime);
	void SetFrame(float deltattime);
	void Update(float deltatime);
	MedusaHead();
	~MedusaHead();
};

#endif