//
// Created by PinkySmile on 04/11/2020.
//

#ifndef SOKULIB_KEY_HPP
#define SOKULIB_KEY_HPP

#include "Vector.hpp"

namespace SokuLib
{
	struct KeyDownListener {
		int count[256]; // counter for DIK keydown
		Vector<unsigned char> enabledKeys; // enlisted keydown
		bool shift;// true if L/R shift is keydown
		bool alt;
		bool ctrl;

		void clear();
		void refresh();
		bool checkPress(unsigned char keyCode, bool shift, bool alt, bool ctrl);
		void setCounter(unsigned char keyCode, unsigned char value);
		
		void enableListen(unsigned char keyCode);
		
	};

	extern KeyDownListener &g_keyDownListener;

	extern bool (* const checkKeyOneshot)(unsigned char, bool, bool, bool);
}


#endif //SOKULIB_KEY_HPP
