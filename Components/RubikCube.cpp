#include "RubikCube.h"
#include <iostream>


RubikCube::RubikCube(int size, float distance)
{
    innerCubes = std::vector<InnerCube *>();
    this->size = size;
    this->distance = distance;
}

void RubikCube::AddInnerCube(InnerCube* innerCube)
{
    innerCubes.push_back(innerCube);
}

void RubikCube::UpdateInnerCubePosition(int index, glm::vec3 position)
{
    innerCubes[index]->UpdatePosition(position);
}

InnerCube* RubikCube::GetInnerCube(int index)
{
    return innerCubes[index];
}

RubikCube::~RubikCube()
{
    std::cout << "RubikCube destructor called" << std::endl;
}

void RubikCube::printCubes() {
    for (int i = 0; i < innerCubes.size(); i++) {
        std::cout << "Cube " << i << " position: " << innerCubes[i]->GetPosition().x << " " << innerCubes[i]->GetPosition().y << " " << innerCubes[i]->GetPosition().z << " | index: " << innerCubes[i]->GetIndex() <<std::endl;
    }
}

std::vector<InnerCube *> RubikCube::GetInnerCubes()
{
    return innerCubes;
}




void RubikCube::rotateFront(int direction) {
    std::map<glm::vec3, glm::vec3, RubikCube::Vec3Comparator> vecMap;
    switch (size) {
        case 3:
            if (direction < 0) {
                vecMap[glm::vec3(1,1,1)] = glm::vec3(1,-1,1);
                vecMap[glm::vec3(0,1,1)] =  glm::vec3(1,0,1);
                vecMap[glm::vec3(-1,1,1)] = glm::vec3(1,1,1);

                vecMap[glm::vec3(1,0,1)] = glm::vec3(0,-1,1);
                vecMap[glm::vec3(0,0,1)] = glm::vec3(0,0,1);
                vecMap[glm::vec3(-1,0,1)] = glm::vec3(0,1,1);

                vecMap[glm::vec3(1,-1,1)] = glm::vec3(-1,-1,1);
                vecMap[glm::vec3(0,-1,1)] = glm::vec3(-1,0,1);
                vecMap[glm::vec3(-1,-1,1)] = glm::vec3(-1,1,1);
            } 
            else {
                vecMap[glm::vec3(1,1,1)] = glm::vec3(-1,1,1);
                vecMap[glm::vec3(0,1,1)] =  glm::vec3(-1,0,1);
                vecMap[glm::vec3(-1,1,1)] = glm::vec3(-1,-1,1);
               
                vecMap[glm::vec3(1,0,1)] = glm::vec3(0,1,1);
                vecMap[glm::vec3(0,0,1)] = glm::vec3(0,0,1);
                vecMap[glm::vec3(-1,0,1)] = glm::vec3(0,-1,1);
               
                vecMap[glm::vec3(1,-1,1)] = glm::vec3(1,1,1);
                vecMap[glm::vec3(0,-1,1)] = glm::vec3(1,0,1);
                vecMap[glm::vec3(-1,-1,1)] = glm::vec3(1,-1,1);
            }

            break;
        case 2:
            if (direction < 0) {
                vecMap[glm::vec3(0.5,0.5,0.5)] = glm::vec3(0.5,-0.5,0.5);
                vecMap[glm::vec3(-0.5,0.5,0.5)] = glm::vec3(0.5,0.5,0.5);
                vecMap[glm::vec3(0.5,-0.5,0.5)] = glm::vec3(-0.5,-0.5,0.5);
                vecMap[glm::vec3(-0.5,-0.5,0.5)] = glm::vec3(-0.5,0.5,0.5);
            }
            else {
                vecMap[glm::vec3(-0.5,-0.5,0.5)] = glm::vec3(0.5,-0.5,0.5);
                vecMap[glm::vec3(0.5,-0.5,0.5)] = glm::vec3(0.5,0.5,0.5);
                vecMap[glm::vec3(-0.5,0.5,0.5)] = glm::vec3(-0.5,-0.5,0.5);
                vecMap[glm::vec3(0.5,0.5,0.5)] = glm::vec3(-0.5,0.5,0.5);
            }
            break;
        case 4:
            if (direction < 0) {
                vecMap[glm::vec3(1.5, 1.5 ,1.5)] = glm::vec3(1.5, -1.5, 1.5);
                vecMap[glm::vec3(0.5, 1.5 ,1.5)] = glm::vec3(1.5, -0.5, 1.5);
                vecMap[glm::vec3(-0.5, 1.5 ,1.5)] = glm::vec3(1.5, 0.5, 1.5);
                vecMap[glm::vec3(-1.5, 1.5 ,1.5)] = glm::vec3(1.5, 1.5, 1.5);

                vecMap[glm::vec3(1.5, 0.5 ,1.5)] = glm::vec3(0.5, -1.5, 1.5);
                vecMap[glm::vec3(0.5, 0.5 ,1.5)] = glm::vec3(0.5, -0.5, 1.5);
                vecMap[glm::vec3(-0.5, 0.5 ,1.5)] = glm::vec3(0.5, 0.5, 1.5);
                vecMap[glm::vec3(-1.5, 0.5 ,1.5)] = glm::vec3(0.5, 1.5, 1.5);

                vecMap[glm::vec3(1.5, -0.5 ,1.5)] = glm::vec3(-0.5, -1.5, 1.5);
                vecMap[glm::vec3(0.5, -0.5 ,1.5)] = glm::vec3(-0.5, -0.5, 1.5);
                vecMap[glm::vec3(-0.5, -0.5 ,1.5)] = glm::vec3(-0.5, 0.5, 1.5);
                vecMap[glm::vec3(-1.5, -0.5 ,1.5)] = glm::vec3(-0.5, 1.5, 1.5);

                vecMap[glm::vec3(1.5, -1.5 ,1.5)] = glm::vec3(-1.5, -1.5, 1.5);
                vecMap[glm::vec3(0.5, -1.5 ,1.5)] = glm::vec3(-1.5, -0.5, 1.5);
                vecMap[glm::vec3(-0.5, -1.5 ,1.5)] = glm::vec3(-1.5, 0.5, 1.5);
                vecMap[glm::vec3(-1.5, -1.5 ,1.5)] = glm::vec3(-1.5, 1.5, 1.5);
            }
            else {
                vecMap[glm::vec3(1.5, 1.5 ,1.5)] = glm::vec3(-1.5, 1.5, 1.5);
                vecMap[glm::vec3(0.5, 1.5 ,1.5)] = glm::vec3(-1.5, 0.5, 1.5);
                vecMap[glm::vec3(-0.5, 1.5 ,1.5)] = glm::vec3(-1.5, -0.5, 1.5);
                vecMap[glm::vec3(-1.5, 1.5 ,1.5)] = glm::vec3(-1.5, -1.5, 1.5);

                vecMap[glm::vec3(1.5, 0.5 ,1.5)] = glm::vec3(-0.5, 1.5, 1.5);
                vecMap[glm::vec3(0.5, 0.5 ,1.5)] = glm::vec3(-0.5, 0.5, 1.5);
                vecMap[glm::vec3(-0.5, 0.5 ,1.5)] = glm::vec3(-0.5, -0.5, 1.5);
                vecMap[glm::vec3(-1.5, 0.5 ,1.5)] = glm::vec3(-0.5, -1.5, 1.5);

                vecMap[glm::vec3(1.5, -0.5 ,1.5)] = glm::vec3(0.5, 1.5, 1.5);
                vecMap[glm::vec3(0.5, -0.5 ,1.5)] = glm::vec3(0.5, 0.5, 1.5);
                vecMap[glm::vec3(-0.5, -0.5 ,1.5)] = glm::vec3(0.5, -0.5, 1.5);
                vecMap[glm::vec3(-1.5, -0.5 ,1.5)] = glm::vec3(0.5, -1.5, 1.5);

                vecMap[glm::vec3(1.5, -1.5 ,1.5)] = glm::vec3(1.5, 1.5, 1.5);
                vecMap[glm::vec3(0.5, -1.5 ,1.5)] = glm::vec3(1.5, 0.5, 1.5);
                vecMap[glm::vec3(-0.5, -1.5 ,1.5)] = glm::vec3(1.5, -0.5, 1.5);
                vecMap[glm::vec3(-1.5, -1.5 ,1.5)] = glm::vec3(1.5, -1.5, 1.5);
            }
            break;
        case 5:
            if (direction < 0) {
                vecMap[glm::vec3(2, 2 ,2)] = glm::vec3(2, -2, 2);
                vecMap[glm::vec3(1, 2 ,2)] = glm::vec3(2, -1, 2);
                vecMap[glm::vec3(0, 2 ,2)] = glm::vec3(2, 0, 2);
                vecMap[glm::vec3(-1, 2 ,2)] = glm::vec3(2, 1, 2);
                vecMap[glm::vec3(-2, 2 ,2)] = glm::vec3(2, 2, 2);

                vecMap[glm::vec3(2, 1 ,2)] = glm::vec3(1, -2, 2);
                vecMap[glm::vec3(1, 1 ,2)] = glm::vec3(1, -1, 2);
                vecMap[glm::vec3(0, 1 ,2)] = glm::vec3(1, 0, 2);
                vecMap[glm::vec3(-1, 1 ,2)] = glm::vec3(1, 1, 2);
                vecMap[glm::vec3(-2, 1 ,2)] = glm::vec3(1, 2, 2);

                vecMap[glm::vec3(2, 0 ,2)] = glm::vec3(0, -2, 2);
                vecMap[glm::vec3(1, 0 ,2)] = glm::vec3(0, -1, 2);
                vecMap[glm::vec3(0, 0 ,2)] = glm::vec3(0, 0, 2);
                vecMap[glm::vec3(-1, 0 ,2)] = glm::vec3(0, 1, 2);
                vecMap[glm::vec3(-2, 0 ,2)] = glm::vec3(0, 2, 2);

                vecMap[glm::vec3(2, -1 ,2)] = glm::vec3(-1, -2, 2);
                vecMap[glm::vec3(1, -1 ,2)] = glm::vec3(-1, -1, 2);
                vecMap[glm::vec3(0, -1 ,2)] = glm::vec3(-1, 0, 2);
                vecMap[glm::vec3(-1, -1 ,2)] = glm::vec3(-1, 1, 2);
                vecMap[glm::vec3(-2, -1 ,2)] = glm::vec3(-1, 2, 2);

                vecMap[glm::vec3(2, -2 ,2)] = glm::vec3(-2, -2, 2);
                vecMap[glm::vec3(1, -2 ,2)] = glm::vec3(-2, -1, 2);
                vecMap[glm::vec3(0, -2 ,2)] = glm::vec3(-2, 0, 2);
                vecMap[glm::vec3(-1, -2 ,2)] = glm::vec3(-2, 1, 2);
                vecMap[glm::vec3(-2, -2 ,2)] = glm::vec3(-2, 2, 2);
            }
            else {
                vecMap[glm::vec3(2, 2 ,2)] = glm::vec3(-2, 2, 2);
                vecMap[glm::vec3(1, 2 ,2)] = glm::vec3(-2, 1, 2);
                vecMap[glm::vec3(0, 2 ,2)] = glm::vec3(-2, 0, 2);
                vecMap[glm::vec3(-1, 2 ,2)] = glm::vec3(-2, -1, 2);
                vecMap[glm::vec3(-2, 2 ,2)] = glm::vec3(-2, -2, 2);

                vecMap[glm::vec3(2, 1 ,2)] = glm::vec3(-1, 2, 2);
                vecMap[glm::vec3(1, 1 ,2)] = glm::vec3(-1, 1, 2);
                vecMap[glm::vec3(0, 1 ,2)] = glm::vec3(-1, 0, 2);
                vecMap[glm::vec3(-1, 1 ,2)] = glm::vec3(-1, -1, 2);
                vecMap[glm::vec3(-2, 1 ,2)] = glm::vec3(-1, -2, 2);

                vecMap[glm::vec3(2, 0 ,2)] = glm::vec3(0, 2, 2);
                vecMap[glm::vec3(1, 0 ,2)] = glm::vec3(0, 1, 2);
                vecMap[glm::vec3(0, 0 ,2)] = glm::vec3(0, 0, 2);
                vecMap[glm::vec3(-1, 0 ,2)] = glm::vec3(0, -1, 2);
                vecMap[glm::vec3(-2, 0 ,2)] = glm::vec3(0, -2, 2);

                vecMap[glm::vec3(2, -1 ,2)] = glm::vec3(1, 2, 2);
                vecMap[glm::vec3(1, -1 ,2)] = glm::vec3(1, 1, 2);
                vecMap[glm::vec3(0, -1 ,2)] = glm::vec3(1, 0, 2);
                vecMap[glm::vec3(-1, -1 ,2)] = glm::vec3(1, -1, 2);
                vecMap[glm::vec3(-2, -1 ,2)] = glm::vec3(1, -2, 2);

                vecMap[glm::vec3(2, -2 ,2)] = glm::vec3(2, 2, 2);
                vecMap[glm::vec3(1, -2 ,2)] = glm::vec3(2, 1, 2);
                vecMap[glm::vec3(0, -2 ,2)] = glm::vec3(2, 0, 2);
                vecMap[glm::vec3(-1, -2 ,2)] = glm::vec3(2, -1, 2);
                vecMap[glm::vec3(-2, -2 ,2)] = glm::vec3(2, -2, 2);
            }
            break;
    }

    for (InnerCube* cube : innerCubes) {
        if (cube->GetPosition().z == distance) {
            glm::vec3 position = cube->GetPosition();
            cube->UpdatePosition(vecMap[position]);
            glm::vec3 newPosition = cube->GetPosition();
            std::cout << "FrontCube index: " << cube->GetIndex() << " | position: " << newPosition.x << " " << newPosition.y << " " << newPosition.z << std::endl;
        }
    }
}

