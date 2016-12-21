#include "Simon.h"



Simon* Simon::_simon = 0;
Simon::Simon(int x, int y) :
GObject(TYPE, x, y, SIMON_WIDTH, SIMON_HEIGHT)
{
	_isMoveleft = true;
	_isMoveright = false;
	_isOnStair = false;
	_isJumping = false;
	_isFalling = true;
	_isSiting = false;
	_canGoStair = false;
	_currentLV = 1;
	_canGoLeft = true;
	_canGoRight = true;
	onGoto = false;
	_hp = 16;
	_heart = 5;
	_stateCurrent = STATE::IS_FALLING;
	_vy = GRAVITY;
	_box = Box(x, y, SIMON_WIDTH, SIMON_HEIGHT,_vx,_vy);
	
	GTexture* simonTT = new GTexture(SIMON_SPRITE, 8, 3, 24,false);
	_sptrite = new GSprite(simonTT, SIMON_Animation_RATE);
}

void Simon::MoveUpdate(float deltaTime)
{
	if (_hp <= 0) return;
	float d = 1.0;
	if (_isJumping && _isFighting)
		d = 1.0;
#pragma region __XU_LY_CHUYEN_DONG__

	if (this->_isFighting) {
		if (Whip::getCurrentWhip()->_done)
			_isFighting = false;
		if (!(this->_isJumping||this->_isFalling))
			return;
		/*if (!this->_stateCurrent==STATE::IS_JUMPFIGH)
			return;*/
	}

	if (this->_stateCurrent == STATE::CANT_HURT){
		//this->_x += int(this->_vx * deltaTime);
		if (_isMoveleft&&_canGoRight){
			this->_x += int(this->_vx * deltaTime*d);
		}
		if (_isMoveright&&_canGoLeft)
		{
			this->_x += int(this->_vx * deltaTime*d);
		}
		this->_y += int(this->_vy * deltaTime);
		if (_vy<GRAVITY)
		_vy += 0.2f;
		this->onGoto = false;
		_box.x = _x;
		_box.y = _y;
		_box.vx = _vx;
		_box.vy = _vy;
		return;
	}
	if (this->_stateCurrent == STATE::ON_BRICK_MOVING)
	{
		this->_x += int(this->_vx * deltaTime*d);
		//this->_vx = _currentMoving.vx;
		_box.x = _x;
		_box.y = _y;
		_box.vx = _vx;
		_box.vy = _vy;
		return;
	}
	//Kiem tra doi tuong co nhay duoc hay ko
	if (this->_isOnStair)
	{
		this->_x += int(this->_vx * deltaTime*d);
		this->_y += int(this->_vy * deltaTime);
		
		if ((this->_x >= this->xDestinate) && (this->_vx>0))
		this->_vx = 0;
		if ((this->_y >= this->yDestinate) && (this->_vy>0))
			this->_vy = 0;
		if ((this->_x <= this->xDestinate) && (this->_vx<0))
			this->_vx = 0;
		if ((this->_y <= this->yDestinate) && (this->_vy<0))
			this->_vy = 0;
		
		if (this->_vx == 0 && this->_vx == 0)
			this->onGoto = false;
	}
	else
	{
		
		if (this->_stateCurrent == STATE::IS_STANDING)
		{
			this->_vx = 0;
			_vy = GRAVITY;
		}
		else
		{
			if (this->_isFalling){
				_vy = GRAVITY;
				this->_y += int(_vy*deltaTime);
				if (this->_lastState == STATE::IS_JUMPING || this->_lastState == STATE::IS_JUMPFIGH)
				if ((this->_vx>0 && this->_canGoRight) || (this->_vx<0 && this->_canGoLeft))
				this->_x += int(this->_vx * deltaTime*d/1.5f );
			}
		}

		if (this->_isMoveleft&&this->_canGoLeft&&!this->_isFalling)
		{
			if (this->_vx < 0)
			{
				this->_x += int(this->_vx * deltaTime*d);
			}
		}
		else if (this->_isMoveright&&this->_canGoRight&&!this->_isFalling)
		{
			if (this->_vx > 0)
			{
				this->_x += int(this->_vx * deltaTime*d);
			}
		}
		if (this->_stateCurrent == STATE::IS_JUMPING || this->_stateCurrent == STATE::IS_JUMPFIGH){
			this->_y += int(this->_vy * deltaTime);
			if ((this->_vx>0 && this->_canGoRight) || (this->_vx<0 && this->_canGoLeft))
				this->_x += int(this->_vx * deltaTime*d / 1.5f);
			if (_vy < -0.3)
				_vy += 0.2f;
			else {
				this->_stateCurrent = STATE::IS_FALLING;
				this->_lastState = STATE::IS_JUMPING;
				_isFalling = true;
				_isJumping = false;
			}
		}
		_canGoRight = true;
		_canGoLeft = true;
	}
#pragma endregion
	_box.x = _x;
	_box.y = _y;
	_box.vx = _vx;
	_box.vy = _vy;
}

