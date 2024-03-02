#include "game.h"
#include <iostream>
#include <glm/gtc/matrix_transform.hpp>

static void printMat(const glm::mat4 mat)
{
	std::cout<<" matrix:"<<std::endl;
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
			std::cout<< mat[j][i]<<" ";
		std::cout<<std::endl;
	}
}

Game::Game() : Scene()
{
}

Game::Game(float angle ,float relationWH, float near1, float far1) : Scene(angle,relationWH,near1,far1)
{ 	
}

void Game::Init()
{		

	AddShader("../res/shaders/pickingShader");	
	AddShader("../res/shaders/basicShader");
	
	AddTexture("../res/textures/plane.png", false);
	int size = 3;
	float distance = 1;
	int index = 0;
	for (float i = -distance; i <= distance; i += 1){
		for (float j = -distance; j <= distance; j += 1){
			for (float k = -distance; k <= distance; k += 1){
				AddShape(Scene::Cube, -1, Scene::TRIANGLES);
				SetShapeTex(index, 0);
				rubikCube->AddInnerCube(new InnerCube(glm::vec3(i, j, k), index));
				shapes[index]->MyTranslate(glm::vec3(i, j, k), 0);
				shapes[index]->MyScale(glm::vec3(0.5, 0.5, 0.5));
				index++;
			}
		}
	}

	rubikCube->printCubes();
	
	pickedShape = 0;
	
	SetShapeTex(0,0);
	MoveCamera(0,zTranslate,10);
	pickedShape = -1;
	
	//ReadPixel(); //uncomment when you are reading from the z-buffer
}

void Game::Update(const glm::mat4 &MVP,const glm::mat4 &Model,const int  shaderIndx)
{
	Shader *s = shaders[shaderIndx];
	int r = ((pickedShape+1) & 0x000000FF) >>  0;
	int g = ((pickedShape+1) & 0x0000FF00) >>  8;
	int b = ((pickedShape+1) & 0x00FF0000) >> 16;
	s->Bind();
	s->SetUniformMat4f("MVP", MVP);
	s->SetUniformMat4f("Normal",Model);
	s->SetUniform4f("lightDirection", 0.0f , 0.0f, -1.0f, 0.0f);
	if(shaderIndx == 0)
		s->SetUniform4f("lightColor",r/255.0f, g/255.0f, b/255.0f,1.0f);
	else 
		s->SetUniform4f("lightColor",0.7f,0.8f,0.1f,1.0f);
	s->Unbind();
}

void Game::WhenRotate()
{
}

void Game::WhenTranslate()
{
}

void Game::Motion()
{
	if(isActive)
	{
	}
}

Game::~Game(void)
{
}

void Game::changeDirection()
{
	direction = -direction;
}

void Game::rotateFront()
{
	if(!validateMove(FRONT)) return;

	std::vector<InnerCube *> innerCubes = rubikCube->GetInnerCubes();
	std::vector<InnerCube *> rotatedCubes = std::vector<InnerCube *>();
	for (InnerCube* cube : innerCubes){
		if (cube->GetPosition().z == 1){
			int index = cube->GetIndex();
			glm::vec3 pos = cube->GetPosition();
			std::cout << "index front: " << index << "position: " << pos.x << " " << pos.y << " " << pos.z << std::endl;
			glm::mat4 rot = shapes[index]->getRot();
			glm::mat4 rotTransposed = glm::transpose(rot);
			glm::vec3 vector = glm::vec3(0, 0, 1);
			glm::vec3 rotatedVector = glm::vec3(rotTransposed * glm::vec4(vector, 1));
			
			shapes[index]->MyRotate(direction*RotationAngle, rotatedVector, 0);
		}
	}
	frontAngle += RotationAngle*direction;
	if(abs(fmod(frontAngle,90.0)) == 0){
		int rotationTimes = abs(frontAngle / 90);
		frontAngle = 0.0;
		for (int i = 0; i < rotationTimes; i++){
			rubikCube->rotateFront(direction);
		}
	}
}

void Game::rotateBack()
{
	if (!validateMove(BACK)) return;

	std::vector<InnerCube *> innerCubes = rubikCube->GetInnerCubes();
	for (InnerCube* cube : innerCubes){
		if (cube->GetPosition().z == -1){
			int index = cube->GetIndex();
			std::cout << "index: " << index << std::endl;
			glm::mat4 rot = shapes[index]->getRot();
			glm::mat4 rotTransposed = glm::transpose(rot);
			glm::vec3 vector = glm::vec3(0, 0, 1);
			glm::vec3 rotatedVector = glm::vec3(rotTransposed * glm::vec4(vector, 1));
			
			shapes[index]->MyRotate(direction*RotationAngle, rotatedVector, 0);
		}
	}
	backAngle += RotationAngle*direction;
	if(abs(fmod(backAngle,90.0)) == 0){
		int rotationTimes = abs(backAngle / 90);
		backAngle = 0.0;
		for (int i = 0; i < rotationTimes; i++){
			rubikCube->rotateBack(direction);
		}
	}
		rubikCube->printCubes();
}

