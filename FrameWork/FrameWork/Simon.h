#ifndef __SIMON_H__
#define __SIMON_H__


#include "GObject.h"
#include "GSprite.h"
#include "Whip.h"


#define SIMON_SPRITE L"simon.png"

#define SIMON_WIDTH			60
#define SIMON_HEIGHT		66
#define SIMON_SPEED			1.2f
#define SIMON_JUMP_SPEED	5.0f
#define SIMON_Animation_RATE	ANIMATIONRATE
#define TYPE TypeGame::Boss_Simon
#define SIMON_JUMPMAX 64

enum STATE
{
	IS_STANDING = 1, // đứng
	IS_JOGGING = 2, //đi bộ
	IS_SITTING = 3, // NGỒI
	IS_JUMPING = 4, //NHẢY 
	IS_UPING = 5, // LÊN CẦU THANG
	IS_DOWNING = 6, // XUỐNG CẦU THANG
	IS_FIGHTING = 7, // ĐÁNH
	IS_JUMPFIGH = 8, //NHẢY LÊN ĐÁNH
	IS_SITFIGHT = 9, // NGỒI ĐÁNH
	IS_UPFIGHT = 10, //LÊN CẦU THANG VỪA ĐÁH
	IS_DOWNFIGHT =11, // VỪA XUỐNG CẦU THANG VỪA ĐÁNH.
	IS_PASSGATE =12, // QUA MANF.
	IS_FALLING = 13
};

class Simon : public GObject {
private:

	static Simon* _simon;

	int _stateCurrent; //trạng thái hiện tại
	bool _isMoveleft; // quay qua trái hay k
	bool _isMoveright;
	bool _isOnStair; // dang o tren cau thang hay k
	bool _isJumping; //dang nhay
	bool _isFalling;// dang roi xuong
	bool _isFighting; // danh danh nhau nek
	int _keyDown; // lưu phím vừa được nhấn.
	int _keyUp;
	float _tmp = 0;

public:
	GSprite* _sptrite;
	static Simon* getCurrentSimon();
	Simon(int x, int y);
	void MoveUpdate(float deltatime);
	void SetFrame(float deltattime);
	void InputUpdate(float deltatime);
	void Update(float deltatime);
	void ChangeState(int state);
	void ChangeState(float deltatime){ _isFighting = false; SetFrame(deltatime); }
	void Jump();
	void Fight();
	int GetState(){
		return _stateCurrent;
	}
	void Draw();
	bool isFighting(){ return _isFighting; }
	bool isMoveRight(){ return _isMoveright; }
	bool isMoveLeft(){ return _isMoveleft; }
	Simon();
	~Simon();
};

#endif