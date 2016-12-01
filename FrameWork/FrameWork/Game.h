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
#include "Ghost.h"
#include "Spearguard.h"
#include "Bat.h"
#include "Cross.h"
#include "Axe.h"
#include "Knife.h"
#include "HolyWater.h"
#include "StopWatch.h"
#include "MorningStar.h"
#include "Roast.h"
#include "Rosary.h"
#include "MoneyBag.h"
#include "SpiritBall.h"
#include "BigHeart.h"
#include "SmallHeart.h"
#include "DoubleShot.h"
#include "ItemNone.h"
#include "MedusaHead.h"
using namespace std;

#define SIMON_SPRITE L"simon.png"

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

