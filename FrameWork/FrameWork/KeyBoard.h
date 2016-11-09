#pragma once
#include <dinput.h>
#include "Graphics.h"
#include <InitGuid.h>

class KeyBoard
{
	static KeyBoard* _keyboard;
	LPDIRECTINPUT8 _input;
	LPDIRECTINPUTDEVICE8 _inputDevice;
	BYTE  _keyStates[256];
public:

	static KeyBoard* getCurrentKeyBoard();
	int InputKeyBoard();
	void UpdateKeyboard();
	void PollKeyboard();
	bool IsKeyDown(BYTE keyCode);
	bool IsKeyUp(BYTE keyCode);


	bool keyLeft();
	bool keyRight();
	bool keyUp();
	bool keyDown();
	bool keySpace();

	bool keyS();
	bool keyW();
	bool keyX();
	bool keyC();

	KeyBoard(void);
	~KeyBoard(void);
};

