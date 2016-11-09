#ifndef _STATE_H_
#define _STATE_H_

#include "Graphics.h"
#include "GTexture.h"
#include <string>
#include <iostream>
#include <fstream>

using namespace std;
#define SIZE 16
#define IMAGE_REF_2 L"TileMap.png"
#define MATRIX_REF_2 "MaTrix.txt"

class State{
	int** _matrix;
	int _col;
	int _row;
	int _listTileCount;
	GTexture* _bgTexture;
	static State* _state;
public:
	State();
	~State();
	static State* getCurrentState();
	void load();
	void draw();
};
#endif