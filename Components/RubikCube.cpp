#include "RubikCube.h"
#include <iostream>


RubikCube::RubikCube()
{
    innerCubes = std::vector<InnerCube *>();
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
        std::cout << "Cube " << i << " position: " << innerCubes[i]->GetPosition().x << " " << innerCubes[i]->GetPosition().y << " " << innerCubes[i]->GetPosition().z << "index: " << innerCubes[i]->GetIndex() <<std::endl;
    }
}

std::vector<InnerCube *> RubikCube::GetInnerCubes()
{
    return innerCubes;
}




void RubikCube::rotateFront(int direction) {
std::map<glm::vec3, glm::vec3, RubikCube::Vec3Comparator> vecMap;
    if (direction < 0) {
    vecMap[glm::vec3(1,-1,1)] = glm::vec3(-1,-1,1);
    vecMap[glm::vec3(1,0,1)] = glm::vec3(0,-1,1);
    vecMap[glm::vec3(1,1,1)] = glm::vec3(1,-1,1);
    vecMap[glm::vec3(0,-1,1)] = glm::vec3(-1,0,1);
    vecMap[glm::vec3(0,0,1)] = glm::vec3(0,0,1);
    vecMap[glm::vec3(0,1,1)] =  glm::vec3(1,0,1);
    vecMap[glm::vec3(-1,-1,1)] = glm::vec3(-1,1,1);
    vecMap[glm::vec3(-1,0,1)] = glm::vec3(0,1,1);
    vecMap[glm::vec3(-1,1,1)] = glm::vec3(1,1,1);
    }
    else {
    vecMap[glm::vec3(1,-1,1)] = glm::vec3(1,1,1);
    vecMap[glm::vec3(1,0,1)] = glm::vec3(0,1,1);
    vecMap[glm::vec3(1,1,1)] = glm::vec3(-1,1,1);
    vecMap[glm::vec3(0,-1,1)] = glm::vec3(1,0,1);
    vecMap[glm::vec3(0,0,1)] = glm::vec3(0,0,1);
    vecMap[glm::vec3(0,1,1)] =  glm::vec3(-1,0,1);
    vecMap[glm::vec3(-1,-1,1)] = glm::vec3(1,-1,1);
    vecMap[glm::vec3(-1,0,1)] = glm::vec3(0,-1,1);
    vecMap[glm::vec3(-1,1,1)] = glm::vec3(-1,-1,1);
    }
    std::cout << "Did front rotation to the " << direction << std::endl;

    for (InnerCube* cube : innerCubes) {
        if (cube->GetPosition().z == 1) {
            glm::vec3 position = cube->GetPosition();
            cube->UpdatePosition(vecMap[position]);
        }
    }
}

void RubikCube::rotateBack(int direction) {
std::map<glm::vec3, glm::vec3, RubikCube::Vec3Comparator> vecMap;
    if (direction < 0) {
    vecMap[glm::vec3(1,-1,-1)] = glm::vec3(-1,-1,-1);
    vecMap[glm::vec3(1,0,-1)] = glm::vec3(0,-1,-1);
    vecMap[glm::vec3(1,1,-1)] = glm::vec3(1,-1,-1);
    vecMap[glm::vec3(0,-1,-1)] = glm::vec3(-1,0,-1);
    vecMap[glm::vec3(0,0,-1)] = glm::vec3(0,0,-1);
    vecMap[glm::vec3(0,1,-1)] =  glm::vec3(1,0,-1);
    vecMap[glm::vec3(-1,-1,-1)] = glm::vec3(-1,1,-1);
    vecMap[glm::vec3(-1,0,-1)] = glm::vec3(0,1,-1);
    vecMap[glm::vec3(-1,1,-1)] = glm::vec3(1,1,-1);
    }
    else {
    vecMap[glm::vec3(1,-1,-1)] = glm::vec3(1,1,-1);
    vecMap[glm::vec3(1,0,-1)] = glm::vec3(0,1,-1);
    vecMap[glm::vec3(1,1,-1)] = glm::vec3(-1,1,-1);
    vecMap[glm::vec3(0,-1,-1)] = glm::vec3(1,0,-1);
    vecMap[glm::vec3(0,0,-1)] = glm::vec3(0,0,-1);
    vecMap[glm::vec3(0,1,-1)] =  glm::vec3(-1,0,-1);
    vecMap[glm::vec3(-1,-1,-1)] = glm::vec3(1,-1,-1);
    vecMap[glm::vec3(-1,0,-1)] = glm::vec3(0,-1,-1);
    vecMap[glm::vec3(-1,1,-1)] = glm::vec3(-1,-1,-1);
    }

    std::cout << "Did back rotation to the " << direction << std::endl;


    // Update positions of the cubes on the front side
    for (InnerCube* cube : innerCubes) {
        if (cube->GetPosition().z == -1) {
            glm::vec3 position = cube->GetPosition();
            cube->UpdatePosition(vecMap[position]);
        }
    }
}

