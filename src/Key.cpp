//
// Created by PinkySmile on 02/12/2020.
//

#include "SokuAddresses.hpp"
#include "Key.hpp"

#include "UnionCast.hpp"

namespace SokuLib
{
	//g_keyDownListener.checkPress()
	bool (* const checkKeyOneshot)(unsigned char, bool, bool, bool) = reinterpret_cast<bool (*)(unsigned char, bool, bool, bool)>(ADDR_CHECK_KEY_ONESHOT);

	KeyDownListener& g_keyDownListener = *reinterpret_cast<KeyDownListener*>(0x8998d8);

	void KeyDownListener::clear() {
		return (this->*union_cast<void(KeyDownListener::*)()>(0x40a910))();
	}
	void KeyDownListener::refresh() {
		return (this->*union_cast<void(KeyDownListener::*)()>(0x40a950))();
	}
	bool KeyDownListener::checkPress(unsigned char keyCode, bool shift, bool alt, bool ctrl) {
		return (this->*union_cast<bool(KeyDownListener::*)(unsigned char, bool, bool, bool)>(0x40aa60))(keyCode, shift, alt, ctrl);
	}
	void KeyDownListener::setCounter(unsigned char keyCode, unsigned char value) {
		return (this->*union_cast<void(KeyDownListener::*)(unsigned char, unsigned char)>(0x40aab0))(keyCode, value);
	}
	void KeyDownListener::enableListen(unsigned char keyCode) {
		return (this->*union_cast<void(KeyDownListener::*)(unsigned char)>(0x40aac0))(keyCode);
	}
}