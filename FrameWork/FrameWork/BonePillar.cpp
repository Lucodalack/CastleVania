#include "BonePillar.h"
#include "Simon.h"
#include "FireBall.h"

BonePillar::BonePillar(int x, int y) :
GObject(4, x, y, _WIDTH, _HEIGHT)
{
	_isMoveleft = false;
	_isDead = false;
	_box = Box(x, y, _WIDTH, _HEIGHT);
	_flag1 = false;
	_flag2 = false;
	_flag3 = false;

	GTexture* texture1 = new GTexture(_SPRITE, 1, 1, 1);
	GTexture* texture2 = new GTexture(_SPRITE1, 1, 1, 1);

	_sprite = new GSprite(texture1, 0);

	_fireball1 = new FireBall(_x, _y + 12);
	_fireball2 = new FireBall(_x, _y + 12);
	_fireball3 = new FireBall(_x, _y + 12);



}

void BonePillar::MoveUpdate(float deltaTime)
{
#pragma region __XU_LY_CHUYEN_DONG__
	if (Simon::getCurrentSimon()->_x < this->_x)
		_isMoveleft = true;
	else
		_isMoveleft = false;

}

void BonePillar::SetFrame(float deltaTime)
{
#pragma region __XU_LY_CHUYEN_DOI_FRAME__
	//
#pragma endregion
}

void BonePillar::Update(float deltatime){
	_time += deltatime;
	if (_flag1 == true)
		_fireball1->Update(deltatime);
	if (_flag2 == true)
		_fireball2->Update(deltatime);
	if (_flag3 == true)
		_fireball3->Update(deltatime);
	if (_time >= 2800)
	{
		_fireball1 = new FireBall(_x, _y + 12);
		_fireball2 = new FireBall(_x, _y + 12);
		_fireball3 = new FireBall(_x, _y + 12);
		_flag1 = false;
		_flag2 = false;
		_flag3 = false;

		_time = 0;
	}
	this->MoveUpdate(deltatime);
	this->_sprite->Update(deltatime);
}

void BonePillar::Draw(){
	if (this->_isDead){
		return;
	}
	if (!this->_isMoveleft){
		this->_sprite->DrawFlipX(_x, _y);
	}
	else{
		this->_sprite->Draw(_x, _y);
	}
	if (_time > 400)
	{
		_fireball1->Draw();
		_flag1 = true;
	}
	if (_time > 800)
	{
		_fireball2->Draw();
		_flag2 = true;
	}
	if (_time > 1200)
	{
		_fireball3->Draw();
		_flag3 = true;
	}
}
BonePillar::~BonePillar(){
	if (_sprite != NULL){
		delete _sprite;
	}
}

