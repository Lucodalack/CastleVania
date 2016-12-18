#ifndef __MEDUSA_H__
#define __MEDUSA_H__


#include "GObject.h"
#include "GSprite.h"
#include "Simon.h"



#define _WIDTH	64
#define _HEIGHT	65
#define _ANIMATE_RATE	7
#define _ATTACK_RATE	10
#define _SPEED	0.2f

#define _SPRITE L"boss/1.png"

enum MEDUSASTATE
{
	IS_SLEEPING = 1, // Ngủ
	IS_LIVING = 2, // Sống lại

};


class Medusa : public GObject {
protected:
	bool _isSleep;//Medusa ngủ
	bool _isLive;//Medusa sống
	bool _isSnake;//Medusa thả rắn

	float _timesleep = 200;
	int last_x;
	bool flag = false;
	bool _isMoveleft;
	bool _flag1, _flag2, _flag3;
	bool _isDead;// da chet chua nek.
	float _time = 0;
	float _tamp;
public:
	GSprite* _sprite;
	Medusa(int x, int y);
	void MoveUpdate(float deltatime);
	void ChangeState(int state);
	void SetFrame(float deltattime);
	void Update(float deltatime);
	void Draw();
	Medusa();
	~Medusa();
};

#endif