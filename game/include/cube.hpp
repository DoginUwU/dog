#include "object.hpp"

class Cube : public Dog::Object
{
public:
    Cube();
    ~Cube();

    void start();
    void update();
};