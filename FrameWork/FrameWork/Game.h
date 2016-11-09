#pragma once
#include "Graphics.h"
#include "Surface.h"
#include "GTexture.h"
#include "GSprite.h"
#include "Simon.h"
#include "GCamera.h"
#include "State.h"
#include <string>
using namespace std;
class Game
{
	static Game* _game;

	Surface* _background;
	GSprite* _mybackground;

public:
	static Game* getCurGame();


	void GameInit();
	void GameLoad();
	void GameRun();
	void GameDraw();

	void handleSimon();

	void GameDrawParameter();
	Game(int screen_width, int screen_height);
	Game();
	~Game();
};

