/*
 * SDLException.cpp
 *
 *  Created on: 18 juil. 2021
 *      Author: Kierann
 */

#include "SDLException.hpp"

#include <SDL_error.h>

using namespace OSDL;

SDLException::SDLException() {
	this->message += "SDL error : ";
	this->message += std::string(SDL_GetError());
	SDL_ClearError();
}
