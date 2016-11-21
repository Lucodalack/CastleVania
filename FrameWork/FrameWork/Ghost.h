#ifndef __GHOST_H__
#define __GHOST_H__


#include "GObject.h"
#include "GSprite.h"



#define _WIDTH	32
#define _HEIGHT	64
#define _SPEED	0.2f
#define _ANIMATE_RATE	7
#define _ATTACK_RATE	10
#define GHOST_SPRITE L"enemy/1.png"

#define TYPE TypeGame::Enemy_Ghost

class Ghost : public GObject {
private:


	bool _isDead;// da chet chua nek.
	bool _isMoveleft;
	RECT _activeArea; // ô chữ nhật mà con này chạy trong đó.
public:
	GSprite* _sprite;
	Ghost(int x, int y,int x2, int y2);
	void MoveUpdate(float deltatime);
	void SetFrame(float deltattime);
	void Update(float deltatime);
	void Draw();
	Ghost();
	~Ghost();
};

#endif