#include "DoubleShot.h"



DoubleShot::DoubleShot(int x, int y, int x2, int y2) :
Item(TYPE, x, y, x2, y2)
{
	//random ra mau
	int tempt = int(time(NULL));
	if (tempt % 2 == 0){
		GTexture* texture = new GTexture(_SPRITE_BLUE, 1, 1, 1);
		_sprite = new GSprite(texture, ANIMATIONRATE);
		_doubleshotcolor = DoubleShotColor::ShotBlue;
	}
	else{
		GTexture* texture = new GTexture(_SPRITE_RED, 1, 1, 1);
		_sprite = new GSprite(texture, ANIMATIONRATE);
		_doubleshotcolor = DoubleShotColor::ShotRed;
	}
	this->SetFrame(0); // nếu chỉ có 1 ô hình thì quất thế này luôn cho nhanh.
}

DoubleShot::~DoubleShot(){
	if (_sprite != NULL){
		delete _sprite;
	}
}
