/*
 * Semaphore.hpp
 *
 *  Created on: 8 août 2021
 *      Author: Kierann
 */

#ifndef OSDL_SEMAPHORE
#define OSDL_SEMAPHORE

#include "../Types.hpp"

struct SDL_semaphore;

namespace OSDL {
/**
 *
 */
class Semaphore {
public:
	Semaphore();

	uint32 getValue();
	void increment();
	void wait();

	~Semaphore();
private:
	SDL_semaphore *semaphore;
};
}

#endif /* OSDL_SEMAPHORE */
