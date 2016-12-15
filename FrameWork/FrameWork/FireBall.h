#ifndef __FIREBALL_H__
#define __FIREBALL_H__

//Đạn của Bone Pillar

#define _WIDTH	16
#define _HEIGHT	20
#define _SPRITE L"other/0.png"
#define TYPE TypeGame::Item_fire_ball
#define _SPEED 0.3f

#include "GObject.h"
#include <vector>
#include <d3d9.h>
#include <d3dx9.h>
#include <stdio.h>

class FireBall : public GObject {
protected:
	int _Str_Y;
	int _Offset;
	int check = 30;
	bool left, right;
	int last_x;

	int a[10];


	int var;
	bool flag = false;
	bool flag1 = false;

public:
	GSprite* _sprite;
	FireBall(int x, int y);
	void MoveUpdate(float deltatime);
	void SetFrame(float deltattime);
	void Update(float deltatime);
	void ChangeState(int state);
	void Draw();
	FireBall();
	~FireBall();
};

#endif
