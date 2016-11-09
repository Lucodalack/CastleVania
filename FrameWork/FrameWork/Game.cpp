#include "Game.h"


#define SIMON_SPRITE L"simon.png"
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
	
}

void Game::GameLoad()
{
	GTexture* backgroundTT = new GTexture(BACKGROUND_FILE, 1, 1, 1);
	//GSprite tamp(backgroundTT,10);
	_mybackground = new GSprite(backgroundTT, 10);
	/*map = new Map(L"Image\\Map.png");*/
	GTexture* simonTT = new GTexture(SIMON_SPRITE, 2, 1, 2);
	//GSprite tamp(backgroundTT,10);
	Simon::getCurrentSimon()->_leftSprite = new GSprite(simonTT, 10);
	//GCamera::getCurrentCamera()->Follow();
}

void Game::GameRun()
{
	KeyBoard::getCurrentKeyBoard()->UpdateKeyboard();
	handleSimon(); 
	if (Simon::getCurrentSimon()->_x > 250) GCamera::getCurrentCamera()->Follow();
	else
	{
		GCamera::getCurrentCamera()->Unfollow();
	}
	GCamera::getCurrentCamera()->Update();
	//map->run();
}

void Game::GameDraw()
{
	//map->draw();
	//GameDrawParameter();
	GCamera::getCurrentCamera()->SetTransform();
	//_mybackground->Draw(0, 0);
	State::getCurrentState()->draw();
	Simon::getCurrentSimon()->draw();
}

void Game::handleSimon(){
	if (KeyBoard::getCurrentKeyBoard()->keyLeft())
		Simon::getCurrentSimon()->run(-5, 0);
	else if (KeyBoard::getCurrentKeyBoard()->keyRight())
		Simon::getCurrentSimon()->run(5, 0);
	else if (KeyBoard::getCurrentKeyBoard()->keyUp())
		Simon::getCurrentSimon()->run(0, -5);
	else if (KeyBoard::getCurrentKeyBoard()->keyDown())
		Simon::getCurrentSimon()->run(0, 5);
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
