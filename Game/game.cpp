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
			shapes[index]->MyRotate(direction*angle, rotatedVector, 0);
		}
	}
	rubikCube->rotateFront(direction);
	rubikCube->printCubes();
}

void Game::rotateBack()
{
	std::vector<InnerCube *> innerCubes = rubikCube->GetInnerCubes();
	for (InnerCube* cube : innerCubes){
		if (cube->GetPosition().z == -1){
			int index = cube->GetIndex();
			std::cout << "index: " << index << std::endl;
			glm::mat4 rot = shapes[index]->getRot();
			glm::mat4 rotTransposed = glm::transpose(rot);
			glm::vec3 vector = glm::vec3(0, 0, 1);
			glm::vec3 rotatedVector = glm::vec3(rotTransposed * glm::vec4(vector, 1));
			shapes[index]->MyRotate(direction*angle, rotatedVector, 0);
		}
	}
		rubikCube->rotateBack(direction);
		rubikCube->printCubes();
}

void Game::rotateRight()
{
	std::vector<InnerCube *> innerCubes = rubikCube->GetInnerCubes();
	for (InnerCube* cube : innerCubes){
		if (cube->GetPosition().x == 1){
			int index = cube->GetIndex();
			glm::vec3 pos = cube->GetPosition();
			std::cout << "index Right: " << index << "position: " << pos.x << " " << pos.y << " " << pos.z << std::endl;
			glm::mat4 rot = shapes[index]->getRot();
			glm::mat4 rotTransposed = glm::transpose(rot);
			glm::vec3 vector = glm::vec3(1, 0, 0);
			glm::vec3 rotatedVector = glm::vec3(rotTransposed * glm::vec4(vector, 1));
			shapes[index]->MyRotate(direction*angle, rotatedVector, 0);
		}
	}
		rubikCube->rotateRight(direction);
		std::cout << "after right rotation" << std::endl;
			for (InnerCube* cube : innerCubes){
		if (cube->GetPosition().x == 1){
			int index = cube->GetIndex();
			glm::vec3 pos = cube->GetPosition();
			std::cout << "index Right: " << index << "position: " << pos.x << " " << pos.y << " " << pos.z << std::endl;

		}
	}
		// rubikCube->printCubes();
}

void Game::rotateLeft()
{
	std::vector<InnerCube *> innerCubes = rubikCube->GetInnerCubes();
	for (InnerCube* cube : innerCubes){
		if (cube->GetPosition().x == -1){
			int index = cube->GetIndex();
			std::cout << "indexLEFT: " << index << std::endl;
			glm::mat4 rot = shapes[index]->getRot();
			glm::mat4 rotTransposed = glm::transpose(rot);
			glm::vec3 vector = glm::vec3(1, 0, 0);
			glm::vec3 rotatedVector = glm::vec3(rotTransposed * glm::vec4(vector, 1));
			shapes[index]->MyRotate(direction*angle,rotatedVector, 0);
		}
	}
		rubikCube->rotateLeft(direction);
		rubikCube->printCubes();
}

void Game::rotateUp()
{
	std::vector<InnerCube *> innerCubes = rubikCube->GetInnerCubes();
	for (InnerCube* cube : innerCubes){
		if (cube->GetPosition().y == 1){
			int index = cube->GetIndex();
			std::cout << "index: " << index << std::endl;
			glm::mat4 rot = shapes[index]->getRot();
			glm::mat4 rotTransposed = glm::transpose(rot);
			glm::vec3 vector = glm::vec3(0, 1, 0);
			glm::vec3 rotatedVector = glm::vec3(rotTransposed * glm::vec4(vector, 1));
			shapes[index]->MyRotate(direction*angle, rotatedVector, 0);
		}
	}
	rubikCube->rotateUp(direction);
	rubikCube->printCubes();
}

void Game::rotateDown()
{
	std::vector<InnerCube *> innerCubes = rubikCube->GetInnerCubes();
	for (InnerCube* cube : innerCubes){
		if (cube->GetPosition().y == -1){
			int index = cube->GetIndex();
			std::cout << "index: " << index << std::endl;
			glm::mat4 rot = shapes[index]->getRot();
			glm::mat4 rotTransposed = glm::transpose(rot);
			glm::vec3 vector = glm::vec3(0, 1, 0);
			glm::vec3 rotatedVector = glm::vec3(rotTransposed * glm::vec4(vector, 1));
			shapes[index]->MyRotate(direction*angle, rotatedVector, 0);
		}
	}
	rubikCube->rotateDown(direction);
	rubikCube->printCubes();
}