void RubikCube::rotateBack(int direction) {
    std::map<glm::vec3, glm::vec3, RubikCube::Vec3Comparator> vecMap;
    switch (size) {
        case 3:
            if (direction < 0) {
                vecMap[glm::vec3(1,1,-1)] = glm::vec3(1,-1,-1);
                vecMap[glm::vec3(0,1,-1)] =  glm::vec3(1,0,-1);
                vecMap[glm::vec3(-1,1,-1)] = glm::vec3(1,1,-1);
                
                vecMap[glm::vec3(1,0,-1)] = glm::vec3(0,-1,-1);
                vecMap[glm::vec3(0,0,-1)] = glm::vec3(0,0,-1);
                vecMap[glm::vec3(-1,0,-1)] = glm::vec3(0,1,-1);
                
                vecMap[glm::vec3(1,-1,-1)] = glm::vec3(-1,-1,-1);
                vecMap[glm::vec3(0,-1,-1)] = glm::vec3(-1,0,-1);
                vecMap[glm::vec3(-1,-1,-1)] = glm::vec3(-1,1,-1);
            }
            else {
                vecMap[glm::vec3(1,1,-1)] = glm::vec3(-1,1,-1);
                vecMap[glm::vec3(0,1,-1)] =  glm::vec3(-1,0,-1);
                vecMap[glm::vec3(-1,1,-1)] = glm::vec3(-1,-1,-1);
                
                vecMap[glm::vec3(1,0,-1)] = glm::vec3(0,1,-1);
                vecMap[glm::vec3(0,0,-1)] = glm::vec3(0,0,-1);
                vecMap[glm::vec3(-1,0,-1)] = glm::vec3(0,-1,-1);
                
                vecMap[glm::vec3(1,-1,-1)] = glm::vec3(1,1,-1);
                vecMap[glm::vec3(0,-1,-1)] = glm::vec3(1,0,-1);
                vecMap[glm::vec3(-1,-1,-1)] = glm::vec3(1,-1,-1);
            }
            break;
        case 2:
            if (direction < 0) {
                vecMap[glm::vec3(-0.5,-0.5,-0.5)] = glm::vec3(-0.5,0.5,-0.5);
                vecMap[glm::vec3(0.5,-0.5,-0.5)] = glm::vec3(-0.5,-0.5,-0.5);
                vecMap[glm::vec3(-0.5,0.5,-0.5)] = glm::vec3(0.5,0.5,-0.5);
                vecMap[glm::vec3(0.5,0.5,-0.5)] = glm::vec3(0.5,-0.5,-0.5);
            }
            else {
                vecMap[glm::vec3(-0.5,-0.5,-0.5)] = glm::vec3(0.5,-0.5,-0.5);
                vecMap[glm::vec3(0.5,-0.5,-0.5)] = glm::vec3(0.5,0.5,-0.5);
                vecMap[glm::vec3(-0.5,0.5,-0.5)] = glm::vec3(-0.5,-0.5,-0.5);
                vecMap[glm::vec3(0.5,0.5,-0.5)] = glm::vec3(-0.5,0.5,-0.5);
            }
            break;
        case 4:
            if (direction < 0) {
                vecMap[glm::vec3(1.5, 1.5 ,-1.5)] = glm::vec3(1.5, -1.5, -1.5);
                vecMap[glm::vec3(0.5, 1.5 ,-1.5)] = glm::vec3(1.5, -0.5, -1.5);
                vecMap[glm::vec3(-0.5, 1.5 ,-1.5)] = glm::vec3(1.5, 0.5, -1.5);
                vecMap[glm::vec3(-1.5, 1.5 ,-1.5)] = glm::vec3(1.5, 1.5, -1.5);

                vecMap[glm::vec3(1.5, 0.5 ,-1.5)] = glm::vec3(0.5, -1.5, -1.5);
                vecMap[glm::vec3(0.5, 0.5 ,-1.5)] = glm::vec3(0.5, -0.5, -1.5);
                vecMap[glm::vec3(-0.5, 0.5 ,-1.5)] = glm::vec3(0.5, 0.5, -1.5);
                vecMap[glm::vec3(-1.5, 0.5 ,-1.5)] = glm::vec3(0.5, 1.5, -1.5);

                vecMap[glm::vec3(1.5, -0.5 ,-1.5)] = glm::vec3(-0.5, -1.5, -1.5);
                vecMap[glm::vec3(0.5, -0.5 ,-1.5)] = glm::vec3(-0.5, -0.5, -1.5);
                vecMap[glm::vec3(-0.5, -0.5 ,-1.5)] = glm::vec3(-0.5, 0.5, -1.5);
                vecMap[glm::vec3(-1.5, -0.5 ,-1.5)] = glm::vec3(-0.5, 1.5, -1.5);

                vecMap[glm::vec3(1.5, -1.5 ,-1.5)] = glm::vec3(-1.5, -1.5, -1.5);
                vecMap[glm::vec3(0.5, -1.5 ,-1.5)] = glm::vec3(-1.5, -0.5, -1.5);
                vecMap[glm::vec3(-0.5, -1.5 ,-1.5)] = glm::vec3(-1.5, 0.5, -1.5);
                vecMap[glm::vec3(-1.5, -1.5 ,-1.5)] = glm::vec3(-1.5, 1.5, -1.5);
            }   
            else {
                vecMap[glm::vec3(1.5, 1.5 ,-1.5)] = glm::vec3(-1.5, 1.5, -1.5);
                vecMap[glm::vec3(0.5, 1.5 ,-1.5)] = glm::vec3(-1.5, 0.5, -1.5);
                vecMap[glm::vec3(-0.5, 1.5 ,-1.5)] = glm::vec3(-1.5, -0.5, -1.5);
                vecMap[glm::vec3(-1.5, 1.5 ,-1.5)] = glm::vec3(-1.5, -1.5, -1.5);

                vecMap[glm::vec3(1.5, 0.5 ,-1.5)] = glm::vec3(-0.5, 1.5, -1.5);
                vecMap[glm::vec3(0.5, 0.5 ,-1.5)] = glm::vec3(-0.5, 0.5, -1.5);
                vecMap[glm::vec3(-0.5, 0.5 ,-1.5)] = glm::vec3(-0.5, -0.5, -1.5);
                vecMap[glm::vec3(-1.5, 0.5 ,-1.5)] = glm::vec3(-0.5, -1.5, -1.5);

                vecMap[glm::vec3(1.5, -0.5 ,-1.5)] = glm::vec3(0.5, 1.5, -1.5);
                vecMap[glm::vec3(0.5, -0.5 ,-1.5)] = glm::vec3(0.5, 0.5, -1.5);
                vecMap[glm::vec3(-0.5, -0.5 ,-1.5)] = glm::vec3(0.5, -0.5, -1.5);
                vecMap[glm::vec3(-1.5, -0.5 ,-1.5)] = glm::vec3(0.5, -1.5, -1.5);

                vecMap[glm::vec3(1.5, -1.5 ,-1.5)] = glm::vec3(1.5, 1.5, -1.5);
                vecMap[glm::vec3(0.5, -1.5 ,-1.5)] = glm::vec3(1.5, 0.5, -1.5);
                vecMap[glm::vec3(-0.5, -1.5 ,-1.5)] = glm::vec3(1.5, -0.5, -1.5);
                vecMap[glm::vec3(-1.5, -1.5 ,-1.5)] = glm::vec3(1.5, -1.5, -1.5);
            }
            break;
        case 5:
            if (direction < 0) {
                vecMap[glm::vec3(2, 2 ,-2)] = glm::vec3(2, -2, -2);
                vecMap[glm::vec3(1, 2 ,-2)] = glm::vec3(2, -1, -2);
                vecMap[glm::vec3(0, 2 ,-2)] = glm::vec3(2, 0, -2);
                vecMap[glm::vec3(-1, 2 ,-2)] = glm::vec3(2, 1, -2);
                vecMap[glm::vec3(-2, 2 ,-2)] = glm::vec3(2, 2, -2);

                vecMap[glm::vec3(2, 1 ,-2)] = glm::vec3(1, -2, -2);
                vecMap[glm::vec3(1, 1 ,-2)] = glm::vec3(1, -1, -2);
                vecMap[glm::vec3(0, 1 ,-2)] = glm::vec3(1, 0, -2);
                vecMap[glm::vec3(-1, 1 ,-2)] = glm::vec3(1, 1, -2);
                vecMap[glm::vec3(-2, 1 ,-2)] = glm::vec3(1, 2, -2);

                vecMap[glm::vec3(2, 0 ,-2)] = glm::vec3(0, -2, -2);
                vecMap[glm::vec3(1, 0 ,-2)] = glm::vec3(0, -1, -2);
                vecMap[glm::vec3(0, 0 ,-2)] = glm::vec3(0, 0, -2);
                vecMap[glm::vec3(-1, 0 ,-2)] = glm::vec3(0, 1, -2);
                vecMap[glm::vec3(-2, 0 ,-2)] = glm::vec3(0, 2, -2);

                vecMap[glm::vec3(2, -1 ,-2)] = glm::vec3(-1, -2, -2);
                vecMap[glm::vec3(1, -1 ,-2)] = glm::vec3(-1, -1, -2);
                vecMap[glm::vec3(0, -1 ,-2)] = glm::vec3(-1, 0, -2);
                vecMap[glm::vec3(-1, -1 ,-2)] = glm::vec3(-1, 1, -2);
                vecMap[glm::vec3(-2, -1 ,-2)] = glm::vec3(-1, 2, -2);

                vecMap[glm::vec3(2, -2 ,-2)] = glm::vec3(-2, -2, -2);
                vecMap[glm::vec3(1, -2 ,-2)] = glm::vec3(-2, -1, -2);
                vecMap[glm::vec3(0, -2 ,-2)] = glm::vec3(-2, 0, -2);
                vecMap[glm::vec3(-1, -2 ,-2)] = glm::vec3(-2, 1, -2);
                vecMap[glm::vec3(-2, -2 ,-2)] = glm::vec3(-2, 2, -2);
            }
            else {
                vecMap[glm::vec3(2, 2 ,-2)] = glm::vec3(-2, 2, -2);
                vecMap[glm::vec3(1, 2 ,-2)] = glm::vec3(-2, 1, -2);
                vecMap[glm::vec3(0, 2 ,-2)] = glm::vec3(-2, 0, -2);
                vecMap[glm::vec3(-1, 2 ,-2)] = glm::vec3(-2, -1, -2);
                vecMap[glm::vec3(-2, 2 ,-2)] = glm::vec3(-2, -2, -2);

                vecMap[glm::vec3(2, 1 ,-2)] = glm::vec3(-1, 2, -2);
                vecMap[glm::vec3(1, 1 ,-2)] = glm::vec3(-1, 1, -2);
                vecMap[glm::vec3(0, 1 ,-2)] = glm::vec3(-1, 0, -2);
                vecMap[glm::vec3(-1, 1 ,-2)] = glm::vec3(-1, -1, -2);
                vecMap[glm::vec3(-2, 1 ,-2)] = glm::vec3(-1, -2, -2);

                vecMap[glm::vec3(2, 0 ,-2)] = glm::vec3(0, 2, -2);
                vecMap[glm::vec3(1, 0 ,-2)] = glm::vec3(0, 1, -2);
                vecMap[glm::vec3(0, 0 ,-2)] = glm::vec3(0, 0, -2);
                vecMap[glm::vec3(-1, 0 ,-2)] = glm::vec3(0, -1, -2);
                vecMap[glm::vec3(-2, 0 ,-2)] = glm::vec3(0, -2, -2);

                vecMap[glm::vec3(2, -1 ,-2)] = glm::vec3(1, 2, -2);
                vecMap[glm::vec3(1, -1 ,-2)] = glm::vec3(1, 1, -2);
                vecMap[glm::vec3(0, -1 ,-2)] = glm::vec3(1, 0, -2);
                vecMap[glm::vec3(-1, -1 ,-2)] = glm::vec3(1, -1, -2);
                vecMap[glm::vec3(-2, -1 ,-2)] = glm::vec3(1, -2, -2);

                vecMap[glm::vec3(2, -2 ,-2)] = glm::vec3(2, 2, -2);
                vecMap[glm::vec3(1, -2 ,-2)] = glm::vec3(2, 1, -2);
                vecMap[glm::vec3(0, -2 ,-2)] = glm::vec3(2, 0, -2);
                vecMap[glm::vec3(-1, -2 ,-2)] = glm::vec3(2, -1, -2);
                vecMap[glm::vec3(-2, -2 ,-2)] = glm::vec3(2, -2, -2);
            }
            break;
    }

    for (InnerCube* cube : innerCubes) {
        if (cube->GetPosition().z == -distance) {
            glm::vec3 position = cube->GetPosition();
            cube->UpdatePosition(vecMap[position]);
            std::cout << "BackCube index: " << cube->GetIndex() << " | position: " << position.x << " " << position.y << " " << position.z << std::endl;
        }
    }
}

