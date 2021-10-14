/*
 * ThreadLoop.hpp
 *
 *  Created on: 29 juil. 2021
 *      Author: Kierann
 */

#ifndef SRC_OSDL_THREAD_THREADLOOP_HPP_
#define SRC_OSDL_THREAD_THREADLOOP_HPP_

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

#endif /* SRC_OSDL_THREAD_THREADLOOP_HPP_ */
