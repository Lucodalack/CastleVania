#include "Fireandle.h"



Fireandle::Fireandle(int x, int y) :
Ground(TYPE, x, y)
{
	_box = Box(x, y, _WIDTH, _HEIGHT);
	GTexture* texture = new GTexture(_SPRITE, 2, 1, 2);
	_sprite = new GSprite(texture, _ANIMATE_RATE);

}


void Fireandle::SetFrame(float deltaTime)
{
#pragma region __XU_LY_CHUYEN_DOI_FRAME__
		this->_sprite->_start = 0;
		this->_sprite->_end = 1;

#pragma endregion
}


Fireandle::~Fireandle(){
	if (_sprite != NULL){
		delete _sprite;
	}
}
