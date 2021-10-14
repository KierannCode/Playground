/*
 * Mutex.cpp
 *
 *  Created on: 14 juil. 2021
 *      Author: Kierann
 */

#include "../../OSDL/Thread/Mutex.hpp"

#include "../../OSDL/Resilience/Exception/SDLException.hpp"

#include <SDL_mutex.h>

OSDL::Mutex::Mutex() {
	mutex = SDL_CreateMutex();
	if (mutex == nullptr) {
		throw SDLException();
	}
}

void OSDL::Mutex::lock() {
	if (SDL_LockMutex(mutex) == -1) {
		throw SDLException();
	}
}
void OSDL::Mutex::unlock() {
	if (SDL_UnlockMutex(mutex) == -1) {
		throw SDLException();
	}
}

OSDL::Mutex::~Mutex() {
	SDL_DestroyMutex(mutex);
}
