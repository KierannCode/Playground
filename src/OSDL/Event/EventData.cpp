/*
 * EventData.cpp
 *
 *  Created on: 7 août 2021
 *      Author: Kierann
 */

#include "EventData.hpp"

#include "../Time/Timer.hpp"

OSDL::EventData::EventData() {
	timestamp = OSDL::Timer::getTicks();
}

OSDL::Time OSDL::EventData::getTimestamp() const {
	return timestamp;
}

OSDL::EventData::~EventData() {
}
