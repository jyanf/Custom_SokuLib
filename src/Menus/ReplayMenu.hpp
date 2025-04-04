//
// Created by DPhoenix on 04/04/2025.
//

#ifndef SOKULIB_REPLAYMENU_HPP
#define SOKULIB_REPLAYMENU_HPP

#include "../Sprite.hpp"
#include "../Font.hpp"
#include "../Design.hpp"
#include "ProfileDeckEdit.hpp"
#include "../Menus.hpp"

namespace SokuLib
{
	struct MenuReplay {
		void** vtable;
		char state;
		char unknown004[3]; // padding?
		
		// 0x008
		SWRFont font;
		// 0x19C
		char unknown19C[4];
		Sprite unknown1A0;
		char unknown234[4];
		Sprite unknown238;

		// 0x2CC
		CReplayList replayList;
		// padding 0x03
		// 0x380
		CDesign layout;

		// 0x3B4
		CDesign::Object* layoutSprites[3];
		MenuCursor cursors[2];

		// 0x3E8
		Guide guides[2];

		// 0x538
		char unknown538[0x0C]; // some List
	};

	static_assert(sizeof(SokuLib::MenuReplay) == 0x544);
}


#endif //SOKULIB_REPLAYMENU_HPP
