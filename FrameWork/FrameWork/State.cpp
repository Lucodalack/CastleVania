#include "State.h"

State* State::_state = 0;
State::State(){}
State::~State(){}
void State::load(){
	string line;
	ifstream myfile(MATRIX_REF_2);
	myfile >> _listTileCount;
	myfile >> _col;
	myfile >> _col;
	myfile >> _col;
	myfile >> _row;
	_matrix = new int * [_row];
	for (int i = 0; i < _row; i++){
		_matrix[i] = new int[_col];
	}
	for (int i = 0; i < _row; i++)
	{
		for (int j = 0; j < _col; j++){
			myfile >> _matrix[i][j];
		}
	}
	_bgTexture = new GTexture(IMAGE_REF_2, _listTileCount, 1, _listTileCount);
}
void State::draw(){
	for (int i = 0; i < _row; i++) {
		for (int j = 0; j < _col; j++) {

			int index = _matrix[i][j];

			RECT srect;
			srect.left = index*SIZE;
			srect.top = 0;
			srect.right = srect.left + SIZE ;
			srect.bottom = srect.top + SIZE;

			D3DXVECTOR3 position(float(j * SIZE), float(i * SIZE), 0.0f);
			/*D3DXMATRIX mat;
			D3DXVECTOR2 center((float)(j * SIZE * 2 + SIZE), (float)(i * SIZE * 2 + SIZE));
			D3DXVECTOR2 scale = D3DXVECTOR2(2.0f, 2.0f);
			D3DXMatrixTransformation2D(&mat, &center, 0.0f, &scale, NULL, 0.0f, NULL);
			Graphics::getCurGraphics()->_sprite->SetTransform(&mat);*/
			Graphics::getCurGraphics()->_sprite->Draw(
				_bgTexture->Texture,
				&srect,
				NULL,
				&position,
				0xFFFFFFFF
				);
		}
	}
}
State* State::getCurrentState(){
	if (!_state){
		_state = new State();
		_state->load();
	}
	return _state;

}