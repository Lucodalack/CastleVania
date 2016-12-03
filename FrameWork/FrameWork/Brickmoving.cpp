#include "Brickmoving.h"


Brickmoving::Brickmoving(int x, int y, int x2, int y2) :
Enemy(TYPE, x, y, x2, y2)
{	
	_vx = _mvbSPEED;
	_box = Box(x, y, _mvbWIDTH, _mvbHEIGHT, _vx, _vy);
	GTexture* texture = new GTexture(_SPRITE, 1, 1, 1);
	_sprite = new GSprite(texture, ANIMATIONRATE);
}

void Brickmoving::MoveUpdate(float deltaTime)
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

void Brickmoving::SetFrame(float deltaTime)
{
#pragma region __XU_LY_CHUYEN_DOI_FRAME__
		this->_sprite->_start = 0;
		this->_sprite->_end = 0;
#pragma endregion
}

void Brickmoving::Update(float deltatime){
	this->MoveUpdate(deltatime);
	this->SetFrame(0);
	this->_sprite->Update(deltatime);
}


Brickmoving::~Brickmoving(){
	if (_sprite != NULL){
		delete _sprite;
	}
}