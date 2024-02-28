#include <iostream>
#include "InnerCube.h"

InnerCube::InnerCube()
{
    position = glm::vec3(0, 0, 0);
    index = 0;
}

InnerCube::InnerCube(glm::vec3 position, int index)
{
    this->position = position;
    this->index = index;
}

glm::vec3 InnerCube::GetPosition()
{
    return position;
}

int InnerCube::GetIndex()
{
    return index;
}

void InnerCube::UpdatePosition(glm::vec3 position)
{
    this->position = position;
}

void InnerCube::SetIndex(int index)
{
    this->index = index;
}

InnerCube::~InnerCube()
{
    std::cout << "InnerCube destructor called" << std::endl;
}