void RubikCube::rotateLeft(int direction) {
std::map<glm::vec3, glm::vec3, RubikCube::Vec3Comparator> vecMap;
if (direction < 0) {
    vecMap[glm::vec3(-1,-1,-1)] = glm::vec3(-1,-1,1);
    vecMap[glm::vec3(-1,0,-1)] = glm::vec3(-1,-1,0);
    vecMap[glm::vec3(-1,1,-1)] = glm::vec3(-1,-1,-1);
    vecMap[glm::vec3(-1,-1,0)] = glm::vec3(-1,0,1);
    vecMap[glm::vec3(-1,0,0)] = glm::vec3(-1,0,0);
    vecMap[glm::vec3(-1,1,0)] =  glm::vec3(-1,0,-1);
    vecMap[glm::vec3(-1,-1,1)] = glm::vec3(-1,1,1);
    vecMap[glm::vec3(-1,0,1)] = glm::vec3(-1,1,0);
    vecMap[glm::vec3(-1,1,1)] = glm::vec3(-1,1,-1);
    }
    else {
    vecMap[glm::vec3(-1,-1,-1)] = glm::vec3(-1,1,-1);
    vecMap[glm::vec3(-1,0,-1)] = glm::vec3(-1,1,0);
    vecMap[glm::vec3(-1,1,-1)] = glm::vec3(-1,1,1);
    vecMap[glm::vec3(-1,-1,0)] = glm::vec3(-1,0,-1);
    vecMap[glm::vec3(-1,0,0)] = glm::vec3(-1,0,0);
    vecMap[glm::vec3(-1,1,0)] =  glm::vec3(-1,0,1);
    vecMap[glm::vec3(-1,-1,1)] = glm::vec3(-1,-1,-1);
    vecMap[glm::vec3(-1,0,1)] = glm::vec3(-1,-1,0);
    vecMap[glm::vec3(-1,1,1)] = glm::vec3(-1,-1,1);
    }

    std::cout << "Did back rotation to the " << direction << std::endl;


    for (InnerCube* cube : innerCubes) {
        if (cube->GetPosition().x == -1) {
            glm::vec3 position = cube->GetPosition();
            cube->UpdatePosition(vecMap[position]);
        }
    }
}

void RubikCube::rotateRight(int direction) {
std::map<glm::vec3, glm::vec3, RubikCube::Vec3Comparator> vecMap;
if (direction < 0) {
    vecMap[glm::vec3(1,-1,-1)] = glm::vec3(1,-1,1);
    vecMap[glm::vec3(1,0,-1)] = glm::vec3(1,-1,0);
    vecMap[glm::vec3(1,1,-1)] = glm::vec3(1,-1,-1);
    vecMap[glm::vec3(1,-1,0)] = glm::vec3(1,0,1);
    vecMap[glm::vec3(1,0,0)] = glm::vec3(1,0,0);
    vecMap[glm::vec3(1,1,0)] =  glm::vec3(1,0,-1);
    vecMap[glm::vec3(1,-1,1)] = glm::vec3(1,1,1);
    vecMap[glm::vec3(1,0,1)] = glm::vec3(1,1,0);
    vecMap[glm::vec3(1,1,1)] = glm::vec3(1,1,-1);
    }
    else {
    vecMap[glm::vec3(1,-1,-1)] = glm::vec3(1,1,-1);
    vecMap[glm::vec3(1,0,-1)] = glm::vec3(1,1,0);
    vecMap[glm::vec3(1,1,-1)] = glm::vec3(1,1,1);
    vecMap[glm::vec3(1,-1,0)] = glm::vec3(1,0,-1);
    vecMap[glm::vec3(1,0,0)] = glm::vec3(1,0,0);
    vecMap[glm::vec3(1,1,0)] =  glm::vec3(1,0,1);
    vecMap[glm::vec3(1,-1,1)] = glm::vec3(1,-1,-1);
    vecMap[glm::vec3(1,0,1)] = glm::vec3(1,-1,0);
    vecMap[glm::vec3(1,1,1)] = glm::vec3(1,-1,1);
    }

    std::cout << "Did right rotation to the " << direction << std::endl;


    for (InnerCube* cube : innerCubes) {
        if (cube->GetPosition().x == 1) {
            glm::vec3 position = cube->GetPosition();
            cube->UpdatePosition(vecMap[position]);
        }
    }
}

