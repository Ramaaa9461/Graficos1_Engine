#pragma once

#include "DDLExport.h"

static class Input
{

private:


protected:

	DllExport virtual bool IsKeyPressedImpl(int keycode) = 0;

public:

	static Input* s_instance;
	DllExport inline static bool getKeyPressed(int keycode) { return s_instance->IsKeyPressedImpl(keycode);  };
	

};