void RubikCube::rotateLeft(int direction) {
std::map<glm::vec3, glm::vec3, RubikCube::Vec3Comparator> vecMap;
switch (size) {
    case 3:
        if (direction < 0) {
            vecMap[glm::vec3(-1,1,1)] = glm::vec3(-1,1,-1);
            vecMap[glm::vec3(-1,1,0)] =  glm::vec3(-1,0,-1);
            vecMap[glm::vec3(-1,1,-1)] = glm::vec3(-1,-1,-1);
            
            vecMap[glm::vec3(-1,0,1)] = glm::vec3(-1,1,0);
            vecMap[glm::vec3(-1,0,0)] = glm::vec3(-1,0,0);
            vecMap[glm::vec3(-1,0,-1)] = glm::vec3(-1,-1,0);
            
            vecMap[glm::vec3(-1,-1,1)] = glm::vec3(-1,1,1);
            vecMap[glm::vec3(-1,-1,0)] = glm::vec3(-1,0,1);
            vecMap[glm::vec3(-1,-1,-1)] = glm::vec3(-1,-1,1);
            }
        else {
            vecMap[glm::vec3(-1,1,1)] = glm::vec3(-1,-1,1);
            vecMap[glm::vec3(-1,1,0)] =  glm::vec3(-1,0,1);
            vecMap[glm::vec3(-1,1,-1)] = glm::vec3(-1,1,1);
            
            vecMap[glm::vec3(-1,0,1)] = glm::vec3(-1,-1,0);
            vecMap[glm::vec3(-1,0,0)] = glm::vec3(-1,0,0);
            vecMap[glm::vec3(-1,0,-1)] = glm::vec3(-1,1,0);
            
            vecMap[glm::vec3(-1,-1,1)] = glm::vec3(-1,-1,-1);
            vecMap[glm::vec3(-1,-1,0)] = glm::vec3(-1,0,-1);
            vecMap[glm::vec3(-1,-1,-1)] = glm::vec3(-1,1,-1);
        }
        break;
    case 2:
        if (direction < 0) {
            vecMap[glm::vec3(-0.5,-0.5,-0.5)] = glm::vec3(-0.5,-0.5,0.5);
            vecMap[glm::vec3(-0.5,0.5,-0.5)] = glm::vec3(-0.5,-0.5,-0.5);
            vecMap[glm::vec3(-0.5,-0.5,0.5)] = glm::vec3(-0.5,0.5,0.5);
            vecMap[glm::vec3(-0.5,0.5,0.5)] = glm::vec3(-0.5,0.5,-0.5);
        }
        else {
            vecMap[glm::vec3(-0.5,-0.5,-0.5)] = glm::vec3(-0.5,0.5,-0.5);
            vecMap[glm::vec3(-0.5,0.5,-0.5)] = glm::vec3(-0.5,0.5,0.5);
            vecMap[glm::vec3(-0.5,-0.5,0.5)] = glm::vec3(-0.5,-0.5,-0.5);
            vecMap[glm::vec3(-0.5,0.5,0.5)] = glm::vec3(-0.5,-0.5,0.5);
        }
        break;
    case 4:
        if (direction < 0) {
            vecMap[glm::vec3(-1.5, 1.5 ,1.5)] = glm::vec3(-1.5, 1.5, -1.5);
            vecMap[glm::vec3(-1.5, 1.5, 0.5)] = glm::vec3(-1.5, 0.5, -1.5);
            vecMap[glm::vec3(-1.5, 1.5, -0.5)] = glm::vec3(-1.5, -0.5, -1.5);
            vecMap[glm::vec3(-1.5, 1.5, -1.5)] = glm::vec3(-1.5, -1.5, -1.5);

            vecMap[glm::vec3(-1.5, 0.5 ,1.5)] = glm::vec3(-1.5, 1.5, -0.5);
            vecMap[glm::vec3(-1.5, 0.5, 0.5)] = glm::vec3(-1.5, 0.5, -0.5);
            vecMap[glm::vec3(-1.5, 0.5, -0.5)] = glm::vec3(-1.5, -0.5, -0.5);
            vecMap[glm::vec3(-1.5, 0.5, -1.5)] = glm::vec3(-1.5, -1.5, -0.5);

            vecMap[glm::vec3(-1.5, -0.5 ,1.5)] = glm::vec3(-1.5, 1.5, 0.5);
            vecMap[glm::vec3(-1.5, -0.5, 0.5)] = glm::vec3(-1.5, 0.5, 0.5); 
            vecMap[glm::vec3(-1.5, -0.5, -0.5)] = glm::vec3(-1.5, -0.5, 0.5);
            vecMap[glm::vec3(-1.5, -0.5, -1.5)] = glm::vec3(-1.5, -1.5, 0.5);

            vecMap[glm::vec3(-1.5, -1.5 ,1.5)] = glm::vec3(-1.5, 1.5, 1.5);
            vecMap[glm::vec3(-1.5, -1.5, 0.5)] = glm::vec3(-1.5, 0.5, 1.5);
            vecMap[glm::vec3(-1.5, -1.5, -0.5)] = glm::vec3(-1.5, -0.5, 1.5);
            vecMap[glm::vec3(-1.5, -1.5, -1.5)] = glm::vec3(-1.5, -1.5, 1.5);
        }
        else {
            vecMap[glm::vec3(-1.5, 1.5 ,1.5)] = glm::vec3(-1.5, -1.5, 1.5);
            vecMap[glm::vec3(-1.5, 1.5, 0.5)] = glm::vec3(-1.5, -0.5, 1.5);
            vecMap[glm::vec3(-1.5, 1.5, -0.5)] = glm::vec3(-1.5, 0.5, 1.5);
            vecMap[glm::vec3(-1.5, 1.5, -1.5)] = glm::vec3(-1.5, 1.5, 1.5);

            vecMap[glm::vec3(-1.5, 0.5 ,1.5)] = glm::vec3(-1.5, -1.5, 0.5);
            vecMap[glm::vec3(-1.5, 0.5, 0.5)] = glm::vec3(-1.5, -0.5, 0.5);
            vecMap[glm::vec3(-1.5, 0.5, -0.5)] = glm::vec3(-1.5, 0.5, 0.5);
            vecMap[glm::vec3(-1.5, 0.5, -1.5)] = glm::vec3(-1.5, 1.5, 0.5);

            vecMap[glm::vec3(-1.5, -0.5 ,1.5)] = glm::vec3(-1.5, -1.5, -0.5);
            vecMap[glm::vec3(-1.5, -0.5, 0.5)] = glm::vec3(-1.5, -0.5, -0.5);
            vecMap[glm::vec3(-1.5, -0.5, -0.5)] = glm::vec3(-1.5, 0.5, -0.5);
            vecMap[glm::vec3(-1.5, -0.5, -1.5)] = glm::vec3(-1.5, 1.5, -0.5);

            vecMap[glm::vec3(-1.5, -1.5 ,1.5)] = glm::vec3(-1.5, -1.5, -1.5);
            vecMap[glm::vec3(-1.5, -1.5, 0.5)] = glm::vec3(-1.5, -0.5, -1.5);
            vecMap[glm::vec3(-1.5, -1.5, -0.5)] = glm::vec3(-1.5, 0.5, -1.5);
            vecMap[glm::vec3(-1.5, -1.5, -1.5)] = glm::vec3(-1.5, 1.5, -1.5);
        }
        break;
    case 5:
        if (direction < 0) {
            vecMap[glm::vec3(-2, 2 ,2)] = glm::vec3(-2, 2, -2);
            vecMap[glm::vec3(-2, 2 ,1)] = glm::vec3(-2, 1, -2);
            vecMap[glm::vec3(-2, 2 ,0)] = glm::vec3(-2, 0, -2);
            vecMap[glm::vec3(-2, 2 ,-1)] = glm::vec3(-2, -1, -2);
            vecMap[glm::vec3(-2, 2 ,-2)] = glm::vec3(-2, -2, -2);

            vecMap[glm::vec3(-2, 1 ,2)] = glm::vec3(-2, 2, -1);
            vecMap[glm::vec3(-2, 1 ,1)] = glm::vec3(-2, 1, -1);
            vecMap[glm::vec3(-2, 1 ,0)] = glm::vec3(-2, 0, -1);
            vecMap[glm::vec3(-2, 1 ,-1)] = glm::vec3(-2, -1, -1);
            vecMap[glm::vec3(-2, 1 ,-2)] = glm::vec3(-2, -2, -1);

            vecMap[glm::vec3(-2, 0 ,2)] = glm::vec3(-2, 2, 0);
            vecMap[glm::vec3(-2, 0 ,1)] = glm::vec3(-2, 1, 0);
            vecMap[glm::vec3(-2, 0 ,0)] = glm::vec3(-2, 0, 0);
            vecMap[glm::vec3(-2, 0 ,-1)] = glm::vec3(-2, -1, 0);
            vecMap[glm::vec3(-2, 0 ,-2)] = glm::vec3(-2, -2, 0);

            vecMap[glm::vec3(-2, -1 ,2)] = glm::vec3(-2, 2, 1);
            vecMap[glm::vec3(-2, -1 ,1)] = glm::vec3(-2, 1, 1);
            vecMap[glm::vec3(-2, -1 ,0)] = glm::vec3(-2, 0, 1);
            vecMap[glm::vec3(-2, -1 ,-1)] = glm::vec3(-2, -1, 1);
            vecMap[glm::vec3(-2, -1 ,-2)] = glm::vec3(-2, -2, 1);

            vecMap[glm::vec3(-2, -2 ,2)] = glm::vec3(-2, 2, 2);
            vecMap[glm::vec3(-2, -2 ,1)] = glm::vec3(-2, 1, 2);
            vecMap[glm::vec3(-2, -2 ,0)] = glm::vec3(-2, 0, 2);
            vecMap[glm::vec3(-2, -2 ,-1)] = glm::vec3(-2, -1, 2);
            vecMap[glm::vec3(-2, -2 ,-2)] = glm::vec3(-2, -2, 2);
        }
        else {
            vecMap[glm::vec3(-2, 2 ,2)] = glm::vec3(-2, -2, 2);
            vecMap[glm::vec3(-2, 2 ,1)] = glm::vec3(-2, -1, 2);
            vecMap[glm::vec3(-2, 2 ,0)] = glm::vec3(-2, 0, 2);
            vecMap[glm::vec3(-2, 2 ,-1)] = glm::vec3(-2, 1, 2);
            vecMap[glm::vec3(-2, 2 ,-2)] = glm::vec3(-2, 2, 2);

            vecMap[glm::vec3(-2, 1 ,2)] = glm::vec3(-2, -2, 1);
            vecMap[glm::vec3(-2, 1 ,1)] = glm::vec3(-2, -1, 1);
            vecMap[glm::vec3(-2, 1 ,0)] = glm::vec3(-2, 0, 1);
            vecMap[glm::vec3(-2, 1 ,-1)] = glm::vec3(-2, 1, 1);
            vecMap[glm::vec3(-2, 1 ,-2)] = glm::vec3(-2, 2, 1);

            vecMap[glm::vec3(-2, 0 ,2)] = glm::vec3(-2, -2, 0);
            vecMap[glm::vec3(-2, 0 ,1)] = glm::vec3(-2, -1, 0);
            vecMap[glm::vec3(-2, 0 ,0)] = glm::vec3(-2, 0, 0);
            vecMap[glm::vec3(-2, 0 ,-1)] = glm::vec3(-2, 1, 0);
            vecMap[glm::vec3(-2, 0 ,-2)] = glm::vec3(-2, 2, 0);

            vecMap[glm::vec3(-2, -1 ,2)] = glm::vec3(-2, -2, -1);
            vecMap[glm::vec3(-2, -1 ,1)] = glm::vec3(-2, -1, -1);
            vecMap[glm::vec3(-2, -1 ,0)] = glm::vec3(-2, 0, -1);
            vecMap[glm::vec3(-2, -1 ,-1)] = glm::vec3(-2, 1, -1);
            vecMap[glm::vec3(-2, -1 ,-2)] = glm::vec3(-2, 2, -1);

            vecMap[glm::vec3(-2, -2 ,2)] = glm::vec3(-2, -2, -2);
            vecMap[glm::vec3(-2, -2 ,1)] = glm::vec3(-2, -1, -2);
            vecMap[glm::vec3(-2, -2 ,0)] = glm::vec3(-2, 0, -2);
            vecMap[glm::vec3(-2, -2 ,-1)] = glm::vec3(-2, 1, -2);
            vecMap[glm::vec3(-2, -2 ,-2)] = glm::vec3(-2, 2, -2);
        }
        break;
    }

    for (InnerCube* cube : innerCubes) {
        if (cube->GetPosition().x == -distance) {
            glm::vec3 position = cube->GetPosition();
            cube->UpdatePosition(vecMap[position]);
            std::cout << "LeftCube index: " << cube->GetIndex() << " | position: " << position.x << " " << position.y << " " << position.z << std::endl;
        }
    }
}

