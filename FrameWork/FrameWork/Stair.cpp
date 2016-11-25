#include "Stair.h"



Stair::Stair(int x, int y) :
Ground(TYPE, x, y)
{
	_box = Box(x, y, _stairWIDTH, _stairHEIGHT);
	GTexture* texture = new GTexture(_SPRITE, 1, 1, 1);
	_sprite = new GSprite(texture, _ANIMATE_RATE);

}


void Stair::SetFrame(float deltaTime)
{
#pragma region __XU_LY_CHUYEN_DOI_FRAME__
	this->_sprite->_start = 0;
	this->_sprite->_end = 0;

#pragma endregion
}


Stair::~Stair(){
	if (_sprite != NULL){
		delete _sprite;
	}
}
