/*
 * Timer.cpp
 *
 *  Created on: 7 août 2021
 *      Author: Kierann
 */

#include "Timer.hpp"

#include <SDL_timer.h>

OSDL::Time OSDL::Timer::getTicks() {
	return SDL_GetTicks();
}

void OSDL::Timer::delay(Time milliseconds) {
	SDL_Delay(milliseconds);
}