void Simon::SetFrame(float deltaTime)
{
	if (_hp <= 0){
		this->_sptrite->_start = 9;
		this->_sptrite->_end = 9;
		return;
	}

#pragma region __XU_LY_CHUYEN_DOI_FRAME__

	if (!this->_isOnStair) //dang o duoi dat
	{
		this->_sptrite->_start = 0;
		this->_sptrite->_end = 0;
		switch (this->_stateCurrent)
		{
		case STATE::IS_STANDING:
		{
								   this->_sptrite->_start = 0;
								   this->_sptrite->_end = 0;
								   if (_isFighting){
									   this->_sptrite->_start = 5;
									   this->_sptrite->_end = 7;
								   }
								   break;
		}
		case STATE::IS_JOGGING://Chay bo
		{
								   this->_sptrite->_start = 0;
								   this->_sptrite->_end = 3;
								   break;
		}
		case STATE::IS_JUMPING: 
		case STATE::IS_SITTING :
		{
								  this->_sptrite->_start = 4;
								  this->_sptrite->_end = 4;
								  break;
		}
		case STATE::IS_FIGHTING:
		{
									this->_sptrite->_start = 5;
									this->_sptrite->_end = 7;
									break;
		}
		case STATE::IS_PASSGATE	:
		{
									this->_sptrite->_start = 9;
									this->_sptrite->_end = 9;
									break;
		}
		case STATE::IS_SITFIGHT: 
		case STATE::IS_JUMPFIGH:
		{
								   this->_sptrite->_start = 15;
								   this->_sptrite->_end = 17;
								   break;
		}
		case STATE::CANT_HURT:{
								  this->_sptrite->_start = 8;
								  this->_sptrite->_end = 8;
								  break;
		}
		default:
		{
				   break;
		}
		}
	}
	else //tren cau thang
	{
		if (_stateCurrent == STATE::IS_STANDING)
			_stateCurrent = STATE::IS_DOWNING;
		if (this->_isMoveleft)
			_stateCurrent = STATE::IS_DOWNING;
		if (this->_isMoveright)
			_stateCurrent = STATE::IS_UPING;
		switch (this->_stateCurrent)
		{
		
		case STATE::IS_UPING:
		{
								if (onGoto){
									this->_sptrite->_start = 12;
									this->_sptrite->_end = 13;
								}
								else
								{
									this->_sptrite->_start = 12;
									this->_sptrite->_end = 12;
								}
								
								break;
		}
		case STATE::IS_DOWNING:
		{
								  if (onGoto){
									  this->_sptrite->_start = 10;
									  this->_sptrite->_end = 11;
								  }
								  else
								  {
									  this->_sptrite->_start = 10;
									  this->_sptrite->_end = 10;
								  }
								
								  break;
		}
		case STATE::IS_UPFIGHT:
		{
								  this->_sptrite->_start = 21;
								  this->_sptrite->_end = 23;
								  break;
		}
		case STATE::IS_DOWNFIGHT:
		{
									this->_sptrite->_start = 18;
									this->_sptrite->_end = 20;
									break;
		}
		case STATE::CANT_HURT:{
								  this->_sptrite->_start = 8;
								  this->_sptrite->_end = 8;
								  break;
		}
		default:
			break;
		}
	}
#pragma endregion
}

