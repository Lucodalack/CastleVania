#include "Game.h"



#define BACKGROUND_FILE L"191_173110_5a4c1.jpg"
Game* Game::_game = 0;
Game * Game::getCurGame()
{
	if (_game == 0)
		_game = new Game();
	return _game;
}

void Game::GameInit()
{
	// cấu hình game
	Windows::getCurrentWindows()->initWindows();
	//Camera::getCurCamera(CAMERAX, CAMERAY, CAMERAWIDTH, CAMERAHEIGHT);
	Graphics::getCurGraphics()->initDirectX3D();
	Graphics::getCurGraphics()->initDirect3DDevice();
	KeyBoard::getCurrentKeyBoard()->InputKeyBoard();
	swepyAABB = new CSweptAABB();
}

void Game::GameLoad()
{
	GTexture* backgroundTT = new GTexture(BACKGROUND_FILE, 1, 1, 1);
	//GSprite tamp(backgroundTT,10);
	_mybackground = new GSprite(backgroundTT, 10);
	/*map = new Map(L"Image\\Map.png");*/
	GTexture* simonTT = new GTexture(SIMON_SPRITE, 8, 3, 24);
	//GSprite tamp(backgroundTT,10);
	Simon::getCurrentSimon()->_sptrite = new GSprite(simonTT, 10);
	_bricks = new Bricks(0, 300, 300, 32);
	//GCamera::getCurrentCamera()->Follow();

	_mghost = new Ghost(0, 302, 300, 302);
	_mspearguard = new Spearguard(100, 302, 300, 302);
	_mbat = new Bat(50, 280, 400, 280);
}
void Game::Collision()
{
	float x, y;
	if (Simon::getCurrentSimon()->_box.y> 200)
		int a = 0;
	swepyAABB->SweptAABB(Simon::getCurrentSimon()->_box, _bricks->_box, x, y);
	if (x == 0 && y == -1){
		Simon::getCurrentSimon()->ChangeState(STATE::IS_STANDING);
		_mbat->ChangeState(BATSATE::IsAwake);
	}
	else if (Simon::getCurrentSimon()->GetState()==STATE::IS_JOGGING)
	{
		Simon::getCurrentSimon()->ChangeState(STATE::IS_FALLING);
	}
	
}


void Game::GameRun(float deltatime)
{
	KeyBoard::getCurrentKeyBoard()->UpdateKeyboard();
	Simon::getCurrentSimon()->Update(deltatime); 
	if (Simon::getCurrentSimon()->_x > 250) GCamera::getCurrentCamera()->Follow();
	else
	{
		GCamera::getCurrentCamera()->Unfollow();
	}
	GCamera::getCurrentCamera()->Update();
	Collision();
	//map->run();

	_mghost->Update(deltatime);
	_mspearguard->Update(deltatime);
	_mbat->Update(deltatime);
}

void Game::GameDraw()
{
	//map->draw();
	//GameDrawParameter();
	GCamera::getCurrentCamera()->SetTransform();
	//_mybackground->Draw(0, 0);
	
	State::getCurrentState()->draw();
	Simon::getCurrentSimon()->Draw();
	_bricks->draw();

	_mghost->Draw();
	_mspearguard->Draw();
	_mbat->Draw();
}


void Game::GameDrawParameter()
{
	/*string str = "( X=" + std::to_string(Camera::getCurCamera()->getLocation().GetX()) + ", Y=" +
		std::to_string(Camera::getCurCamera()->getLocation().GetY()) + ")";
	Graphics::getCurGraphics()->PrintText(str.c_str(), 20, 10, 10, D3DCOLOR_XRGB(255, 255, 255));*/
}

Game::Game(int screen_width, int screen_height)
{
	Windows::getCurrentWindows()->_width = screen_width;
	Windows::getCurrentWindows()->_height = screen_height;
}

Game::Game()
{
}


Game::~Game()
{
	delete this;
}
