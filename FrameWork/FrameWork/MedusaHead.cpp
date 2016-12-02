#include "MedusaHead.h"


MedusaHead::MedusaHead(int x, int y, int x2, int y2) :
Enemy(TYPE, x, y, x2, y2)
{
	_vx = _medusaheadSPEED;
	_box = Box(x, y, _medusaheadWIDTH, _medusaheadHEIGHT, _vx, _vy);
	GTexture* texture = new GTexture(MEDUSAHEAD_SPRITE, 2, 1, 2);
	_sprite = new GSprite(texture, ANIMATIONRATE);
	this->SetFrame(0);
}

void MedusaHead::MoveUpdate(float deltaTime)
{
#pragma region __XU_LY_CHUYEN_DONG__
	int ynek = this->_activeArea.top - (this->_activeArea.bottom - this->_activeArea.top) / 2;

	if (this->_y <= ynek){
		_vy = 2 * _medusaheadSPEED;
		this->_y += int(deltaTime*_vy);
		return; // con nay ddang roi xuong 1 doan cho bang thang simon roi moi bay
	}
	if (_isMoveleft){
		if (_x <= _activeArea.left){
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
	this->_y += int(15 * sin(float(_x)));
#pragma endregion
	_box.x = _x;
	_box.y = _y;
	_box.vx = _vx;
	_box.vy = _vy;
}

void MedusaHead::SetFrame(float deltaTime)
{
#pragma region __XU_LY_CHUYEN_DOI_FRAME__
	this->_sprite->_start = 0;
	this->_sprite->_end = 1;
#pragma endregion
}

void MedusaHead::Update(float deltatime){
	this->MoveUpdate(deltatime);
	this->_sprite->Update(deltatime);
}

MedusaHead::~MedusaHead(){
	if (_sprite != NULL){
		delete _sprite;
	}
}