void Simon::Jump(){
	if (_hp <= 0)
		return;
	if (!_isJumping){
		if (this->_isFighting ){
			this->_stateCurrent = STATE::IS_JUMPFIGH;
		}
		else
		{
			this->_stateCurrent = STATE::IS_JUMPING;
		}
		_vy = -3.0f;
		_isJumping = true;
		if (KeyBoard::getCurrentKeyBoard()->IsKeyDown(DIK_RIGHT))
			this->_vx = SIMON_SPEED;
		if (KeyBoard::getCurrentKeyBoard()->IsKeyDown(DIK_LEFT))
			this->_vx = -SIMON_SPEED;
	}
}

void Simon::Fight(){
	if (_hp <= 0)
		return;
	Whip::getCurrentWhip()->_done = false;
#pragma region __XU_LY_PHIM_DANH__
	if (!this->_isFighting)
	{
		this->_lastState = this->_stateCurrent;
		this->_isFighting = true;

		switch (this->_stateCurrent)
		{
		case STATE::IS_JUMPING:
			this->_stateCurrent = STATE::IS_JUMPFIGH;
			break;
		case STATE::IS_SITTING:
			this->_stateCurrent = STATE::IS_SITFIGHT;
			break;
		case STATE::IS_DOWNING:
			this->_stateCurrent = STATE::IS_DOWNFIGHT;
			break;
		case STATE::IS_UPING:
			this->_stateCurrent = STATE::IS_UPFIGHT;
			break;
		default:
			this->_stateCurrent = STATE::IS_SITFIGHT;
			break;
		}
	}
#pragma endregion
}

void Simon::InputUpdate(float deltaTime)
{
	if (_hp <= 0)
		return;
	if (this->_isFighting){
		return;
	}
	
#pragma region __KHONG_CO_SU_KIEN_PHIM__
	
	this->_keyDown = KeyBoard::getCurrentKeyBoard()->GetKeyDown();
	this->_keyUp = KeyBoard::getCurrentKeyBoard()->GetKeyUp();
	if (!this->_isJumping)
	{
		
		//this->_vy = 0;

		if (!this->_isOnStair&&!this->_isFalling && (this->_stateCurrent != STATE::CANT_HURT) && (this->_stateCurrent != STATE::ON_BRICK_MOVING))
		{
			this->_vx = 0;
			//this->_stateCurrent = STATE::IS_FALLING;
		}
		else
		{

		}
		if (this->_stateCurrent != STATE::IS_FALLING 
			&& !this->_isFighting 
			&& (this->_stateCurrent != STATE::IS_UPING)
			&& (this->_stateCurrent != STATE::IS_DOWNING)
			&& (this->_stateCurrent != STATE::CANT_HURT)
			&& (this->_stateCurrent != STATE::ON_BRICK_MOVING)
			)
			_stateCurrent = STATE::IS_STANDING;
	}
	this->_isSiting = false;
#pragma endregion


#pragma region __XU_LY_PHIM_DI_QUA_TRAI_HOAC_PHAI__
	if (this->_stateCurrent == STATE::CANT_HURT) return;
	if (this->_isOnStair) return;
	if ((KeyBoard::getCurrentKeyBoard()->keyLeft() || KeyBoard::getCurrentKeyBoard()->keyRight())
		&& this->_stateCurrent != STATE::IS_JUMPING&& this->_stateCurrent != STATE::IS_FALLING)
	{
		this->_stateCurrent = STATE::IS_JOGGING;
		if (KeyBoard::getCurrentKeyBoard()->keyRight())
		{
			this->_isMoveright = true;
			this->_isMoveleft = false;
			this->_vx = SIMON_SPEED;
		}
		else
		{
			this->_isMoveright = false;
			this->_isMoveleft = true;
			this->_vx = -SIMON_SPEED;
		}
	}
#pragma endregion

	//this->_stateCurrent = STATE::IS_FIGHTING;

#pragma region __XU_LY_PHIM_DI_LEN_ XUONG__
	if (KeyBoard::getCurrentKeyBoard()->keyUp()){
		//chua lam
	}
	if (KeyBoard::getCurrentKeyBoard()->keyDown()){
		if (_canGoStair){
			this->_stateCurrent = STATE::IS_DOWNING;
		}
		else{
				this->_stateCurrent = STATE::IS_SITTING;
				this->_isSiting = true;
		}
	}
#pragma endregion


}