void RubikCube::rotateRight(int direction) {
std::map<glm::vec3, glm::vec3, RubikCube::Vec3Comparator> vecMap;
switch (size) {
    case 3:
        if (direction < 0) { 
            vecMap[glm::vec3(1,1,1)] = glm::vec3(1,1,-1);
            vecMap[glm::vec3(1,1,0)] =  glm::vec3(1,0,-1);
            vecMap[glm::vec3(1,1,-1)] = glm::vec3(1,-1,-1);
            
            vecMap[glm::vec3(1,0,1)] = glm::vec3(1,1,0);
            vecMap[glm::vec3(1,0,0)] = glm::vec3(1,0,0);
            vecMap[glm::vec3(1,0,-1)] = glm::vec3(1,-1,0);
            
            vecMap[glm::vec3(1,-1,1)] = glm::vec3(1,1,1);
            vecMap[glm::vec3(1,-1,0)] = glm::vec3(1,0,1);
            vecMap[glm::vec3(1,-1,-1)] = glm::vec3(1,-1,1);
            }
        else {
            vecMap[glm::vec3(1,1,1)] = glm::vec3(1,-1,1);
            vecMap[glm::vec3(1,1,0)] =  glm::vec3(1,0,1);
            vecMap[glm::vec3(1,1,-1)] = glm::vec3(1,1,1);
            
            vecMap[glm::vec3(1,0,1)] = glm::vec3(1,-1,0);
            vecMap[glm::vec3(1,0,0)] = glm::vec3(1,0,0);
            vecMap[glm::vec3(1,0,-1)] = glm::vec3(1,1,0);
            
            vecMap[glm::vec3(1,-1,1)] = glm::vec3(1,-1,-1);
            vecMap[glm::vec3(1,-1,0)] = glm::vec3(1,0,-1);
            vecMap[glm::vec3(1,-1,-1)] = glm::vec3(1,1,-1);
        }
        break;
    case 2:
        if (direction < 0) {
            vecMap[glm::vec3(0.5,-0.5,-0.5)] = glm::vec3(0.5,-0.5,0.5);
            vecMap[glm::vec3(0.5,0.5,-0.5)] = glm::vec3(0.5,-0.5,-0.5);
            vecMap[glm::vec3(0.5,-0.5,0.5)] = glm::vec3(0.5,0.5,0.5);
            vecMap[glm::vec3(0.5,0.5,0.5)] = glm::vec3(0.5,0.5,-0.5);
        }
        else {
            vecMap[glm::vec3(0.5,-0.5,-0.5)] = glm::vec3(0.5,0.5,-0.5);
            vecMap[glm::vec3(0.5,0.5,-0.5)] = glm::vec3(0.5,0.5,0.5);
            vecMap[glm::vec3(0.5,-0.5,0.5)] = glm::vec3(0.5,-0.5,-0.5);
            vecMap[glm::vec3(0.5,0.5,0.5)] = glm::vec3(0.5,-0.5,0.5);
        }
        break;
    case 4:
        if (direction < 0) {
            vecMap[glm::vec3(1.5, 1.5 ,1.5)] = glm::vec3(1.5, 1.5, -1.5);
            vecMap[glm::vec3(1.5, 1.5, 0.5)] = glm::vec3(1.5, 0.5, -1.5);
            vecMap[glm::vec3(1.5, 1.5, -0.5)] = glm::vec3(1.5, -0.5, -1.5);
            vecMap[glm::vec3(1.5, 1.5, -1.5)] = glm::vec3(1.5, -1.5, -1.5);

            vecMap[glm::vec3(1.5, 0.5 ,1.5)] = glm::vec3(1.5, 1.5, -0.5);
            vecMap[glm::vec3(1.5, 0.5, 0.5)] = glm::vec3(1.5, 0.5, -0.5);
            vecMap[glm::vec3(1.5, 0.5, -0.5)] = glm::vec3(1.5, -0.5, -0.5);
            vecMap[glm::vec3(1.5, 0.5, -1.5)] = glm::vec3(1.5, -1.5, -0.5);

            vecMap[glm::vec3(1.5, -0.5 ,1.5)] = glm::vec3(1.5, 1.5, 0.5);
            vecMap[glm::vec3(1.5, -0.5, 0.5)] = glm::vec3(1.5, 0.5, 0.5); 
            vecMap[glm::vec3(1.5, -0.5, -0.5)] = glm::vec3(1.5, -0.5, 0.5);
            vecMap[glm::vec3(1.5, -0.5, -1.5)] = glm::vec3(1.5, -1.5, 0.5);

            vecMap[glm::vec3(1.5, -1.5 ,1.5)] = glm::vec3(1.5, 1.5, 1.5);
            vecMap[glm::vec3(1.5, -1.5, 0.5)] = glm::vec3(1.5, 0.5, 1.5);
            vecMap[glm::vec3(1.5, -1.5, -0.5)] = glm::vec3(1.5, -0.5, 1.5);
            vecMap[glm::vec3(1.5, -1.5, -1.5)] = glm::vec3(1.5, -1.5, 1.5);
        }
        else {
            vecMap[glm::vec3(1.5, 1.5 ,1.5)] = glm::vec3(1.5, -1.5, 1.5);
            vecMap[glm::vec3(1.5, 1.5, 0.5)] = glm::vec3(1.5, -0.5, 1.5);
            vecMap[glm::vec3(1.5, 1.5, -0.5)] = glm::vec3(1.5, 0.5, 1.5);
            vecMap[glm::vec3(1.5, 1.5, -1.5)] = glm::vec3(1.5, 1.5, 1.5);

            vecMap[glm::vec3(1.5, 0.5 ,1.5)] = glm::vec3(1.5, -1.5, 0.5);
            vecMap[glm::vec3(1.5, 0.5, 0.5)] = glm::vec3(1.5, -0.5, 0.5);
            vecMap[glm::vec3(1.5, 0.5, -0.5)] = glm::vec3(1.5, 0.5, 0.5);
            vecMap[glm::vec3(1.5, 0.5, -1.5)] = glm::vec3(1.5, 1.5, 0.5);

            vecMap[glm::vec3(1.5, -0.5 ,1.5)] = glm::vec3(1.5, -1.5, -0.5);
            vecMap[glm::vec3(1.5, -0.5, 0.5)] = glm::vec3(1.5, -0.5, -0.5);
            vecMap[glm::vec3(1.5, -0.5, -0.5)] = glm::vec3(1.5, 0.5, -0.5);
            vecMap[glm::vec3(1.5, -0.5, -1.5)] = glm::vec3(1.5, 1.5, -0.5);

            vecMap[glm::vec3(1.5, -1.5 ,1.5)] = glm::vec3(1.5, -1.5, -1.5);
            vecMap[glm::vec3(1.5, -1.5, 0.5)] = glm::vec3(1.5, -0.5, -1.5);
            vecMap[glm::vec3(1.5, -1.5, -0.5)] = glm::vec3(1.5, 0.5, -1.5);
            vecMap[glm::vec3(1.5, -1.5, -1.5)] = glm::vec3(1.5, 1.5, -1.5);
        }
        break;
    case 5:
        if (direction < 0) {
            vecMap[glm::vec3(2, 2 ,2)] = glm::vec3(2, 2, -2);
            vecMap[glm::vec3(2, 2 ,1)] = glm::vec3(2, 1, -2);
            vecMap[glm::vec3(2, 2 ,0)] = glm::vec3(2, 0, -2);
            vecMap[glm::vec3(2, 2 ,-1)] = glm::vec3(2, -1, -2);
            vecMap[glm::vec3(2, 2 ,-2)] = glm::vec3(2, -2, -2);

            vecMap[glm::vec3(2, 1 ,2)] = glm::vec3(2, 2, -1);
            vecMap[glm::vec3(2, 1 ,1)] = glm::vec3(2, 1, -1);
            vecMap[glm::vec3(2, 1 ,0)] = glm::vec3(2, 0, -1);
            vecMap[glm::vec3(2, 1 ,-1)] = glm::vec3(2, -1, -1);
            vecMap[glm::vec3(2, 1 ,-2)] = glm::vec3(2, -2, -1);

            vecMap[glm::vec3(2, 0 ,2)] = glm::vec3(2, 2, 0);
            vecMap[glm::vec3(2, 0 ,1)] = glm::vec3(2, 1, 0);
            vecMap[glm::vec3(2, 0 ,0)] = glm::vec3(2, 0, 0);
            vecMap[glm::vec3(2, 0 ,-1)] = glm::vec3(2, -1, 0);
            vecMap[glm::vec3(2, 0 ,-2)] = glm::vec3(2, -2, 0);

            vecMap[glm::vec3(2, -1 ,2)] = glm::vec3(2, 2, 1);
            vecMap[glm::vec3(2, -1 ,1)] = glm::vec3(2, 1, 1);
            vecMap[glm::vec3(2, -1 ,0)] = glm::vec3(2, 0, 1);
            vecMap[glm::vec3(2, -1 ,-1)] = glm::vec3(2, -1, 1);
            vecMap[glm::vec3(2, -1 ,-2)] = glm::vec3(2, -2, 1);

            vecMap[glm::vec3(2, -2 ,2)] = glm::vec3(2, 2, 2);
            vecMap[glm::vec3(2, -2 ,1)] = glm::vec3(2, 1, 2);
            vecMap[glm::vec3(2, -2 ,0)] = glm::vec3(2, 0, 2);
            vecMap[glm::vec3(2, -2 ,-1)] = glm::vec3(2, -1, 2);
            vecMap[glm::vec3(2, -2 ,-2)] = glm::vec3(2, -2, 2);
        }
        else {
            vecMap[glm::vec3(2, 2 ,2)] = glm::vec3(2, -2, 2);
            vecMap[glm::vec3(2, 2 ,1)] = glm::vec3(2, -1, 2);
            vecMap[glm::vec3(2, 2 ,0)] = glm::vec3(2, 0, 2);
            vecMap[glm::vec3(2, 2 ,-1)] = glm::vec3(2, 1, 2);
            vecMap[glm::vec3(2, 2 ,-2)] = glm::vec3(2, 2, 2);

            vecMap[glm::vec3(2, 1 ,2)] = glm::vec3(2, -2, 1);
            vecMap[glm::vec3(2, 1 ,1)] = glm::vec3(2, -1, 1);
            vecMap[glm::vec3(2, 1 ,0)] = glm::vec3(2, 0, 1);
            vecMap[glm::vec3(2, 1 ,-1)] = glm::vec3(2, 1, 1);
            vecMap[glm::vec3(2, 1 ,-2)] = glm::vec3(2, 2, 1);

            vecMap[glm::vec3(2, 0 ,2)] = glm::vec3(2, -2, 0);
            vecMap[glm::vec3(2, 0 ,1)] = glm::vec3(2, -1, 0);
            vecMap[glm::vec3(2, 0 ,0)] = glm::vec3(2, 0, 0);
            vecMap[glm::vec3(2, 0 ,-1)] = glm::vec3(2, 1, 0);
            vecMap[glm::vec3(2, 0 ,-2)] = glm::vec3(2, 2, 0);

            vecMap[glm::vec3(2, -1 ,2)] = glm::vec3(2, -2, -1);
            vecMap[glm::vec3(2, -1 ,1)] = glm::vec3(2, -1, -1);
            vecMap[glm::vec3(2, -1 ,0)] = glm::vec3(2, 0, -1);
            vecMap[glm::vec3(2, -1 ,-1)] = glm::vec3(2, 1, -1);
            vecMap[glm::vec3(2, -1 ,-2)] = glm::vec3(2, 2, -1);

            vecMap[glm::vec3(2, -2 ,2)] = glm::vec3(2, -2, -2);
            vecMap[glm::vec3(2, -2 ,1)] = glm::vec3(2, -1, -2);
            vecMap[glm::vec3(2, -2 ,0)] = glm::vec3(2, 0, -2);
            vecMap[glm::vec3(2, -2 ,-1)] = glm::vec3(2, 1, -2);
            vecMap[glm::vec3(2, -2 ,-2)] = glm::vec3(2, 2, -2);
        }
        break;
    }

    for (InnerCube* cube : innerCubes) {
        if (cube->GetPosition().x == distance) {
            glm::vec3 position = cube->GetPosition();
            cube->UpdatePosition(vecMap[position]);
            std::cout << "RightCube index: " << cube->GetIndex() << " | position: " << position.x << " " << position.y << " " << position.z << std::endl;
        }
    }
}

