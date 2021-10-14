/*
 * System.cpp
 *
 *  Created on: 12 sept. 2021
 *      Author: Kierann
 */

#include "System.hpp"

#include <SDL.h>

void OSDL::System::initialize() {
	SDL_Init(SDL_INIT_EVERYTHING);
	SDL_StopTextInput();
	SDL_SetHint(SDL_HINT_WINDOWS_NO_CLOSE_ON_ALT_F4, "1");
}
void OSDL::System::quit() {
	SDL_Quit();
}
