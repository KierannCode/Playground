/*
 * Mutex.hpp
 *
 *  Created on: 14 juil. 2021
 *      Author: Kierann
 */

#ifndef SRC_OSDL_THREAD_MUTEX_HPP_
#define SRC_OSDL_THREAD_MUTEX_HPP_

#include "../Types.hpp"

struct SDL_mutex;

namespace OSDL {

/**
 * Implementation of a mutex using SDL primitives.
 *
 * This implementation is the Object Oriented version of SDL_mutex.
 * A mutex shall be used to prevent concurrent access to shared ressources between several threads.
 * The mutex must be locked right before using the ressources, and unlocked right after.
 * This implementation supports recursive locking.
 */
class Mutex {
public:
	/**
	 * Creates a new mutex, unlocked by default.
	 *
	 * @throws OSDL::SDLException if the mutex could not be created by SDL
	 */
	Mutex();

	/**
	 * Locks the mutex.
	 *
	 * When a mutex is locked in a thread, this method will pause any other thread
	 * trying to lock it, until it is unlocked in the thread where it has been locked.
	 * If a mutex is locked several times in a row in the same thread, it must be unlocked the
	 * same amount of times to be available in other threads, this is called recursive locking.
	 *
	 * @see OSDL::Mutex::unlock
	 *
	 * @throws OSDL::SDLException if the mutex could not be locked by SDL
	 *
	 * @exceptsafe If the methods throws an exception, the mutex might be corrupted and
	 * shall not be used anymore.
	 */
	void lock();
	/**
	 * Unlocks the mutex.
	 *
	 * This method must be called when the mutex is locked in order to unlock it.
	 * If the mutex was locked several times in a row in the same thread, it must
	 * be unlocked the same number of times to be available in other threads.
	 * Calling this method when the mutex is not locked results in undefined behavior.
	 *
	 * @see OSDL::Mutex::lock
	 *
	 * @throws OSDL::SDLException if the mutex could not be unlocked by SDL
	 *
	 * @exceptsafe If the methods throws an exception, the mutex might be corrupted and
	 * shall not be used anymore. Can cause undefined behavior.
	 */
	void unlock();

	/**
	 * Destroys the mutex.
	 *
	 * A mutex must always be destroyed in its unlocked state.
	 * Destroying a locked mutex results in undefined behavior.
	 *
	 * @exceptsafe Shall not throw exceptions. Can cause undefined behavior.
	 */
	~Mutex();
private:
	SDL_mutex *mutex;
};
}

#endif /* SRC_OSDL_THREAD_MUTEX_HPP_ */