void RubikCube::rotateUp(int direction) {
std::map<glm::vec3, glm::vec3, RubikCube::Vec3Comparator> vecMap;
switch (size) {
    case 3:
        if (direction < 0) {
            vecMap[glm::vec3(1,1,1)] = glm::vec3(-1,1,1);
            vecMap[glm::vec3(1,1,0)] =  glm::vec3(0,1,1);
            vecMap[glm::vec3(1,1,-1)] = glm::vec3(1,1,1);
            
            vecMap[glm::vec3(0,1,1)] = glm::vec3(-1,1,0);
            vecMap[glm::vec3(0,1,0)] = glm::vec3(0,1,0);
            vecMap[glm::vec3(0,1,-1)] = glm::vec3(1,1,0);
            
            vecMap[glm::vec3(-1,1,1)] = glm::vec3(-1,1,-1);
            vecMap[glm::vec3(-1,1,0)] = glm::vec3(0,1,-1);
            vecMap[glm::vec3(-1,1,-1)] = glm::vec3(1,1,-1);
        }
        else {
            vecMap[glm::vec3(1,1,1)] = glm::vec3(1,1,-1);    
            vecMap[glm::vec3(1,1,0)] =  glm::vec3(0,1,-1);
            vecMap[glm::vec3(1,1,-1)] = glm::vec3(-1,1,-1);
            
            vecMap[glm::vec3(0,1,1)] = glm::vec3(1,1,0);
            vecMap[glm::vec3(0,1,0)] = glm::vec3(0,1,0);
            vecMap[glm::vec3(0,1,-1)] = glm::vec3(-1,1,0);
            
            vecMap[glm::vec3(-1,1,1)] = glm::vec3(1,1,1);
            vecMap[glm::vec3(-1,1,0)] = glm::vec3(0,1,1);
            vecMap[glm::vec3(-1,1,-1)] = glm::vec3(-1,1,1);
        }
        break;
    case 2:
        if (direction < 0) {
            vecMap[glm::vec3(-0.5,0.5,-0.5)] = glm::vec3(0.5,0.5,-0.5);
            vecMap[glm::vec3(0.5,0.5,-0.5)] = glm::vec3(0.5,0.5,0.5);
            vecMap[glm::vec3(-0.5,0.5,0.5)] = glm::vec3(-0.5,0.5,-0.5);
            vecMap[glm::vec3(0.5,0.5,0.5)] = glm::vec3(-0.5,0.5,0.5);
        }
        else {
            vecMap[glm::vec3(-0.5,0.5,-0.5)] = glm::vec3(-0.5,0.5,0.5);
            vecMap[glm::vec3(0.5,0.5,-0.5)] = glm::vec3(-0.5,0.5,-0.5);
            vecMap[glm::vec3(-0.5,0.5,0.5)] = glm::vec3(0.5,0.5,0.5);
            vecMap[glm::vec3(0.5,0.5,0.5)] = glm::vec3(0.5,0.5,-0.5);
        }
        break;
    case 4:
        if (direction < 0) {
            vecMap[glm::vec3(1.5, 1.5 ,1.5)] = glm::vec3(-1.5, 1.5, 1.5);
            vecMap[glm::vec3(1.5, 1.5 ,0.5)] = glm::vec3(-0.5, 1.5, 1.5);
            vecMap[glm::vec3(1.5, 1.5 ,-0.5)] = glm::vec3(0.5, 1.5, 1.5);
            vecMap[glm::vec3(1.5, 1.5 ,-1.5)] = glm::vec3(1.5, 1.5, 1.5);

            vecMap[glm::vec3(0.5, 1.5 ,1.5)] = glm::vec3(-1.5, 1.5, 0.5);
            vecMap[glm::vec3(0.5, 1.5 ,0.5)] = glm::vec3(-0.5, 1.5, 0.5);
            vecMap[glm::vec3(0.5, 1.5 ,-0.5)] = glm::vec3(0.5, 1.5, 0.5);
            vecMap[glm::vec3(0.5, 1.5 ,-1.5)] = glm::vec3(1.5, 1.5, 0.5);

            vecMap[glm::vec3(-0.5, 1.5 ,1.5)] = glm::vec3(-1.5, 1.5, -0.5);
            vecMap[glm::vec3(-0.5, 1.5 ,0.5)] = glm::vec3(-0.5, 1.5, -0.5);
            vecMap[glm::vec3(-0.5, 1.5 ,-0.5)] = glm::vec3(0.5, 1.5, -0.5);
            vecMap[glm::vec3(-0.5, 1.5 ,-1.5)] = glm::vec3(1.5, 1.5, -0.5);

            vecMap[glm::vec3(-1.5, 1.5 ,1.5)] = glm::vec3(-1.5, 1.5, -1.5);
            vecMap[glm::vec3(-1.5, 1.5 ,0.5)] = glm::vec3(-0.5, 1.5, -1.5);
            vecMap[glm::vec3(-1.5, 1.5 ,-0.5)] = glm::vec3(0.5, 1.5, -1.5);
            vecMap[glm::vec3(-1.5, 1.5 ,-1.5)] = glm::vec3(1.5, 1.5, -1.5);
        }
        else{
            vecMap[glm::vec3(1.5, 1.5 ,1.5)] = glm::vec3(1.5, 1.5, -1.5);
            vecMap[glm::vec3(1.5, 1.5 ,0.5)] = glm::vec3(0.5, 1.5, -1.5);
            vecMap[glm::vec3(1.5, 1.5 ,-0.5)] = glm::vec3(-0.5, 1.5, -1.5);
            vecMap[glm::vec3(1.5, 1.5 ,-1.5)] = glm::vec3(-1.5, 1.5, -1.5);

            vecMap[glm::vec3(0.5, 1.5 ,1.5)] = glm::vec3(1.5, 1.5, -0.5);
            vecMap[glm::vec3(0.5, 1.5 ,0.5)] = glm::vec3(0.5, 1.5, -0.5);
            vecMap[glm::vec3(0.5, 1.5 ,-0.5)] = glm::vec3(-0.5, 1.5, -0.5);
            vecMap[glm::vec3(0.5, 1.5 ,-1.5)] = glm::vec3(-1.5, 1.5, -0.5);

            vecMap[glm::vec3(-0.5, 1.5 ,1.5)] = glm::vec3(1.5, 1.5, 0.5);
            vecMap[glm::vec3(-0.5, 1.5 ,0.5)] = glm::vec3(0.5, 1.5, 0.5);
            vecMap[glm::vec3(-0.5, 1.5 ,-0.5)] = glm::vec3(-0.5, 1.5, 0.5);
            vecMap[glm::vec3(-0.5, 1.5 ,-1.5)] = glm::vec3(-1.5, 1.5, 0.5);

            vecMap[glm::vec3(-1.5, 1.5 ,1.5)] = glm::vec3(1.5, 1.5, 1.5);
            vecMap[glm::vec3(-1.5, 1.5 ,0.5)] = glm::vec3(0.5, 1.5, 1.5);
            vecMap[glm::vec3(-1.5, 1.5 ,-0.5)] = glm::vec3(-0.5, 1.5, 1.5);
            vecMap[glm::vec3(-1.5, 1.5 ,-1.5)] = glm::vec3(-1.5, 1.5, 1.5);
        }
        break;
    case 5:
        if (direction < 0) {
            vecMap[glm::vec3(2, 2 ,2)] = glm::vec3(-2, 2, 2);
            vecMap[glm::vec3(2, 2 ,1)] = glm::vec3(-1, 2, 2);
            vecMap[glm::vec3(2, 2 ,0)] = glm::vec3(0, 2, 2);
            vecMap[glm::vec3(2, 2 ,-1)] = glm::vec3(1, 2, 2);
            vecMap[glm::vec3(2, 2 ,-2)] = glm::vec3(2, 2, 2);

            vecMap[glm::vec3(1, 2 ,2)] = glm::vec3(-2, 2, 1);
            vecMap[glm::vec3(1, 2 ,1)] = glm::vec3(-1, 2, 1);
            vecMap[glm::vec3(1, 2 ,0)] = glm::vec3(0, 2, 1);
            vecMap[glm::vec3(1, 2 ,-1)] = glm::vec3(1, 2, 1);
            vecMap[glm::vec3(1, 2 ,-2)] = glm::vec3(2, 2, 1);

            vecMap[glm::vec3(0, 2 ,2)] = glm::vec3(-2, 2, 0);
            vecMap[glm::vec3(0, 2 ,1)] = glm::vec3(-1, 2, 0);
            vecMap[glm::vec3(0, 2 ,0)] = glm::vec3(0, 2, 0);
            vecMap[glm::vec3(0, 2 ,-1)] = glm::vec3(1, 2, 0);
            vecMap[glm::vec3(0, 2 ,-2)] = glm::vec3(2, 2, 0);

            vecMap[glm::vec3(-1, 2 ,2)] = glm::vec3(-2, 2, -1);
            vecMap[glm::vec3(-1, 2 ,1)] = glm::vec3(-1, 2, -1);
            vecMap[glm::vec3(-1, 2 ,0)] = glm::vec3(0, 2, -1);
            vecMap[glm::vec3(-1, 2 ,-1)] = glm::vec3(1, 2, -1);
            vecMap[glm::vec3(-1, 2 ,-2)] = glm::vec3(2, 2, -1);

            vecMap[glm::vec3(-2, 2 ,2)] = glm::vec3(-2, 2, -2);
            vecMap[glm::vec3(-2, 2 ,1)] = glm::vec3(-1, 2, -2);
            vecMap[glm::vec3(-2, 2 ,0)] = glm::vec3(0, 2, -2);
            vecMap[glm::vec3(-2, 2 ,-1)] = glm::vec3(1, 2, -2);
            vecMap[glm::vec3(-2, 2 ,-2)] = glm::vec3(2, 2, -2);
        }
        else {
            vecMap[glm::vec3(2, 2 ,2)] = glm::vec3(2, 2, -2);
            vecMap[glm::vec3(2, 2 ,1)] = glm::vec3(1, 2, -2);
            vecMap[glm::vec3(2, 2 ,0)] = glm::vec3(0, 2, -2);
            vecMap[glm::vec3(2, 2 ,-1)] = glm::vec3(-1, 2, -2);
            vecMap[glm::vec3(2, 2 ,-2)] = glm::vec3(-2, 2, -2);

            vecMap[glm::vec3(1, 2 ,2)] = glm::vec3(2, 2, -1);
            vecMap[glm::vec3(1, 2 ,1)] = glm::vec3(1, 2, -1);
            vecMap[glm::vec3(1, 2 ,0)] = glm::vec3(0, 2, -1);
            vecMap[glm::vec3(1, 2 ,-1)] = glm::vec3(-1, 2, -1);
            vecMap[glm::vec3(1, 2 ,-2)] = glm::vec3(-2, 2, -1);

            vecMap[glm::vec3(0, 2 ,2)] = glm::vec3(2, 2, 0);
            vecMap[glm::vec3(0, 2 ,1)] = glm::vec3(1, 2, 0);
            vecMap[glm::vec3(0, 2 ,0)] = glm::vec3(0, 2, 0);
            vecMap[glm::vec3(0, 2 ,-1)] = glm::vec3(-1, 2, 0);
            vecMap[glm::vec3(0, 2 ,-2)] = glm::vec3(-2, 2, 0);

            vecMap[glm::vec3(-1, 2 ,2)] = glm::vec3(2, 2, 1);
            vecMap[glm::vec3(-1, 2 ,1)] = glm::vec3(1, 2, 1);
            vecMap[glm::vec3(-1, 2 ,0)] = glm::vec3(0, 2, 1);
            vecMap[glm::vec3(-1, 2 ,-1)] = glm::vec3(-1, 2, 1);
            vecMap[glm::vec3(-1, 2 ,-2)] = glm::vec3(-2, 2, 1);

            vecMap[glm::vec3(-2, 2 ,2)] = glm::vec3(2, 2, 2);
            vecMap[glm::vec3(-2, 2 ,1)] = glm::vec3(1, 2, 2);
            vecMap[glm::vec3(-2, 2 ,0)] = glm::vec3(0, 2, 2);
            vecMap[glm::vec3(-2, 2 ,-1)] = glm::vec3(-1, 2, 2);
            vecMap[glm::vec3(-2, 2 ,-2)] = glm::vec3(-2, 2, 2);
        }
        break;
    } 

    for (InnerCube* cube : innerCubes) {
        if (cube->GetPosition().y == distance) {
            glm::vec3 position = cube->GetPosition();
            cube->UpdatePosition(vecMap[position]);
            std::cout << "UpCube index: " << cube->GetIndex() << " | position: " << position.x << " " << position.y << " " << position.z << std::endl;
        }
    }
}