void Simon::Update(float deltatime){
	if (_hp <= 0){
		_timeDeath += deltatime;
		_isDeath = true;
	}
		
	this->InputUpdate(deltatime);
	this->SetFrame(deltatime);
	this->MoveUpdate(deltatime);
	MoveState();
	this->_sptrite->Update(deltatime);
	if (_isFighting){
		Whip::getCurrentWhip()->Update(deltatime);
	}
}

void Simon::MoveState(){
	if (_hp <= 0)
		return;
	if (!_isOnStair) return;
	switch (_currentLV)
	{
	case 1:
		if (_y < 1220){
			this->ChangeState(STATE::IS_UPING);
			this->isMoveLeft(false);
			this->isMoveRight(true);
			this->_isOnStair = true;
			this->onGoto = true;
			this->_x =3841;
			this->_y = 1140;
			GCamera::getCurrentCamera()->ChangeState(2);
			_currentLV = 2;
			return;
		}
		break;
	case 2:
		if (_y < 833){
			this->ChangeState(STATE::IS_UPING);
			this->isMoveLeft(false);
			this->isMoveRight(true);
			this->_isOnStair = true;
			this->onGoto = true;
			this->_x = 1664;
			this->_y = 753;
			GCamera::getCurrentCamera()->ChangeState(3);
			_currentLV = 3;
			return;
		}
		break;
	case 3:
		if (_y < 450){
			this->ChangeState(STATE::IS_UPING);
			this->isMoveLeft(false);
			this->isMoveRight(true);
			this->_isOnStair = true;
			this->onGoto = true;
			this->_x = 1343;
			this->_y = 369;
			GCamera::getCurrentCamera()->ChangeState(4);
			_currentLV = 4;
			return;
		}
		break;
	default:
		break;
	}
}

void Simon::Draw(){
	if (_timeDeath > DEATH_TIME)
		return;
	int d = (this->_stateCurrent == STATE::IS_SITFIGHT || this->_stateCurrent == STATE::IS_SITTING) ? 20 : 0;
	if (this->_isMoveright){
		this->_sptrite->DrawFlipX(_x-10, _y+d);
	}
	else{
		this->_sptrite->Draw(_x-11, _y+d);
	}
	Whip::getCurrentWhip()->Draw();
}

void Simon::ChangeState(int state){
	//if (_stateCurrent == STATE::IS_UPING&& state == STATE::IS_STANDING) return;
	_lastState = _stateCurrent;
	if (_lastState == STATE::CANT_HURT){

		this->_hp -= 1;
	}
	this->_stateCurrent = state;
	switch (state) {
	case STATE::IS_STANDING:
		this->_isFalling = false; 
		this->_isJumping = false; 
		if (this->_isSiting)
			this->_stateCurrent = STATE::IS_SITTING;
		break;
	case STATE::IS_FALLING: this->_isFalling = true;
		this->_isJumping = false;  break;
	case STATE::IS_UPING: this->_isOnStair = true;
		if (this->_vy == GRAVITY) this->_vy = 0; break;
	case STATE::IS_DOWNING: this->_isOnStair = true;
		if (this->_vy == GRAVITY) this->_vy = 0; break;
	case STATE::CANT_HURT: 
		this->_isOnStair = false;
		if (_isMoveleft&&_canGoRight){
			this->_vx = 1.2f;
			this->_x += int(this->_vx * 3);
		}
		if (_isMoveright&&_canGoLeft)
		{
			this->_vx = -1.2f;
			this->_x += int(this->_vx * 3);
		}
		this->_vy = -2.0f;
		
		this->_y += int(this->_vy * 3);
		this->_box.x = this->_x;
		this->_box.y = this->_y;
		this->_box.vx = this->_vx;
		this->_box.vy = this->_vy;
		break;
	case STATE::ON_BRICK_MOVING:
		this->_isFalling = false;
		this->_isJumping = false; break;
	}
}

Simon* Simon::getCurrentSimon(){
	if (!_simon)
		_simon = new Simon(3742, 1453);
	return _simon;
}




