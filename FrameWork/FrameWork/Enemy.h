﻿#ifndef __ENEMY_H__
#define __ENEMY_H__


#include "GObject.h"
#include "GSprite.h"
#include "SweptAABB.h"
#define _WIDTH	32
#define _HEIGHT	64
#define _SPEED	1.0f
#define _ATTACK_RATE	33

class Enemy : public GObject {
protected:
	CSweptAABB* swepyAABB;
	bool _isDead;// da chet chua nek.
	bool _isMoveleft;
	bool _isHurting;
	int _damage;
	int _hp;
	RECT _activeArea; // ô chữ nhật mà con này chạy trong đó.
public:
	GSprite* _sprite;
	Enemy(int type,int x, int y, int x2, int y2);
	Enemy(int type, int x, int y, int x2, int y2,bool left);
	void MoveUpdate(float deltatime);
	void SetFrame(float deltattime);
	void Update(float deltatime);
	void Collistion(float deltatime);
	void Draw();
	Enemy();
	~Enemy();
};

#endif