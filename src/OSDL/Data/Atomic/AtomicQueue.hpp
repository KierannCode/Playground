/*
 * AtomicQueue.hpp
 *
 *  Created on: 3 sept. 2021
 *      Author: Kierann
 */

#ifndef OSDL_ATOMICQUEUE
#define OSDL_ATOMICQUEUE

#include "../../Types.hpp"

namespace OSDL {
class SingleLinkElement;
class Data;
class Mutex;

/**
 * @brief Thread-safe polymorph queue
 *
 * @details A thread-safe implementation of a polymorph queue with staged popping : \n
 * This is a FIFO structure you can push elements into and pop elements off.\n
 * Consecutive pops empty the queue, starting with the first pushed elements.\n
 * The last element popped can be restored at the beginning of the queue.\n
 * This strucutre is thread-safe, meaning that most of its methods can be called
 * simultaneously in any thread.
 */
class AtomicQueue {
public:
	/**
	 * @brief Default constructor
	 *
	 * @details Initializes the queue, empty by default.
	 */
	AtomicQueue();

	/**
	 * @brief Pushes data at the end of the queue
	 *
	 * @details Creates a copy of the pushed data and puts it at the end of the queue.\n
	 * This method is thread-safe and can be called safely in any thread.
	 *
	 * @param data The data pushed into the queue
	 */
	void push(const OSDL::Data &data);
	/**
	 * @brief Pops data at the beginning of the queue
	 *
	 * @details Removes and returns the data at the beginning of the queue.\n
	 * The last popped element is temporarily saved and can be pushed back at the beginning
	 * of the queue using 'unPop'.\n
	 * Only the last popped element is saved, calling this method multiple times effectively
	 * empties the queue.
	 * This method is thread-safe and can be called safely in any thread.
	 *
	 * @return The data at the beginning of the queue
	 *
	 * @see OSDL::AtomicQueue::unPop
	 */
	OSDL::Data* pop();
	/**
	 * @brief Restores the last popped element
	 *
	 * @details Restores the last popped element at the beginning of the queue.\n
	 * This method is not thread-safe and must be called in the same thread that called 'pop'
	 * for the last time.
	 * Calling this method when no element was popped will throw an exception.
	 *
	 * @see OSDL::AtomicQueue::pop
	 *
	 * @throw OSDL::IllegalCallException if there was no popped element saved.
	 *
	 * @throw OSDL::IllegalCallException if it is not called in the same thread which called
	 * 'pop' last.
	 */
	void unPop();

	/**
	 * @brief Destructor
	 *
	 * @details Empties and destroys the queue.\n
	 * This method is not thread safe : destroying the object while using it in another thread
	 * will result in undefined behavior.
	 */
	~AtomicQueue();
private:
	SingleLinkElement *firstElement;
	SingleLinkElement *lastElement;

	SingleLinkElement *poppedElement;
	OSDL::ThreadID poppedElementThread;

	OSDL::Mutex *mutex;
};
}

#endif /* OSDL_ATOMICQUEUE */
