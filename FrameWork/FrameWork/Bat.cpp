#include "Bat.h"


Bat::Bat(int x, int y, int x2, int y2) :
Enemy(TYPE, x, y, x2, y2)
{
	_isSleep = true;
	_vx = _batSPEED;
	_box = Box(x, y, _batWIDTH, _batHEIGHT, _vx, _vy);
	GTexture* texture = new GTexture(BAT_SPRITE, 4, 1, 4);
	_sprite = new GSprite(texture, _ANIMATE_RATE);
}

void Bat::MoveUpdate(float deltaTime)
{
#pragma region __XU_LY_CHUYEN_DONG__
	int ynek = Simon::getCurrentSimon()->_y ;

	if (this->_isSleep){
		return;
	}
	if (this->_y <= ynek){
		_vy = 2*_batSPEED;
		this->_y += int(deltaTime*_vy);
		return; // con nay ddang roi xuong 1 doan cho bang thang simon roi moi bay
	}
	if (_isMoveleft){
		if (_x <= _activeArea.left ){
			_vx *= -1;
			this->_isMoveleft = !this->_isMoveleft;
			this->_y = ynek;
		}
	}
	else{
		if (_x >= _activeArea.right){
			_vx *= -1;
			this->_isMoveleft = !this->_isMoveleft;
			this->_y = ynek;
		}
	}
	this->_x += int(this->_vx * deltaTime);
	this->_y += int(8 * sin(float(_x)));
#pragma endregion
	_box.x = _x;
	_box.y = _y;
	_box.vx = _vx;
	_box.vy = _vy;
}

void Bat::SetFrame(float deltaTime)
{
#pragma region __XU_LY_CHUYEN_DOI_FRAME__
	if (this->_isSleep){
		this->_sprite->_start = 0;
		this->_sprite->_end = 0;
	}
	else{
		this->_sprite->_start = 1;
		this->_sprite->_end = 3;
	}
#pragma endregion
}

void Bat::Update(float deltatime){
	this->MoveUpdate(deltatime);
	this->SetFrame(deltatime);
	this->_sprite->Update(deltatime);
}

void Bat::ChangeState(int state){
	if (state == BATSATE::IsSleep){
		this->_isSleep = true;
	}
	else
	if (state == BATSATE::IsAwake){
		this->_isSleep = false;
	}
}
Bat::~Bat(){
	if (_sprite != NULL){
		delete _sprite;
	}
}
