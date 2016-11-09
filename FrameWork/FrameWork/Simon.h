#ifndef __SIMON_H__
#define __SIMON_H__


#include "GObject.h"
#include "GSprite.h"

#define SIMON_WIDTH			32
#define SIMON_HEIGHT		64
#define SIMON_SPEED			0.2f
#define SIMON_JUMP_SPEED	0.7f
#define SIMON_ANIMATE_RATE	7
#define SIMON_ATTACK_RATE	10
#define TYPE 2

class Simon : public GObject {
private:

	static Simon* _simon;

public:
	GSprite* _upSprite;
	GSprite* _downSprite;
	GSprite* _leftSprite;
	GSprite* _rightSprite;
	static Simon* getCurrentSimon();
	Simon(int x, int y);
	void run(int x, int y);
	void draw();
	Simon();
	~Simon();
};

#endif