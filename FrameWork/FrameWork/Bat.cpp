#include "Bat.h"


Bat::Bat(int x, int y, int x2, int y2) :
GObject(TYPE, x, y, _WIDTH, _HEIGHT)
{
	_isMoveleft = false;
	_isDead = false;
	_isSleep = true;
	_vy = GRAVITY;
	_vx = _SPEED;
	_box = Box(x, y, _WIDTH, _HEIGHT, _vx, _vy);
	_activeArea.top = y;
	_activeArea.left = x;
	_activeArea.right = x2;
	_activeArea.bottom = y2;
	GTexture* texture = new GTexture(BAT_SPRITE, 4, 1, 4);
	_sprite = new GSprite(texture, _ANIMATE_RATE);
	_starty = y;
}

void Bat::MoveUpdate(float deltaTime)
{
#pragma region __XU_LY_CHUYEN_DONG__
	if (this->_isSleep){
		return;
	}

	if (_isMoveleft){
		if (_x <= _activeArea.left ){
			_vx *= -1;
			this->_isMoveleft = !this->_isMoveleft;
			this->_y = this->_starty;
		}
	}
	else{
		if (_x >= _activeArea.right){
			_vx *= -1;
			this->_isMoveleft = !this->_isMoveleft;
			this->_y = this->_starty;
		}
	}
	this->_x += int(this->_vx * deltaTime);
	this->_y += int(7 * sin(float(_x)));
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

void Bat::Draw(){
	if (!this->_isMoveleft){
		this->_sprite->DrawFlipX(_x, _y);
	}
	else{
		this->_sprite->Draw(_x, _y);
	}
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
