#pragma once
#include <dinput.h>
#include "Graphics.h"
#include <InitGuid.h>


#define KEYBOARD_BUFFER_SIZE	1024
class KeyBoard
{
	static KeyBoard* _keyboard;
	
public:

	LPDIRECTINPUT8 _input;
	LPDIRECTINPUTDEVICE8 _inputDevice;
	BYTE  _keyStates[256];
	DIDEVICEOBJECTDATA _KeyEvents[KEYBOARD_BUFFER_SIZE];

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

