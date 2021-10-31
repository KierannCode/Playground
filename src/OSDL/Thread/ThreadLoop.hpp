/*
 * ThreadLoop.hpp
 *
 *  Created on: 29 juil. 2021
 *      Author: Kierann
 */

#ifndef OSDL_THREADLOOP
#define OSDL_THREADLOOP

#include "../Types.hpp"

struct SDL_Thread;

namespace OSDL {
class AtomicBoolean;
class Semaphore;

class ThreadLoop {
public:
	void start();
	void iterate();
	void stop();

	virtual ~ThreadLoop();
private:
	SDL_Thread *thread;

	OSDL::AtomicBoolean *running;
	OSDL::Semaphore *startIteration;

	friend int threadMethod(void *data);

	virtual void initialize();
	virtual void loopCode();
	virtual void quit();
};
}

#endif /* OSDL_THREADLOOP */
