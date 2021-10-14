/*
 * KeyboardKeyPressedData.cpp
 *
 *  Created on: 30 août 2021
 *      Author: Kierann
 */

#include "KeyboardKeyPressedData.hpp"

OSDL::KeyboardKeyPressedData::KeyboardKeyPressedData(OSDL::KeyboardKey key) :
		OSDL::KeyboardKeyData(key) {
}

OSDL::KeyboardKeyPressedData* OSDL::KeyboardKeyPressedData::createCopy() const {
	return new OSDL::KeyboardKeyPressedData(*this);
}

OSDL::EventType OSDL::KeyboardKeyPressedData::getEventType() const {
	return OSDL::EventType::KEYBOARD_KEY_PRESSED;
}
