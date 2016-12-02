#include "Spearguard.h"


Spearguard::Spearguard(int x, int y, int x2, int y2) :
Enemy(TYPE, x, y, x2, y2)
{
	GTexture* tt = new GTexture(SPEARGAURD_SPRITE, 4, 1, 4);
	_sprite = new GSprite(tt, ANIMATIONRATE);
	this->_vx = _guardSPEED;
	this->SetFrame(0);
}

void Spearguard::SetFrame(float deltaTime)
{
#pragma region __XU_LY_CHUYEN_DOI_FRAME__
	this->_sprite->_start = 0;
	this->_sprite->_end = 3;
#pragma endregion
}

Spearguard::~Spearguard(){
	if (_sprite != NULL){
		delete _sprite;
	}
}
