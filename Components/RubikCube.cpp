#include "RubikCube.h"
#include <iostream>
#include <map>


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


struct Vec3Comparator {
    bool operator()(const glm::vec3& v1, const glm::vec3& v2) const {
        if (v1.x != v2.x)
            return v1.x < v2.x;
        if (v1.y != v2.y)
            return v1.y < v2.y;
        return v1.z < v2.z;
    }
};

void RubikCube::rotateFront()
{
    std::map<glm::vec3, glm::vec3, Vec3Comparator> vecMap;
    vecMap[glm::vec3(1,-1,1)] = glm::vec3(-1,-1,1);
    vecMap[glm::vec3(1,0,1)] = glm::vec3(0,-1,1);
    vecMap[glm::vec3(1,1,1)] = glm::vec3(1,-1,1);
    vecMap[glm::vec3(0,-1,1)] = glm::vec3(-1,0,1);
    vecMap[glm::vec3(0,0,1)] = glm::vec3(0,0,1);
    vecMap[glm::vec3(0,1,1)] =  glm::vec3(1,0,1);
    vecMap[glm::vec3(-1,-1,1)] = glm::vec3(-1,1,1);
    vecMap[glm::vec3(-1,0,1)] = glm::vec3(0,1,1);
    vecMap[glm::vec3(-1,1,1)] = glm::vec3(1,1,1);

    // Update positions of the cubes on the front side
    for (InnerCube* cube : innerCubes) {
        if (cube->GetPosition().z == 1) {
            glm::vec3 position = cube->GetPosition();
            cube->UpdatePosition(vecMap[position]);
        }
    }
}


