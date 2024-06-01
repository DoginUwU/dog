#include <string>
#include <glm/glm.hpp>

namespace Dog
{
    class Shader
    {
    public:
        uint program;
        uint modelLoc;
        uint viewLoc;
        uint projectionLoc;

        Shader(const std::string& vertexPath, const std::string& fragmentPath);
        ~Shader();

        void use() const;

        void setMat4(uint loc, const glm::mat4 &mat) const;
        void setVec3(uint loc, const glm::vec3 &vec) const;

    private:
        uint loadShader(std::string path, uint type);
    };
}
