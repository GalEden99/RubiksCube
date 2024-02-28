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
