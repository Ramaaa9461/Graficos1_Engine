#pragma once

#include "Shape.h"


class RectangleShape : public Shape
{

private:

    float positions[8];
    unsigned int indices[6];

     void  setVertices();
     void  setIndixs();
     void calculateVertices();

public:
    
    RectangleShape(glm::vec4 RGBA);



};

