#pragma once

#include "Shape.h"


class RectangleShape : public Shape
{

private:

    float positions[16];

    unsigned int indices[6];

     void  setVertices();
     void  setIndixs();


public:
    
    RectangleShape();



};

