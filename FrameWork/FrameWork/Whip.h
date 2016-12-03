#ifndef __Whip_H__
#define __Whip_H__

#include "Simon.h"
#define _WIDTH 64
#define _HEIGHT 64
//#define _SPRITE L"morningstar.png"
#define _SPRITE L"morningstar.png"
#define TYPE TypeGame::MxD
class Whip : public GObject {
private:
	bool _turnlef;
	static Whip* _whip;
public:
	GSprite* _sprite;
	Whip(int x, int y);
	static Whip* getCurrentWhip();
	void MoveUpdate(float deltatime);
	void SetFrame(float deltattime);
	void Update(float deltatime);
	void Draw();
	Whip();
	~Whip();
};

#endif