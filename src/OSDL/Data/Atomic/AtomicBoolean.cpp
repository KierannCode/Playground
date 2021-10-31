/*
 * AtomicBoolean.cpp
 *
 *  Created on: 23 sept. 2021
 *      Author: Kierann
 */

#include "AtomicBoolean.hpp"

#include "../../Thread/Mutex.hpp"

OSDL::AtomicBoolean::AtomicBoolean() {
	value = false;
	mutex = new OSDL::Mutex;
}

OSDL::AtomicBoolean::AtomicBoolean(bool value) {
	this->value = value;
	mutex = new OSDL::Mutex;
}

bool OSDL::AtomicBoolean::getValue() const {
	mutex->lock();
	bool value = this->value;
	mutex->unlock();
	return value;
}
void OSDL::AtomicBoolean::setValue(bool value) {
	mutex->lock();
	this->value = value;
	mutex->unlock();
}

OSDL::AtomicBoolean::~AtomicBoolean() {
	delete mutex;
}
