#pragma once

#include "Shape.h"

class Sprite : public Shape
{


private:

    	float positions[16]; 

        unsigned int indices[6];


    void  setVerticesSingleImage();
    void setVerticesSpriteSheet();
    void  setIndixs();


public:

    Sprite(std::string imageName, bool singleImage);




};

