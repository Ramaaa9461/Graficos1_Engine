#pragma once

struct UVCoords 
{
	float u, v;
};


class Frame
{


public:

	Frame();
	~Frame();

	UVCoords uvCoords[4];
};

