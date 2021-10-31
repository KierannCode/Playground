/*
 * AtomicQueue.cpp
 *
 *  Created on: 3 sept. 2021
 *      Author: Kierann
 */

#include "AtomicQueue.hpp"

#include "../SinglyLinkedElement.hpp"
#include "../Data.hpp"

#include "../../Thread/Mutex.hpp"

#include "../../Resilience/Exception/IllegalCallException/IllegalArgumentException.hpp"
#include "../../Resilience/Exception/IllegalCallException/IllegalCallException.hpp"

#include <SDL_thread.h>

OSDL::AtomicQueue::AtomicQueue() {
	firstElement = nullptr;
	lastElement = nullptr;

	poppedElement = nullptr;
	poppedElementThread = 0;

	mutex = new OSDL::Mutex();
}

void OSDL::AtomicQueue::push(const OSDL::Data &data) {
	mutex->lock();
	if (lastElement != nullptr) {
		lastElement->link(new SinglyLinkedElement(data));
		lastElement = lastElement->getNextElement();
	} else {
		firstElement = new SinglyLinkedElement(data);
		lastElement = firstElement;
	}
	mutex->unlock();
}

OSDL::Data* OSDL::AtomicQueue::pop() {
	OSDL::Data *data = nullptr;
	mutex->lock();
	if (poppedElement != nullptr) {
		delete poppedElement;
	}
	poppedElement = firstElement;
	if (poppedElement != nullptr) {
		firstElement = poppedElement->getNextElement();
		if (firstElement == nullptr) {
			lastElement = nullptr;
		}
		poppedElement->isolate();
		poppedElementThread = SDL_ThreadID();
		data = &(poppedElement->getData());
	}
	mutex->unlock();
	return data;
}

void OSDL::AtomicQueue::unPop() {
	mutex->lock();
	if (poppedElement == nullptr) {
		mutex->unlock();
		throw OSDL::IllegalCallException(
				"Method 'unPop' must be called after calling method 'pop' first");
	}
	if (SDL_ThreadID() != poppedElementThread) {
		mutex->unlock();
		throw OSDL::IllegalCallException(
				"Method 'unPop' must be called in the same thread calling method 'pop'");
	}
	poppedElement->link(firstElement);
	firstElement = poppedElement;
	if (lastElement == nullptr) {
		lastElement = firstElement;
	}
	poppedElement = nullptr;
	poppedElementThread = 0;
	mutex->unlock();
}

OSDL::AtomicQueue::~AtomicQueue() {
	delete mutex;

	if (poppedElement != nullptr) {
		delete poppedElement;
	}

	poppedElement = firstElement;
	while (poppedElement != nullptr) {
		firstElement = poppedElement->getNextElement();
		delete poppedElement;
		poppedElement = firstElement;
	}
}
