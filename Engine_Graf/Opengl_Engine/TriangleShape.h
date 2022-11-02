#pragma once

#include "Shape.h"


class TriangleShape : public Shape
{

private:

    float positions[9];
    unsigned int indices[3];

     void  setVertices();
     void  setIndixs();


public:
    
    TriangleShape();



};

