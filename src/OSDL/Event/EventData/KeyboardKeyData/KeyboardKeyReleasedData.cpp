/*
 * KeyboardKeyReleasedData.cpp
 *
 *  Created on: 30 août 2021
 *      Author: Kierann
 */

#include "KeyboardKeyReleasedData.hpp"

OSDL::KeyboardKeyReleasedData::KeyboardKeyReleasedData(OSDL::KeyboardKey key) :
		OSDL::KeyboardKeyData(key) {
}

OSDL::KeyboardKeyReleasedData* OSDL::KeyboardKeyReleasedData::createCopy() const {
	return new OSDL::KeyboardKeyReleasedData(*this);
}

OSDL::EventType OSDL::KeyboardKeyReleasedData::getEventType() const {
	return OSDL::EventType::KEYBOARD_KEY_RELEASED;
}
