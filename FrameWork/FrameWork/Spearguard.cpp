#include "Spearguard.h"


Spearguard::Spearguard(int x, int y, int x2, int y2) :
Enemy(TYPE, x, y, x2, y2)
{
	GTexture* tt = new GTexture(SPEARGAURD_SPRITE, 4, 1, 4);
	_sprite = new GSprite(tt, 10);
	this->_vx = _guardSPEED;
	this->SetFrame(0);
	_box = Box(x, y, _guardWIDTH, _guardHEIGHT, _vx, _vy);
	_hp = HP;
}

void Spearguard::SetFrame(float deltaTime)
{
#pragma region __XU_LY_CHUYEN_DOI_FRAME__
	this->_sprite->_start = 0;
	this->_sprite->_end = 3;
#pragma endregion
}
void Spearguard::Collistion(float deltaTime)
{
	if (_isDead) return;
	float x, y; 
	if (Simon::getCurrentSimon()->GetState() == STATE::CANT_HURT)
		return;
	if (Simon::getCurrentSimon()->isFighting()){
		if (swepyAABB->AABB(this->_box, Whip::getCurrentWhip()->_box, x, y)){
			if (_hp>0)
			_hp--;
		}
	}
	if (swepyAABB->AABB(this->_box, Simon::getCurrentSimon()->_box, x, y)){
		swepyAABB->AABB(this->_box, Simon::getCurrentSimon()->_box, x, y);
		Simon::getCurrentSimon()->ChangeState(STATE::CANT_HURT);
	}
	////swepyAABB->SweptAABB(this->_box, Whip::getCurrentWhip()->_box, x, y, deltaTime);
	//if (swepyAABB->AABB(this->_box, Whip::getCurrentWhip()->_box, x, y)){
	//	if (Simon::getCurrentSimon()->isFighting()){
	//		//Simon::getCurrentSimon()->ChangeState(STATE::IS_FIGHTING);
	//		_hp--;
	//	}
	//	
	//}
}
Spearguard::~Spearguard(){
	if (_sprite != NULL){
		delete _sprite;
	}
}

