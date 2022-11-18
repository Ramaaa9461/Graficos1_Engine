#pragma once

#include "DDLExport.h"

static class Input
{

private:


	static Input* s_instance;
protected:

	DllExport virtual bool IsKeyPressedImpl(int keycode) = 0;

public:

	DllExport inline static bool getKeyPressed(int keycode) { return s_instance->IsKeyPressedImpl(keycode);  };
	

};

