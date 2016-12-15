﻿#include "Game.h"



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
	
	//_bricks = new Bricks(0, 1570, 5000, 32);
	Quadtree::getCurrentQuadtree()->load();
	GCamera::getCurrentCamera()->x = 3584;
	GCamera::getCurrentCamera()->y = 1248;

}

void Game::Collision(float deltatime)
{	
	Quadtree::getCurrentQuadtree()->_root->Retrieve(listObject);
	for each(GObject* tamp in listObject){
		tamp->Collistion(deltatime);
	}	
}
void Game::_ProcessKeyBoard()
{
	// Collect all key states first
	
	KeyBoard::getCurrentKeyBoard()->_inputDevice->GetDeviceState(
		sizeof(KeyBoard::getCurrentKeyBoard()->_keyStates),
		KeyBoard::getCurrentKeyBoard()->_keyStates);



	// Collect all buffered events
	DWORD dwElements = KEYBOARD_BUFFER_SIZE;
	HRESULT hr = KeyBoard::getCurrentKeyBoard()->_inputDevice->GetDeviceData(sizeof(DIDEVICEOBJECTDATA),
		KeyBoard::getCurrentKeyBoard()->_KeyEvents, &dwElements, 0);

	// Scan through all data, check if the key is pressed or released
	for (DWORD i = 0; i < dwElements; i++)
	{
		int KeyCode = KeyBoard::getCurrentKeyBoard()->_KeyEvents[i].dwOfs;
		int KeyState = KeyBoard::getCurrentKeyBoard()->_KeyEvents[i].dwData;
		if ((KeyState & 0x80) > 0)
			OnKeyDown(KeyCode);
		else
			OnKeyUp(KeyCode);
	}
}
void Game::OnKeyDown(int KeyCode)
{
	if (Simon::getCurrentSimon()->GetState() == STATE::CANT_HURT)
		return;
	switch (KeyCode)
	{
	case DIK_SPACE:
  		Simon::getCurrentSimon()->Jump(); break;
	case DIK_C:
		Simon::getCurrentSimon()->Fight();
		break;
	case DIK_X:
		Simon::getCurrentSimon()->ChangeState(STATE::CANT_HURT);
		break;
	}
}
void Game::GameRun(float deltatime)
{
	KeyBoard::getCurrentKeyBoard()->UpdateKeyboard();
	Simon::getCurrentSimon()->Update(deltatime); 
	//if (Simon::getCurrentSimon()->_x > 250) GCamera::getCurrentCamera()->Follow();
	/*else
	{
		GCamera::getCurrentCamera()->Unfollow();
	}*/
	GCamera::getCurrentCamera()->Update();

	listObject.clear();
	Quadtree::getCurrentQuadtree()->_root->Retrieve(listObject);
	for each(GObject* tamp in listObject){
		tamp->Update(deltatime);
	}
	Collision(deltatime);
}

void Game::GameDraw()
{
	//map->draw();
	//GameDrawParameter();
	GCamera::getCurrentCamera()->SetTransform();
	//_mybackground->Draw(0, 0);
	
	State::getCurrentState()->draw();
	Simon::getCurrentSimon()->Draw();
	//_bricks->Draw();
	listObject.clear();
	Quadtree::getCurrentQuadtree()->_root->Retrieve(listObject);
	for each(GObject* tamp in listObject){
		tamp->Draw();
	}
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
