#pragma once
#include "Graphics.h"
#include "Surface.h"
#include "GTexture.h"
#include "GSprite.h"
#include "Simon.h"
#include "GCamera.h"
#include "State.h"
#include "Bricks.h"
#include "SweptAABB.h"
#include <string>
#include "Quadtree.h"
#include "GObject.h"
#include <vector>
using namespace std;


class Game
{
	static Game* _game;

	Surface* _background;
	GSprite* _mybackground;
	Bricks* _bricks;
	CSweptAABB* swepyAABB;
	

	GObject *_mbat, *_mspearguard, *_mghost,*_item,*_enemy;

public:
	static Game* getCurGame();

	vector<GObject*> listObject;
	void GameInit();
	void GameLoad();
	void GameRun(float deltatime);
	void GameDraw();
	void Collision();

	void GameDrawParameter();
	Game(int screen_width, int screen_height);
	Game();
	~Game();
};

