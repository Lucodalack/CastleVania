#include "Brickhidden.h"



Brickhidden::Brickhidden(int x, int y) :
Ground(TYPE, x, y)
{
	_box = Box(x, y, _WIDTH, _HEIGHT);
	GTexture* texture = new GTexture(_SPRITE, 1, 1, 1);
	_sprite = new GSprite(texture, _ANIMATE_RATE);

}


void Brickhidden::SetFrame(float deltaTime)
{
#pragma region __XU_LY_CHUYEN_DOI_FRAME__
	this->_sprite->_start = 0;
	this->_sprite->_end = 0;

#pragma endregion
}


Brickhidden::~Brickhidden(){
	if (_sprite != NULL){
		delete _sprite;
	}
}
