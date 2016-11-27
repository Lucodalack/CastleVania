#ifndef __BAT_H__
#define __BAT_H__


#include "Enemy.h"
#include "Simon.h"

#define _batWIDTH	32
#define _batHEIGHT	64
#define _batSPEED	0.2f
#define BAT_SPRITE L"enemy/0.png"
#define TYPE TypeGame::Enemy_Bat

enum BATSATE{
	IsSleep = 0,
	IsAwake = 1
};
class Bat : public Enemy {
private:

	bool _isSleep; // dang dung im tren tuong.
public:
	Bat(int x, int y, int x2, int y2);
	void MoveUpdate(float deltatime);
	void SetFrame(float deltattime);
	void Update(float deltatime);
    void ChangeState(int state);
	Bat();
	~Bat();
};

#endif