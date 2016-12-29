#ifndef __ITEM_H__
#define __ITEM_H__

#include "GObject.h"
#include "GSprite.h"
#include "Whip.h"
#include "SweptAABB.h"
#include "GAudio.h"

#define _WIDTH	32
#define _HEIGHT	32
#define _SPEED	0.113f
#define _ATTACK_RATE	10
#define _LIFETIME 3000
enum ItemState{
	_ItemHidding =0,
	_ItemShowing =1
};
class Item : public GObject {
protected:
	CSweptAABB* swepyAABB;
	float _lifeTime; // lifetime <0 là đang ẩn sau gạch hay sau j đó. lifetime >= _LIFETIME thì là biết mất.
	bool _isOnGround;
	RECT _activeArea; // ô chữ nhật mà con này chạy trong đó.
public:
	GSprite* _sprite;
	Item(int type, int x, int y, int x2, int y2);
	void MoveUpdate(float deltatime);
	void SetFrame(float deltattime);
	void Update(float deltatime);
	void ChangeState(int state);
	void Collistion(float deltatime);
	void Draw();
	int GetLifeTime(){
		return _lifeTime;
	}
	void WakeUp(){
		if (_lifeTime < 0)
			_lifeTime = 0;
	}
	Item();
	~Item();
};

#endif