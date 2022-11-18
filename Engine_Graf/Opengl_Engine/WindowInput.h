#pragma once


#include "Input.h"

class WindowInput : public Input
{
private:

protected:
	virtual bool IsKeyPressedImpl(int keycode) override;

public:


};

