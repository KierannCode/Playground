/*
 * Math.cpp
 *
 *  Created on: 22 sept. 2021
 *      Author: Kierann
 */

#include "Math.hpp"

#include <SDL_stdinc.h>

float OSDL::Math::min(float a, float b) {
	return SDL_min(a, b);
}
float OSDL::Math::max(float a, float b) {
	return SDL_max(a, b);
}

int OSDL::Math::floor(float x) {
	return SDL_floorf(x);
}

int OSDL::Math::ceil(float x) {
	return SDL_ceilf(x);
}
