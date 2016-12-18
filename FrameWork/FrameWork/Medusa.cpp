#include "Medusa.h"
#include "Simon.h"

Medusa::Medusa(int x, int y) :
GObject(1, x, y, _WIDTH, _HEIGHT)
{
	last_x = x;
	_vx = 0.2f;
	_isSleep = true;
	_box = Box(x, y, _WIDTH, _HEIGHT, _vx, _vy);
	GTexture* texture = new GTexture(_SPRITE, 5, 1, 5);
	_sprite = new GSprite(texture, 7);
	//int w = x2 - x;
	//int h = y2 - y;
	//_awakeBox = Box(x, y, w, h, 0, 0);
	//_tamp = 0;
	//_hp = HP;
	_flag1 = false;
}

void Medusa::MoveUpdate(float deltaTime)
{
#pragma region __XU_LY_CHUYEN_DONG__
	int ynek = Simon::getCurrentSimon()->_y;

	if (Simon::getCurrentSimon()->_x < (this->_x))
	{
		flag = true;
	}
	if (this->_isSleep){
		return;
	}
	if (Simon::getCurrentSimon()->_x >= _x)
		_isMoveleft = false;
	else
		_isMoveleft = true;



	if (_isMoveleft){

		if (Simon::getCurrentSimon()->_x - _x <= -128)
		{
			if (_vx < 0)
				_vx = -0.1f;
			else
				_vx = 0.1f;
			this->_y = ynek;
		}
		if (Simon::getCurrentSimon()->_x + 32 >= _x)
		{
			if (_vx < 0)
				_vx = 0.1f;
			else
				_vx = -0.1f;
			this->_y = ynek;

		}
		if (_x >= last_x && _vx>0)
		{
			if (_vx < 0)
				_vx = 0.1f;
			else
				_vx = -0.1f;
			this->_y = ynek;

		}
	}
	else{
		if (Simon::getCurrentSimon()->_x - _x <= 128)
		{
			if (_vx < 0)
				_vx = -0.1f;
			else
				_vx = 0.1f;

			this->_y = ynek;
		}

		if (Simon::getCurrentSimon()->_x <= _x + 32)
		{
			if (_vx < 0)
				_vx = 0.1f;
			else
				_vx = -0.1f;
			this->_y = ynek;

		}
		if (_x <= last_x && _vx<0)
		{
			if (_vx < 0)
				_vx = 0.1f;
			else
				_vx = -0.1f;
			this->_y = ynek;

		}
	}

	this->_x += int(this->_vx * deltaTime);
	this->_tamp += (this->_vx * deltaTime / 10);
	/*if (_y < _activeArea.top || _y > _activeArea.bottom)
	this->_y -= int(3 * sin(float(_tamp)));*/
	//if (!(_y <= ynek || _y >= ynek))
	//	this->_y += int(3 * sin(float(_tamp)));
	//int sign = abs(sin(float(_tamp))) / sin(float(_tamp));
	this->_y += int(8 * sin(float(_tamp)));
#pragma endregion
	_box.x = _x;
	_box.y = _y;
	_box.vx = _vx;
	_box.vy = _vy;
}

void Medusa::SetFrame(float deltaTime)
{
#pragma region __XU_LY_CHUYEN_DOI_FRAME__
	if (this->_isSleep){
		this->_sprite->_start = 4;
		this->_sprite->_end = 4;
	}
	else{
		this->_sprite->_start = 0;
		this->_sprite->_end = 3;
	}
#pragma endregion
}

void Medusa::Update(float deltatime){
	//if (_hp == 0) {
	//	this->_isDead = true;
	//	this->_timeDeath += deltatime;
	//	this->_spriteDeath->Update(deltatime);
	//}


	if (flag == true && _timesleep >= 0)
		_timesleep -= deltatime;
	if (_timesleep < 0)
		ChangeState(2);

	if (this->_isDead){
		return;
	}
	this->MoveUpdate(deltatime);
	this->SetFrame(deltatime);
	this->_sprite->Update(deltatime);
}

void Medusa::ChangeState(int state){
	if (state == MEDUSASTATE::IS_SLEEPING){
		this->_isSleep = true;
	}
	else
	if (state == MEDUSASTATE::IS_LIVING){
		this->_isSleep = false;
	}
}

void Medusa::Draw(){
	this->_sprite->Draw(_x, _y);
}


