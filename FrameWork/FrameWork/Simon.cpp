#include "Simon.h"



Simon* Simon::_simon = 0;
Simon::Simon(int x, int y) :
GObject(TYPE, x, y, SIMON_WIDTH, SIMON_HEIGHT)
{

}

void Simon::run(int x, int y)
{
	_x += x;
	_y += y;
}
void Simon::draw()
{
	_leftSprite->Draw(_x, _y);
}
Simon* Simon::getCurrentSimon(){
	if (!_simon)
		_simon = new Simon(50, 50);
	return _simon;
}




