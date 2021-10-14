/*
 * Semaphore.hpp
 *
 *  Created on: 8 août 2021
 *      Author: Kierann
 */

#ifndef SRC_OSDL_THREAD_SEMAPHORE_HPP_
#define SRC_OSDL_THREAD_SEMAPHORE_HPP_

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

#endif /* SRC_OSDL_THREAD_SEMAPHORE_HPP_ */
