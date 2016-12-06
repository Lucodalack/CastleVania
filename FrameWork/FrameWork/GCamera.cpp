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
}
GCamera::GCamera()
{
}

void GCamera::Update()
{
	int cameraX = x+this->width / 2, cameraY = y+this->height / 2;
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
		);
}

void GCamera::Follow()
{
	this->following = Simon::getCurrentSimon();
}

void GCamera::Unfollow()
{
	this->following = nullptr;
}

bool GCamera::IsFollowing() const
{
	return this->following != nullptr;
}

void GCamera::SetTransform() const
{
	Graphics::getCurGraphics()->_Direct3DDevice->SetTransform(D3DTS_PROJECTION, &orthographicMatrix);
	Graphics::getCurGraphics()->_Direct3DDevice->SetTransform(D3DTS_WORLD, &identityMatrix);
	Graphics::getCurGraphics()->_Direct3DDevice->SetTransform(D3DTS_VIEW, &viewMatrix);
}
GCamera* GCamera::getCurrentCamera(){
	if (!_camera)
		_camera = new GCamera(515, 350,0,0);
	return _camera;
}