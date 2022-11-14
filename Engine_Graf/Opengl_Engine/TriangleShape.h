#pragma once

#include "Shape.h"


class TriangleShape : public Shape
{

private:

    float positions[6];
    unsigned int indices[3];

     void  setVertices();
     void  setIndixs();


public:
    
    TriangleShape(glm::vec4 RGBA, int initPositionX, int initPositionY);



};

