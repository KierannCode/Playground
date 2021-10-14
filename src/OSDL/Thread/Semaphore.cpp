/*
 * Semaphore.cpp
 *
 *  Created on: 8 août 2021
 *      Author: Kierann
 */

#include "Semaphore.hpp"

#include "../Resilience/Exception/SDLException.hpp"

#include <SDL_mutex.h>

OSDL::Semaphore::Semaphore() {
	semaphore = SDL_CreateSemaphore(0);
	if (semaphore == nullptr) {
		throw OSDL::SDLException();
	}
}

uint32 OSDL::Semaphore::getValue() {
	return SDL_SemValue(semaphore);
}

void OSDL::Semaphore::increment() {
	if (SDL_SemPost(semaphore) == -1) {
		throw OSDL::SDLException();
	}
}

void OSDL::Semaphore::wait() {
	if (SDL_SemWait(semaphore) != 0) {
		throw OSDL::SDLException();
	}
}

OSDL::Semaphore::~Semaphore() {
	SDL_DestroySemaphore(semaphore);
}
