#pragma once

#include "Shape.h"


class RectangleShape : public Shape
{

private:


    int width, height;
    float positions[8];
    unsigned int indices[6];

     void  setVertices();
     void  setIndixs();
     void calculateVertices();

public:
    
    RectangleShape();

    void setColor(glm::vec4 RGBA);

};