Medusa::~Medusa(){
	if (_sprite != NULL){
		delete _sprite;
	}
}
#include "Medusa.h"
#include "Simon.h"

Medusa::Medusa(int x, int y) :
GObject(1, x, y, _WIDTH, _HEIGHT)
{
	last_x = x;
	_vx = 0.2f;
	_isSleep = true;
	_box = Box(x, y, _WIDTH, _HEIGHT, _vx, _vy);
	GTexture* texture = new GTexture(_SPRITE, 5, 1, 5);
	_sprite = new GSprite(texture, 7);
	//int w = x2 - x;
	//int h = y2 - y;
	//_awakeBox = Box(x, y, w, h, 0, 0);
	//_tamp = 0;
	//_hp = HP;
	_flag1 = false;
}

void Medusa::MoveUpdate(float deltaTime)
{
#pragma region __XU_LY_CHUYEN_DONG__
	int ynek = Simon::getCurrentSimon()->_y;

	if (Simon::getCurrentSimon()->_x < (this->_x))
	{
		flag = true;
	}
	if (this->_isSleep){
		return;
	}
	if (Simon::getCurrentSimon()->_x >= _x)
		_isMoveleft = false;
	else
		_isMoveleft = true;



	if (_isMoveleft){

		if (Simon::getCurrentSimon()->_x - _x <= -128)
		{
			if (_vx < 0)
				_vx = -0.1f;
			else
				_vx = 0.1f;
			this->_y = ynek;
		}
		if (Simon::getCurrentSimon()->_x + 32 >= _x)
		{
			if (_vx < 0)
				_vx = 0.1f;
			else
				_vx = -0.1f;
			this->_y = ynek;

		}
		if (_x >= last_x && _vx>0)
		{
			if (_vx < 0)
				_vx = 0.1f;
			else
				_vx = -0.1f;
			this->_y = ynek;

		}
	}
	else{
		if (Simon::getCurrentSimon()->_x - _x <= 128)
		{
			if (_vx < 0)
				_vx = -0.1f;
			else
				_vx = 0.1f;

			this->_y = ynek;
		}

		if (Simon::getCurrentSimon()->_x <= _x + 32)
		{
			if (_vx < 0)
				_vx = 0.1f;
			else
				_vx = -0.1f;
			this->_y = ynek;

		}
		if (_x <= last_x && _vx<0)
		{
			if (_vx < 0)
				_vx = 0.1f;
			else
				_vx = -0.1f;
			this->_y = ynek;

		}
	}

	this->_x += int(this->_vx * deltaTime);
	this->_tamp += (this->_vx * deltaTime / 10);
	/*if (_y < _activeArea.top || _y > _activeArea.bottom)
	this->_y -= int(3 * sin(float(_tamp)));*/
	//if (!(_y <= ynek || _y >= ynek))
	//	this->_y += int(3 * sin(float(_tamp)));
	//int sign = abs(sin(float(_tamp))) / sin(float(_tamp));
	this->_y += int(8 * sin(float(_tamp)));
#pragma endregion
	_box.x = _x;
	_box.y = _y;
	_box.vx = _vx;
	_box.vy = _vy;
}

void Medusa::SetFrame(float deltaTime)
{
#pragma region __XU_LY_CHUYEN_DOI_FRAME__
	if (this->_isSleep){
		this->_sprite->_start = 4;
		this->_sprite->_end = 4;
	}
	else{
		this->_sprite->_start = 0;
		this->_sprite->_end = 3;
	}
#pragma endregion
}

void Medusa::Update(float deltatime){
	//if (_hp == 0) {
	//	this->_isDead = true;
	//	this->_timeDeath += deltatime;
	//	this->_spriteDeath->Update(deltatime);
	//}


	if (flag == true && _timesleep >= 0)
		_timesleep -= deltatime;
	if (_timesleep < 0)
		ChangeState(2);

	if (this->_isDead){
		return;
	}
	this->MoveUpdate(deltatime);
	this->SetFrame(deltatime);
	this->_sprite->Update(deltatime);
}

void Medusa::ChangeState(int state){
	if (state == MEDUSASTATE::IS_SLEEPING){
		this->_isSleep = true;
	}
	else
	if (state == MEDUSASTATE::IS_LIVING){
		this->_isSleep = false;
	}
}

void Medusa::Draw(){
	this->_sprite->Draw(_x, _y);
}


Medusa::~Medusa(){
	if (_sprite != NULL){
		delete _sprite;
	}
}
