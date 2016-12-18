#include "FireBall.h"
#include "Simon.h"



FireBall::FireBall(int x, int y) :
GObject(TYPE, x, y, _WIDTH, _HEIGHT)

{
	last_x = x;
	_vx = _SPEED;
	_box = Box(x, y, _WIDTH, _WIDTH);
	GTexture* texture1 = new GTexture(_SPRITE, 1, 1, 1);
	_sprite = new GSprite(texture1, 0);


}

void FireBall::ChangeState(int state){
	//
}

void FireBall::Update(float DeltaTime)
{
	if (flag == true && flag1 == true)
	{
		flag = false;
		flag = false;
	}

	if (Simon::getCurrentSimon()->_x < this->last_x && flag1 == false)
	{
		_vx = -_SPEED;
		flag = true;
	}
	else
	if (flag == false)
	{
		_vx = _SPEED;
		flag1 = true;
	}

	this->_x += int(this->_vx * DeltaTime);

	_box = Box(_x, _y, _WIDTH, _WIDTH);
}

void FireBall::Draw()
{
	_sprite->Draw(_x, _y);
}