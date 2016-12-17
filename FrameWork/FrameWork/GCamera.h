#ifndef _CAMERA_H_
#define _CAMERA_H_


#include "Simon.h"
#include "Graphics.h"

#define STATE1_X 3584
#define STATE1_Y 1248
#define STATE2_X 3584
#define STATE2_Y 865
#define STATE3_X 2722
#define STATE3_Y 480
#define STATE4_X 1021
#define STATE4_Y 98

class GCamera
{
private:
	static GCamera* _camera;
	D3DXMATRIX orthographicMatrix;
	D3DXMATRIX identityMatrix;
	D3DXMATRIX viewMatrix;
	bool _isFollowing;
	int _currentState;
public:
	GCamera(int width, int height,int x,int y);
	void ChangeState(int state);
	int x, y;
	int xDestinate;
	bool onGoto;
	int width;
	int height;
	//Game Functions
	void Update(float deltatime);
	void Move();
	void Follow();
	void Unfollow();
	bool IsFollowing() const;
	void SetTransform() const;
	static GCamera* getCurrentCamera();
	GCamera();
	~GCamera();
};

#endif