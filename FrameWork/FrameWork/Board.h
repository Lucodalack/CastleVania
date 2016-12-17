#ifndef _BOARD_H_
#define _BOARD_H_
#include "Graphics.h"
#include "GCamera.h"
#include "Simon.h"
#include "GTexture.h"
#define SPRITE_BOARD L"other/board.png"
#define SPRITE_ALL L"other/misc.bmp"
class Board{
private:
	static Board* current;
	int _score;
	int _playerHp;
	int _enemyHP;
	int _time;
	int _heart;
	int _life;
	int _state;

	D3DXVECTOR3 _scorePosition;
	D3DXVECTOR3 _playerHpPosition;
	D3DXVECTOR3 _enemyHPPosition;
	D3DXVECTOR3 _timePosition;
	D3DXVECTOR3 _heartPosition;
	D3DXVECTOR3 _lifePosition;
	D3DXVECTOR3 _statePosition;

	RECT rect0;
	RECT rect1;
	RECT rect2;
	RECT rect3;
	RECT rect4;
	RECT rect5;
	RECT rect6;
	RECT rect7;
	RECT rect8;
	RECT rect9;

	GTexture* _all;
	GTexture* _board;
public:

	Board();
	~Board(){}
	static Board* GetCurrentBoard();
	void Update();
	void Draw();
	void drawPlaerHP();
	void drawEnemyHP();
	void drawScore();
	void drawTime();
	void drawState();
	void drawHeart();
	void drawLife();
	void drawNumber(D3DXVECTOR3 position, int numb);
};
#endif
