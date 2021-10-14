/*
 * AtomicQueue.hpp
 *
 *  Created on: 3 sept. 2021
 *      Author: Kierann
 */

#ifndef SRC_OSDL_DATA_ATOMIC_ATOMICQUEUE_HPP_
#define SRC_OSDL_DATA_ATOMIC_ATOMICQUEUE_HPP_

#include "../../Types.hpp"

namespace OSDL {
class SinglyLinkedElement;
class Data;
class Mutex;

class AtomicQueue {
public:
	AtomicQueue();

	void push(const OSDL::Data &data);
	OSDL::Data* pop();
	void unPop();

	~AtomicQueue();
private:
	SinglyLinkedElement *firstElement;
	SinglyLinkedElement *lastElement;

	SinglyLinkedElement *poppedElement;
	OSDL::ThreadID poppedElementThread;

	OSDL::Mutex *mutex;
};
}

#endif /* SRC_OSDL_DATA_ATOMIC_ATOMICQUEUE_HPP_ */
