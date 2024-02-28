#include <vector>
#include "InnerCube.h"


class RubikCube {
    private:
        std::vector<InnerCube *> innerCubes;

    public:
        RubikCube();
        void AddInnerCube(InnerCube* innerCube);
        void UpdateInnerCubePosition(int index, glm::vec3 position);
        InnerCube* GetInnerCube(int index);
        std::vector<InnerCube *> GetInnerCubes();

        void printCubes();
        ~RubikCube();
};