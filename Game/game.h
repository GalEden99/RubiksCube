#pragma once
#include "scene.h"
#include <vector>

class Game : public Scene
{
public:

	enum Direction {FRONT,BACK,LEFT,RIGHT,UP,DOWN};
	
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
	void multiplyAngle(float factor);
	bool validateMove(Direction);
	~Game(void);


	int direction = -1;
	float RotationAngle = 90.0f;
	float frontAngle = 0.0f;
	float backAngle = 0.0f;
	float leftAngle = 0.0f;
	float rightAngle = 0.0f;
	float upAngle = 0.0f;
	float downAngle = 0.0f;
	
};

