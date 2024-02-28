#include <glm/glm.hpp>

class InnerCube
{
    private:
        glm::vec3 position;
        int index;
    
    public:
        InnerCube();
        InnerCube(glm::vec3 position, int index);
        glm::vec3 GetPosition();
        int GetIndex();
        void UpdatePosition(glm::vec3 position);
        void SetIndex(int index);
        ~InnerCube();

}
;