#include "Spearguard.h"



Spearguard::Spearguard(int x, int y, int x2, int y2) :
GObject(TYPE, x, y, _WIDTH, _HEIGHT)
{
	_isMoveleft = false;
	_isDead = false;
	_vy = GRAVITY;
	_vx = _SPEED;
	_box = Box(x, y, _WIDTH, _HEIGHT, _vx, _vy);
	_activeArea.top = y;
	_activeArea.left = x;
	_activeArea.right = x2;
	_activeArea.bottom = y2;
	GTexture* ghosttt = new GTexture(SPEARGUARD_SPRITE, 4, 1, 4);
	_sprite = new GSprite(ghosttt, _ANIMATE_RATE);
	this->SetFrame(0);
}

void Spearguard::MoveUpdate(float deltaTime)
{
#pragma region __XU_LY_CHUYEN_DONG__
	if (_isMoveleft){
		if (_x <= _activeArea.left){
			_vx *= -1;
			this->_isMoveleft = !this->_isMoveleft;
		}
	}
	else{
		if (_x >= _activeArea.right){
			_vx *= -1;
			this->_isMoveleft = !this->_isMoveleft;
		}
	}

	this->_x += int(this->_vx * deltaTime);
#pragma endregion
	_box.x = _x;
	_box.y = _y;
	_box.vx = _vx;
	_box.vy = _vy;
}

void Spearguard::SetFrame(float deltaTime)
{
#pragma region __XU_LY_CHUYEN_DOI_FRAME__
	this->_sprite->_start = 0;
	this->_sprite->_end = 3;
#pragma endregion
}

void Spearguard::Update(float deltatime){
	this->MoveUpdate(deltatime);
	this->_sprite->Update(deltatime);
}

void Spearguard::Draw(){
	if (!this->_isMoveleft){
		this->_sprite->DrawFlipX(_x, _y);
	}
	else{
		this->_sprite->Draw(_x, _y);
	}
}
Spearguard::~Spearguard(){
	if (_sprite != NULL){
		delete _sprite;
	}
}
