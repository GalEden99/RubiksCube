#pragma once
#include "scene.h"

class Game : public Scene
{
public:
	
	Game();
	Game(float angle,float relationWH,float near, float far);
	void Init();
	void Update(const glm::mat4 &MVP,const glm::mat4 &Model,const int  shaderIndx);
	void ControlPointUpdate();
	void WhenRotate();
	void WhenTranslate();
	void Motion();
	void rotateFront();
	void rotateBack();
	void rotateLeft();
	void rotateRight();
	void rotateUp();
	void rotateDown();
	void changeDirection();
	~Game(void);

	int direction = 1;
	int angle = 90;
};

