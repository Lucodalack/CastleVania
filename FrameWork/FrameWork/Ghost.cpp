#include "Ghost.h"

Ghost::Ghost(int x, int y,int x2,int y2) :
Enemy(TYPE,x, y, x2, y2)
{
	GTexture* ghosttt = new GTexture(GHOST_SPRITE, 2, 1, 2);
	_sprite = new GSprite(ghosttt, ANIMATIONRATE);
	this->_vx = _ghostSPEED;
}

void Ghost::SetFrame(float deltaTime)
{
#pragma region __XU_LY_CHUYEN_DOI_FRAME__
	this->_sprite->_start = 0;
	this->_sprite->_end = 1;
#pragma endregion
}

Ghost::~Ghost(){
	if (_sprite != NULL){
		delete _sprite;
	}
}
