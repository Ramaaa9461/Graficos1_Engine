#ifndef  INPUT_H
#define INPUT_H

#include "Window.h"

namespace FACU_RAMI_ENGINE
{
	class Input
	{
	private:
		Window* window;
	public:

		Input(Window* window);
		~Input();

		void SetWindowsShouldClose(bool windowsIsOpen);
		
		bool GetKey(int key);
	};
};

#endif