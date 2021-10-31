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
 * @brief Implementation of a mutex using SDL primitives.
 *
 * @details This implementation is the Object Oriented version of SDL_mutex.\n
 * A mutex shall be used to prevent concurrent access to shared ressources between threads.\n
 * A mutex must be locked right before using the ressources, and unlocked right after.\n
 * This implementation supports recursive locking.
 */
class Mutex {
public:
	/**
	 * @brief Creates a new mutex, unlocked by default.
	 *
	 * @throw OSDL::SDLException if the mutex could not be created by SDL.
	 */
	Mutex();

	/**
	 * @brief Locks the mutex.
	 *
	 * @details When a mutex is locked in a thread, this method will pause any other thread
	 * trying to lock it until it is unlocked in the thread where it has been locked.\n
	 * If a mutex is locked several times in a row in the same thread, it must be unlocked the
	 * same amount of times to be available in other threads (recursive locking).
	 *
	 * @see OSDL::Mutex::unlock
	 *
	 * @throw OSDL::SDLException if the mutex could not be locked by SDL.
	 */
	void lock();
	/**
	 * @brief Unlocks the mutex.
	 *
	 * @details This method must be called when the mutex is locked in order to unlock it.\n
	 * If the mutex was locked several times in a row in the same thread, it must
	 * be unlocked the same number of times to be available in other threads (recursive locking).\n
	 * Calling this method when the mutex is not locked results in undefined behavior.
	 *
	 * @see OSDL::Mutex::lock
	 *
	 * @throw OSDL::SDLException if the mutex could not be unlocked by SDL.
	 */
	void unlock();

	/**
	 * @brief Destroys the mutex.
	 *
	 * @details A mutex must always be destroyed in its unlocked state.\n
	 * Destroying a locked mutex results in undefined behavior.
	 */
	~Mutex();
private:
	SDL_mutex *mutex;
};
}

#endif /* SRC_OSDL_THREAD_MUTEX_HPP_ */
