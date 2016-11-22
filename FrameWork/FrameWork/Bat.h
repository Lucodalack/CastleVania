#ifndef __BAT_H__
#define __BAT_H__


#include "GObject.h"

#define _WIDTH	32
#define _HEIGHT	64
#define _SPEED	0.2f
#define _ANIMATE_RATE	7
#define _ATTACK_RATE	10
#define BAT_SPRITE L"enemy/0.png"
#define TYPE TypeGame::Enemy_Bat

enum BATSATE{
	IsSleep = 0,
	IsAwake = 1
};
class Bat : public GObject {
private:

	bool _isDead;// da chet chua nek.
	bool _isSleep; // dang dung im tren tuong.
	bool _isMoveleft;
	RECT _activeArea; // ô chữ nhật mà con này chạy trong đó.
	int _starty;
public:
	GSprite* _sprite;
	Bat(int x, int y, int x2, int y2);
	void MoveUpdate(float deltatime);
	void SetFrame(float deltattime);
	void Update(float deltatime);
	void Draw();
    void ChangeState(int state);
	Bat();
	~Bat();
};

#endif