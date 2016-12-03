#include "Whip.h"

Whip* Whip::_whip = 0;
Whip::Whip(int x, int y) :
GObject(TYPE, x, y, _WIDTH, _HEIGHT)
{
	_box = Box(x, y, _WIDTH, _HEIGHT, _vx, _vy);
	GTexture* tt = new GTexture(_SPRITE, 4, 3, 12);
	_sprite = new GSprite(tt, ANIMATIONRATE);
	SetFrame(0); //1 kieu roi
}

void Whip::MoveUpdate(float deltaTime)
{
#pragma region __XU_LY_CHUYEN_DONG__
	this->_x = Simon::getCurrentSimon()->_x;
	this->_y = Simon::getCurrentSimon()->_y;
#pragma endregion
	_box.x = _x;
	_box.y = _y;
	_box.vx = _vx;
	_box.vy = _vy;
}

void Whip::SetFrame(float deltaTime)
{
#pragma region __XU_LY_CHUYEN_DOI_FRAME__
	this->_sprite->_start = 0;
	this->_sprite->_end = 2;
#pragma endregion
}

void Whip::Update(float deltatime){
	this->MoveUpdate(deltatime);
	this->SetFrame(deltatime);
	this->_sprite->Update(deltatime);
}

void Whip::Draw(){
	//if (!Simon::getCurrentSimon()->isFighting())
		//return;

	if (Simon::getCurrentSimon()->isMoveRight()){
		this->_sprite->DrawFlipX(_x, _y);
	}
	else{
		this->_sprite->Draw(_x, _y);
	}
}

Whip* Whip::getCurrentWhip(){
	if (!_whip)
		_whip = new Whip(Simon::getCurrentSimon()->_x, Simon::getCurrentSimon()->_y);
	return _whip;
}





