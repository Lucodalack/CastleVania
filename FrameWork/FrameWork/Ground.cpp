#include "Ground.h"


Ground::Ground(int type, int x, int y) :
GObject(type, x, y, _WIDTH, _HEIGHT)
{
	_isOnGround = false;
	_isLife = true;
	//_lifeTime = -1;
	_lifeTime = 0; //cái này để test thôi.
	_box = Box(x, y, _WIDTH, _HEIGHT);

}

void Ground::SetFrame(float deltaTime)
{
#pragma region __XU_LY_CHUYEN_DOI_FRAME__
//
#pragma endregion
}

void Ground::Update(float deltatime){
	this->_sprite->Update(deltatime);
}

void Ground::Draw(){
	if (this->_lifeTime < 0){
		return; //chua xuat hien.
	}
	if (this->_lifeTime >= _LIFETIME){
		return;
	}
	else{
		this->_sprite->Draw(_x, _y);
	}
}

void Ground::ChangeState(int state){
//
}
Ground::~Ground(){
	if (_sprite != NULL){
		delete _sprite;
	}
}
