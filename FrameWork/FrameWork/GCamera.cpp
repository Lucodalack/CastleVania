#include "GCamera.h"

GCamera* GCamera::_camera = 0;


GCamera::~GCamera(){

}
GCamera::GCamera(int width, int height,int x, int y)
{
	this->width = width;
	this->height = height;
	this->x = x;
	this->y = y;
	D3DXMatrixOrthoLH(&orthographicMatrix, width, -height, 0.0f, 1.0f);
	D3DXMatrixIdentity(&identityMatrix);
	_currentState = 1;
}
GCamera::GCamera()
{
}

void GCamera::Update()
{
	int cameraX, cameraY;
	switch (_currentState)
	{
	case 1:
		this->_isFollowing = false;
		break;
	case 2:
		if ((Simon::getCurrentSimon()->_x > (1536 + 0.5*width)) && (Simon::getCurrentSimon()->_x < (4096 - 0.5*width)))
			_isFollowing = true;
		else
		{
			this->_isFollowing = false;
			break;
		}
		break;
	case 3:
		if ((Simon::getCurrentSimon()->_x >(0 + 0.5*width)) && (Simon::getCurrentSimon()->_x < (3072 - 0.5*width)))
			_isFollowing = true;
		else
		{
			this->_isFollowing = false;
			break;
		}
		
		break;
	case 4:
		if ((Simon::getCurrentSimon()->_x >(0 + 0.5*width)) && (Simon::getCurrentSimon()->_x < (1536 - 0.5*width)))
			_isFollowing = true;
		else
		{
			this->_isFollowing = false;
			break;
		}

		break;
	default:
		break;
	}
	/*int cameraX = x+this->width / 2, cameraY = y+this->height / 2;
	if (this->IsFollowing())
	{
		cameraX = this->following->_x;
		cameraY = this->following->_y;
	}

	this->viewMatrix = D3DXMATRIX(
		1, 0, 0, 0,
		0, 1, 0, 0,
		0, 0, 1, 0,
		-cameraX, -cameraY, 0, 1
		);*/
	cameraX = x + this->width / 2;
	cameraY = y + this->height / 2;
	if (this->_isFollowing)
	{
		cameraX = Simon::getCurrentSimon()->_x;
	}

	this->viewMatrix = D3DXMATRIX(
		1, 0, 0, 0,
		0, 1, 0, 0,
		0, 0, 1, 0,
		-cameraX, -cameraY, 0, 1
		);
}

void GCamera::Follow()
{
	//this->following = Simon::getCurrentSimon();
}

void GCamera::Unfollow()
{
	//this->following = nullptr;
}

bool GCamera::IsFollowing() const
{
	//return this->following != nullptr;
	return true;
}

void GCamera::SetTransform() const
{
	Graphics::getCurGraphics()->_Direct3DDevice->SetTransform(D3DTS_PROJECTION, &orthographicMatrix);
	Graphics::getCurGraphics()->_Direct3DDevice->SetTransform(D3DTS_WORLD, &identityMatrix);
	Graphics::getCurGraphics()->_Direct3DDevice->SetTransform(D3DTS_VIEW, &viewMatrix);
}
GCamera* GCamera::getCurrentCamera(){
	if (!_camera)
		_camera = new GCamera(515, 350,STATE1_X,STATE1_Y);
	return _camera;
}
void GCamera::ChangeState(int state){
	_currentState = state;
	switch (state)
	{
	case 1:
		x = STATE1_X;
		y = STATE1_Y;
		break;
	case 2:
		x = STATE2_X;
		y = STATE2_Y;
		break;
	case 3:
		x = STATE3_X;
		y = STATE3_Y;
		break;
	case 4:
		x = STATE4_X;
		y = STATE4_Y;
		break;
	default:
		break;
	}
}