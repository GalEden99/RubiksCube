#include <vector>
#include "InnerCube.h"
#include <map>



class RubikCube {
    private:
        std::vector<InnerCube *> innerCubes;
        int size;
        float distance;

    public:
        RubikCube(int size, float distance);
        void AddInnerCube(InnerCube* innerCube);
        void UpdateInnerCubePosition(int index, glm::vec3 position);
        InnerCube* GetInnerCube(int index);
        std::vector<InnerCube *> GetInnerCubes();
        void rotateFront(int direction);
        void rotateBack(int direction);
        void rotateLeft(int direction);
        void rotateRight(int direction);
        void rotateUp(int direction);
        void rotateDown(int direction);



        struct Vec3Comparator {
        bool operator()(const glm::vec3& v1, const glm::vec3& v2) const {
            if (v1.x != v2.x)
                return v1.x < v2.x;
            if (v1.y != v2.y)
                return v1.y < v2.y;
            return v1.z < v2.z;
              }
        };

        std::map<glm::vec3, glm::vec3,Vec3Comparator> getFrontRotation(int direction);


        void printCubes();
        ~RubikCube();
};