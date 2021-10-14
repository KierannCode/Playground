/*
 * Mutex.hpp
 *
 *  Created on: 14 juil. 2021
 *      Author: Kierann
 */

#ifndef SRC_OSDL_THREAD_MUTEX_HPP_
#define SRC_OSDL_THREAD_MUTEX_HPP_

struct SDL_mutex;

namespace OSDL {
class Mutex {
public:
	Mutex();

	void lock();
	void unlock();

	~Mutex();
private:
	SDL_mutex *mutex;
};
}

#endif /* SRC_OSDL_THREAD_MUTEX_HPP_ */
