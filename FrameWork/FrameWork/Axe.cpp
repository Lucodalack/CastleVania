#include "Axe.h"



Axe::Axe(int x, int y, int x2, int y2) :
Item(TYPE, x, y, x2, y2)
{
	GTexture* texture = new GTexture(_SPRITE, 1, 1, 1);
	_sprite = new GSprite(texture, ANIMATIONRATE);
	this->SetFrame(0); // nếu chỉ có 1 ô hình thì quất thế này luôn cho nhanh.
}
Axe::~Axe(){
	if (_sprite != NULL){
		delete _sprite;
	}
}
