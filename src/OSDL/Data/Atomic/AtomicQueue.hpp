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

class AtomicQueue {
public:
	AtomicQueue();

	void push(const OSDL::Data &data);
	OSDL::Data* pop();
	void unPop();

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