void Game::rotateRight()
{
	if (!validateMove(RIGHT)) return;

	std::vector<InnerCube *> innerCubes = rubikCube->GetInnerCubes();
	for (InnerCube* cube : innerCubes){
		if (cube->GetPosition().x == 1){
			int index = cube->GetIndex();
			glm::vec3 pos = cube->GetPosition();
			glm::mat4 rot = shapes[index]->getRot();
			glm::mat4 rotTransposed = glm::transpose(rot);
			glm::vec3 vector = glm::vec3(1, 0, 0);
			glm::vec3 rotatedVector = glm::vec3(rotTransposed * glm::vec4(vector, 1));
			
			shapes[index]->MyRotate(direction*RotationAngle, rotatedVector, 0);
		}
	}
	rightAngle += RotationAngle*direction;
		if(abs(fmod(rightAngle,90.0)) == 0){
			int rotationTimes = abs(rightAngle / 90);
			rightAngle = 0.0;
			for (int i = 0; i < rotationTimes; i++){
				rubikCube->rotateRight(direction);
			}
		}
}

void Game::rotateLeft()
{
	if (!validateMove(LEFT)) return;

	std::vector<InnerCube *> innerCubes = rubikCube->GetInnerCubes();
	for (InnerCube* cube : innerCubes){
		if (cube->GetPosition().x == -1){
			int index = cube->GetIndex();
			glm::mat4 rot = shapes[index]->getRot();
			glm::mat4 rotTransposed = glm::transpose(rot);
			glm::vec3 vector = glm::vec3(1, 0, 0);
			glm::vec3 rotatedVector = glm::vec3(rotTransposed * glm::vec4(vector, 1));
			
			shapes[index]->MyRotate(direction*RotationAngle,rotatedVector, 0);
		}
	}
	leftAngle += RotationAngle*direction;
		if(abs(fmod(leftAngle,90.0)) == 0){
			int rotationTimes = abs(leftAngle / 90);

			leftAngle = 0.0;
			for (int i = 0; i < rotationTimes; i++){
				rubikCube->rotateLeft(direction);
			}
		}
		
}

void Game::rotateUp()
{
	if (!validateMove(UP)) return;

	std::vector<InnerCube *> innerCubes = rubikCube->GetInnerCubes();
	for (InnerCube* cube : innerCubes){
		if (cube->GetPosition().y == 1){
			int index = cube->GetIndex();
			glm::mat4 rot = shapes[index]->getRot();
			glm::mat4 rotTransposed = glm::transpose(rot);
			glm::vec3 vector = glm::vec3(0, 1, 0);
			glm::vec3 rotatedVector = glm::vec3(rotTransposed * glm::vec4(vector, 1));
			
			shapes[index]->MyRotate(direction*RotationAngle, rotatedVector, 0);
		}
	}
	upAngle += RotationAngle*direction;
	if (abs(fmod(upAngle, 90.0)) == 0){
		int rotationTimes = abs(upAngle / 90);
		upAngle = 0.0;
		for (int i = 0; i < rotationTimes; i++){
			rubikCube->rotateUp(direction);
		}
	}
	rubikCube->printCubes();
}

void Game::rotateDown()
{
	if (!validateMove(DOWN)) return;

	std::vector<InnerCube *> innerCubes = rubikCube->GetInnerCubes();
	for (InnerCube* cube : innerCubes){
		if (cube->GetPosition().y == -1){
			int index = cube->GetIndex();
			std::cout << "index: " << index << std::endl;
			glm::mat4 rot = shapes[index]->getRot();
			glm::mat4 rotTransposed = glm::transpose(rot);
			glm::vec3 vector = glm::vec3(0, 1, 0);
			glm::vec3 rotatedVector = glm::vec3(rotTransposed * glm::vec4(vector, 1));
			
			shapes[index]->MyRotate(direction*RotationAngle, rotatedVector, 0);
		}
	}
	downAngle += RotationAngle*direction;
	if (abs(fmod(downAngle, 90.0)) == 0){
		std::cout << "downAngle: " << downAngle << std::endl;
		int rotationTimes = abs(downAngle / 90);
		downAngle = 0.0;
		for (int i = 0; i < rotationTimes; i++){
			rubikCube->rotateDown(direction);
		}
	}
	rubikCube->printCubes();
}

void Game::multiplyAngle(float factor)
{
	if (RotationAngle >=180) return;
	RotationAngle *= factor;
} 

bool Game::validateMove(Direction expression){
	switch (expression)
	{
	case FRONT:
		return rightAngle == 0 && leftAngle == 0 && upAngle == 0 && downAngle == 0;
		break;
	case BACK:
		return rightAngle == 0 && leftAngle == 0 && upAngle == 0 && downAngle == 0;
		break;
	case LEFT:
		return frontAngle == 0 && backAngle == 0 && upAngle == 0 && downAngle == 0;
		break;
	case RIGHT:
		return frontAngle == 0 && backAngle == 0 && upAngle == 0 && downAngle == 0;
		break;
	case UP:
		return frontAngle == 0 && backAngle == 0 && rightAngle == 0 && leftAngle == 0;
		break;
	case DOWN:
		return frontAngle == 0 && backAngle == 0 && rightAngle == 0 && leftAngle == 0;
		break;
	}
}