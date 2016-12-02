//#include "Whip.h"
//
//Whip::Whip(int x, int y) :
//GObject(TYPE, x, y, _WIDTH, _HEIGHT)
//{
//	_box = Box(x, y, _WIDTH, _HEIGHT, _vx, _vy);
//	GTexture* tt = new GTexture(_SPRITE, 3, 3, 9);
//	_sprite = new GSprite(tt, _ANIMATE_RATE);
//}
//
//void Whip::MoveUpdate(float deltaTime)
//{
//#pragma region __XU_LY_CHUYEN_DONG__
//	
//#pragma endregion
//	_box.x = _x;
//	_box.y = _y;
//	_box.vx = _vx;
//	_box.vy = _vy;
//}
//
//void Whip::SetFrame(float deltaTime)
//{
//#pragma region __XU_LY_CHUYEN_DOI_FRAME__
//	this->_sprite->_start = 0;
//	this->_sprite->_end = 2;
//#pragma endregion
//}
//
//void Simon::Update(float deltatime){
//	this->MoveUpdate(deltatime);
//	this->SetFrame(deltatime);
//	this->_sptrite->Update(deltatime);
//}
//
//void Simon::Draw(){
//	if (this->_isMoveright){
//		this->_sptrite->DrawFlipX(_x, _y);
//	}
//	else{
//		this->_sptrite->Draw(_x, _y);
//	}
//}
//
//
//
//
//