void RubikCube::rotateDown(int direction) {
std::map<glm::vec3, glm::vec3, RubikCube::Vec3Comparator> vecMap;
switch (size) {
    case 3:
        if (direction < 0) {
            vecMap[glm::vec3(1,-1,1)] = glm::vec3(-1,-1,1);
            vecMap[glm::vec3(1,-1,0)] =  glm::vec3(0,-1,1);
            vecMap[glm::vec3(1,-1,-1)] = glm::vec3(1,-1,1);
            
            vecMap[glm::vec3(0,-1,1)] = glm::vec3(-1,-1,0);
            vecMap[glm::vec3(0,-1,0)] = glm::vec3(0,-1,0);
            vecMap[glm::vec3(0,-1,-1)] = glm::vec3(1,-1,0);
            
            vecMap[glm::vec3(-1,-1,1)] = glm::vec3(-1,-1,-1);
            vecMap[glm::vec3(-1,-1,0)] = glm::vec3(0,-1,-1);
            vecMap[glm::vec3(-1,-1,-1)] = glm::vec3(1,-1,-1);
        }
        else {
            vecMap[glm::vec3(1,-1,1)] = glm::vec3(1,-1,-1);    
            vecMap[glm::vec3(1,-1,0)] =  glm::vec3(0,-1,-1);
            vecMap[glm::vec3(1,-1,-1)] = glm::vec3(-1,-1,-1);
            
            vecMap[glm::vec3(0,-1,1)] = glm::vec3(1,-1,0);
            vecMap[glm::vec3(0,-1,0)] = glm::vec3(0,-1,0);
            vecMap[glm::vec3(0,-1,-1)] = glm::vec3(-1,-1,0);
            
            vecMap[glm::vec3(-1,-1,1)] = glm::vec3(1,-1,1);
            vecMap[glm::vec3(-1,-1,0)] = glm::vec3(0,-1,1);
            vecMap[glm::vec3(-1,-1,-1)] = glm::vec3(-1,-1,1);
        }
        break;
    case 2:
        if (direction < 0) {
            vecMap[glm::vec3(-0.5,-0.5,-0.5)] = glm::vec3(0.5,-0.5,-0.5);
            vecMap[glm::vec3(0.5,-0.5,-0.5)] = glm::vec3(0.5,-0.5,0.5);
            vecMap[glm::vec3(-0.5,-0.5,0.5)] = glm::vec3(-0.5,-0.5,-0.5);
            vecMap[glm::vec3(0.5,-0.5,0.5)] = glm::vec3(-0.5,-0.5,0.5);
        }
        else {
            vecMap[glm::vec3(-0.5,-0.5,-0.5)] = glm::vec3(-0.5,-0.5,0.5);
            vecMap[glm::vec3(0.5,-0.5,-0.5)] = glm::vec3(-0.5,-0.5,-0.5);
            vecMap[glm::vec3(-0.5,-0.5,0.5)] = glm::vec3(0.5,-0.5,0.5);
            vecMap[glm::vec3(0.5,-0.5,0.5)] = glm::vec3(0.5,-0.5,-0.5);
        }
        break;
       case 4:
        if (direction < 0) {
            vecMap[glm::vec3(1.5, -1.5 ,1.5)] = glm::vec3(-1.5, -1.5, 1.5);
            vecMap[glm::vec3(1.5, -1.5 ,0.5)] = glm::vec3(-0.5, -1.5, 1.5);
            vecMap[glm::vec3(1.5, -1.5 ,-0.5)] = glm::vec3(0.5, -1.5, 1.5);
            vecMap[glm::vec3(1.5, -1.5 ,-1.5)] = glm::vec3(1.5, -1.5, 1.5);

            vecMap[glm::vec3(0.5, -1.5 ,1.5)] = glm::vec3(-1.5, -1.5, 0.5);
            vecMap[glm::vec3(0.5, -1.5 ,0.5)] = glm::vec3(-0.5, -1.5, 0.5);
            vecMap[glm::vec3(0.5, -1.5 ,-0.5)] = glm::vec3(0.5, -1.5, 0.5);
            vecMap[glm::vec3(0.5, -1.5 ,-1.5)] = glm::vec3(1.5, -1.5, 0.5);

            vecMap[glm::vec3(-0.5, -1.5 ,1.5)] = glm::vec3(-1.5, -1.5, -0.5);
            vecMap[glm::vec3(-0.5, -1.5 ,0.5)] = glm::vec3(-0.5, -1.5, -0.5);
            vecMap[glm::vec3(-0.5, -1.5 ,-0.5)] = glm::vec3(0.5, -1.5, -0.5);
            vecMap[glm::vec3(-0.5, -1.5 ,-1.5)] = glm::vec3(1.5, -1.5, -0.5);

            vecMap[glm::vec3(-1.5, -1.5 ,1.5)] = glm::vec3(-1.5, -1.5, -1.5);
            vecMap[glm::vec3(-1.5, -1.5 ,0.5)] = glm::vec3(-0.5, -1.5, -1.5);
            vecMap[glm::vec3(-1.5, -1.5 ,-0.5)] = glm::vec3(0.5, -1.5, -1.5);
            vecMap[glm::vec3(-1.5, -1.5 ,-1.5)] = glm::vec3(1.5, -1.5, -1.5);
        }
        else{
            vecMap[glm::vec3(1.5, -1.5 ,1.5)] = glm::vec3(1.5, -1.5, -1.5);
            vecMap[glm::vec3(1.5, -1.5 ,0.5)] = glm::vec3(0.5, -1.5, -1.5);
            vecMap[glm::vec3(1.5, -1.5 ,-0.5)] = glm::vec3(-0.5, -1.5, -1.5);
            vecMap[glm::vec3(1.5, -1.5 ,-1.5)] = glm::vec3(-1.5, -1.5, -1.5);

            vecMap[glm::vec3(0.5, -1.5 ,1.5)] = glm::vec3(1.5, -1.5, -0.5);
            vecMap[glm::vec3(0.5, -1.5 ,0.5)] = glm::vec3(0.5, -1.5, -0.5);
            vecMap[glm::vec3(0.5, -1.5 ,-0.5)] = glm::vec3(-0.5, -1.5, -0.5);
            vecMap[glm::vec3(0.5, -1.5 ,-1.5)] = glm::vec3(-1.5, -1.5, -0.5);

            vecMap[glm::vec3(-0.5, -1.5 ,1.5)] = glm::vec3(1.5, -1.5, 0.5);
            vecMap[glm::vec3(-0.5, -1.5 ,0.5)] = glm::vec3(0.5, -1.5, 0.5);
            vecMap[glm::vec3(-0.5, -1.5 ,-0.5)] = glm::vec3(-0.5, -1.5, 0.5);
            vecMap[glm::vec3(-0.5, -1.5 ,-1.5)] = glm::vec3(-1.5, -1.5, 0.5);

            vecMap[glm::vec3(-1.5, -1.5 ,1.5)] = glm::vec3(1.5, -1.5, 1.5);
            vecMap[glm::vec3(-1.5, -1.5 ,0.5)] = glm::vec3(0.5, -1.5, 1.5);
            vecMap[glm::vec3(-1.5, -1.5 ,-0.5)] = glm::vec3(-0.5, -1.5, 1.5);
            vecMap[glm::vec3(-1.5, -1.5 ,-1.5)] = glm::vec3(-1.5, -1.5, 1.5);
        }
        break;    
    case 5:
        if (direction < 0) {
            vecMap[glm::vec3(2, -2 ,2)] = glm::vec3(-2, -2, 2);
            vecMap[glm::vec3(2, -2 ,1)] = glm::vec3(-1, -2, 2);
            vecMap[glm::vec3(2, -2 ,0)] = glm::vec3(0, -2, 2);
            vecMap[glm::vec3(2, -2 ,-1)] = glm::vec3(1, -2, 2);
            vecMap[glm::vec3(2, -2 ,-2)] = glm::vec3(2, -2, 2);

            vecMap[glm::vec3(1, -2 ,2)] = glm::vec3(-2, -2, 1);
            vecMap[glm::vec3(1, -2 ,1)] = glm::vec3(-1, -2, 1);
            vecMap[glm::vec3(1, -2 ,0)] = glm::vec3(0, -2, 1);
            vecMap[glm::vec3(1, -2 ,-1)] = glm::vec3(1, -2, 1);
            vecMap[glm::vec3(1, -2 ,-2)] = glm::vec3(2, -2, 1);

            vecMap[glm::vec3(0, -2 ,2)] = glm::vec3(-2, -2, 0);
            vecMap[glm::vec3(0, -2 ,1)] = glm::vec3(-1, -2, 0);
            vecMap[glm::vec3(0, -2 ,0)] = glm::vec3(0, -2, 0);
            vecMap[glm::vec3(0, -2 ,-1)] = glm::vec3(1, -2, 0);
            vecMap[glm::vec3(0, -2 ,-2)] = glm::vec3(2, -2, 0);

            vecMap[glm::vec3(-1, -2 ,2)] = glm::vec3(-2, -2, -1);
            vecMap[glm::vec3(-1, -2 ,1)] = glm::vec3(-1, -2, -1);
            vecMap[glm::vec3(-1, -2 ,0)] = glm::vec3(0, -2, -1);
            vecMap[glm::vec3(-1, -2 ,-1)] = glm::vec3(1, -2, -1);
            vecMap[glm::vec3(-1, -2 ,-2)] = glm::vec3(2, -2, -1);

            vecMap[glm::vec3(-2, -2 ,2)] = glm::vec3(-2, -2, -2);
            vecMap[glm::vec3(-2, -2 ,1)] = glm::vec3(-1, -2, -2);
            vecMap[glm::vec3(-2, -2 ,0)] = glm::vec3(0, -2, -2);
            vecMap[glm::vec3(-2, -2 ,-1)] = glm::vec3(1, -2, -2);
            vecMap[glm::vec3(-2, -2 ,-2)] = glm::vec3(2, -2, -2);
        }
        else {
            vecMap[glm::vec3(2, -2 ,2)] = glm::vec3(2, -2, -2);
            vecMap[glm::vec3(2, -2 ,1)] = glm::vec3(1, -2, -2);
            vecMap[glm::vec3(2, -2 ,0)] = glm::vec3(0, -2, -2);
            vecMap[glm::vec3(2, -2 ,-1)] = glm::vec3(-1, -2, -2);
            vecMap[glm::vec3(2, -2 ,-2)] = glm::vec3(-2, -2, -2);

            vecMap[glm::vec3(1, -2 ,2)] = glm::vec3(2, -2, -1);
            vecMap[glm::vec3(1, -2 ,1)] = glm::vec3(1, -2, -1);
            vecMap[glm::vec3(1, -2 ,0)] = glm::vec3(0, -2, -1);
            vecMap[glm::vec3(1, -2 ,-1)] = glm::vec3(-1, -2, -1);
            vecMap[glm::vec3(1, -2 ,-2)] = glm::vec3(-2, -2, -1);

            vecMap[glm::vec3(0, -2 ,2)] = glm::vec3(2, -2, 0);
            vecMap[glm::vec3(0, -2 ,1)] = glm::vec3(1, -2, 0);
            vecMap[glm::vec3(0, -2 ,0)] = glm::vec3(0, -2, 0);
            vecMap[glm::vec3(0, -2 ,-1)] = glm::vec3(-1, -2, 0);
            vecMap[glm::vec3(0, -2 ,-2)] = glm::vec3(-2, -2, 0);

            vecMap[glm::vec3(-1, -2 ,2)] = glm::vec3(2, -2, 1);
            vecMap[glm::vec3(-1, -2 ,1)] = glm::vec3(1, -2, 1);
            vecMap[glm::vec3(-1, -2 ,0)] = glm::vec3(0, -2, 1);
            vecMap[glm::vec3(-1, -2 ,-1)] = glm::vec3(-1, -2, 1);
            vecMap[glm::vec3(-1, -2 ,-2)] = glm::vec3(-2, -2, 1);

            vecMap[glm::vec3(-2, -2 ,2)] = glm::vec3(2, -2, 2);
            vecMap[glm::vec3(-2, -2 ,1)] = glm::vec3(1, -2, 2);
            vecMap[glm::vec3(-2, -2 ,0)] = glm::vec3(0, -2, 2);
            vecMap[glm::vec3(-2, -2 ,-1)] = glm::vec3(-1, -2, 2);
            vecMap[glm::vec3(-2, -2 ,-2)] = glm::vec3(-2, -2, 2);
        }
        break;
    }
    

    for (InnerCube* cube : innerCubes) {
        if (cube->GetPosition().y == -distance) {
            glm::vec3 position = cube->GetPosition();
            cube->UpdatePosition(vecMap[position]);
            std::cout << "DownCube index: " << cube->GetIndex() << " | position: " << position.x << " " << position.y << " " << position.z << std::endl;
        }
    }
}




