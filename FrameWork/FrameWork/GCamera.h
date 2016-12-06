#ifndef _CAMERA_H_
#define _CAMERA_H_


#include "Simon.h"
#include "Graphics.h"

class GCamera
{
private:
	static GCamera* _camera;
	D3DXMATRIX orthographicMatrix;
	D3DXMATRIX identityMatrix;
	D3DXMATRIX viewMatrix;
	Simon* following;
public:
	GCamera(int width, int height,int x,int y);

	int x, y;
	int width;
	int height;
	//Game Functions
	void Update();
	void Follow();
	void Unfollow();
	bool IsFollowing() const;
	void SetTransform() const;
	static GCamera* getCurrentCamera();
	GCamera();
	~GCamera();
};

#endif