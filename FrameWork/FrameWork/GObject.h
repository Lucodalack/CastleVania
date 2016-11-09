#ifndef __OBJECT_H__
#define __OBJECT_H__



#include <d3d9.h>
#include <d3dx9.h>
#include "GSprite.h"

#define GRAVITY			-0.0022f



class GObject {
protected:

public:
	int _x;
	int _y;
	int _width;
	int _height;

	float _vx;
	float _vy;
	float _gravity;

	int _type;

	RECT _bound;



	GObject::GObject(int type, int x, int y, int width, int height);

	/*virtual void LoadResource();
	virtual void Update(int Delta);
	virtual void Render();
	virtual void Damaged(int damage, int x, int y);*/



	void UpdatePosition(int time);
	//void FixPositionCollid(G_OBJECT * o, int CollidPos);


	~GObject();
};

#endif