void RubikCube::rotateUp(int direction) {
std::map<glm::vec3, glm::vec3, RubikCube::Vec3Comparator> vecMap;
if (direction < 0) {
    vecMap[glm::vec3(-1,1,-1)] = glm::vec3(1,1,-1);
    vecMap[glm::vec3(0,1,-1)] = glm::vec3(1,1,0);
    vecMap[glm::vec3(1,1,-1)] = glm::vec3(1,1,1);
    vecMap[glm::vec3(-1,1,0)] = glm::vec3(0,1,-1);
    vecMap[glm::vec3(0,1,0)] = glm::vec3(0,1,0);
    vecMap[glm::vec3(1,1,0)] =  glm::vec3(0,1,1);
    vecMap[glm::vec3(-1,1,1)] = glm::vec3(-1,1,-1);
    vecMap[glm::vec3(0,1,1)] = glm::vec3(-1,1,0);
    vecMap[glm::vec3(1,1,1)] = glm::vec3(-1,1,1);
    }
    else {
    vecMap[glm::vec3(-1,1,-1)] = glm::vec3(-1,1,1);
    vecMap[glm::vec3(0,1,-1)] = glm::vec3(-1,1,0);
    vecMap[glm::vec3(1,1,-1)] = glm::vec3(-1,1,-1);
    vecMap[glm::vec3(-1,1,0)] = glm::vec3(0,1,1);
    vecMap[glm::vec3(0,1,0)] = glm::vec3(0,1,0);
    vecMap[glm::vec3(1,1,0)] =  glm::vec3(0,1,-1);
    vecMap[glm::vec3(-1,1,1)] = glm::vec3(1,1,1);
    vecMap[glm::vec3(0,1,1)] = glm::vec3(1,1,0);
    vecMap[glm::vec3(1,1,1)] = glm::vec3(1,1,-1);    
    }
    for (InnerCube* cube : innerCubes) {
        if (cube->GetPosition().y == 1) {
            glm::vec3 position = cube->GetPosition();
            cube->UpdatePosition(vecMap[position]);
        }
    }
}


void RubikCube::rotateDown(int direction) {
std::map<glm::vec3, glm::vec3, RubikCube::Vec3Comparator> vecMap;
if (direction < 0) {
    vecMap[glm::vec3(-1,-1,-1)] = glm::vec3(1,-1,-1);
    vecMap[glm::vec3(0,-1,-1)] = glm::vec3(1,-1,0);
    vecMap[glm::vec3(1,-1,-1)] = glm::vec3(1,-1,1);
    vecMap[glm::vec3(-1,-1,0)] = glm::vec3(0,-1,-1);
    vecMap[glm::vec3(0,-1,0)] = glm::vec3(0,-1,0);
    vecMap[glm::vec3(1,-1,0)] =  glm::vec3(0,-1,1);
    vecMap[glm::vec3(-1,-1,1)] = glm::vec3(-1,-1,-1);
    vecMap[glm::vec3(0,-1,1)] = glm::vec3(-1,-1,0);
    vecMap[glm::vec3(1,-1,1)] = glm::vec3(-1,-1,1);
    }
    else {
    vecMap[glm::vec3(-1,-1,-1)] = glm::vec3(-1,-1,1);
    vecMap[glm::vec3(0,-1,-1)] = glm::vec3(-1,-1,0);
    vecMap[glm::vec3(1,-1,-1)] = glm::vec3(-1,-1,-1);
    vecMap[glm::vec3(-1,-1,0)] = glm::vec3(0,-1,1);
    vecMap[glm::vec3(0,-1,0)] = glm::vec3(0,-1,0);
    vecMap[glm::vec3(1,-1,0)] =  glm::vec3(0,-1,-1);
    vecMap[glm::vec3(-1,-1,1)] = glm::vec3(1,-1,1);
    vecMap[glm::vec3(0,-1,1)] = glm::vec3(1,-1,0);
    vecMap[glm::vec3(1,-1,1)] = glm::vec3(1,-1,-1);    
    }
    for (InnerCube* cube : innerCubes) {
        if (cube->GetPosition().y == -1) {
            glm::vec3 position = cube->GetPosition();
            cube->UpdatePosition(vecMap[position]);
        }
    }
}




