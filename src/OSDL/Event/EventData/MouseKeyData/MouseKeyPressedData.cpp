/*
 * MouseKeyPressedData.cpp
 *
 *  Created on: 27 août 2021
 *      Author: Kierann
 */

#include "MouseKeyPressedData.hpp"

OSDL::MouseKeyPressedData::MouseKeyPressedData(OSDL::MouseKey key, int x, int y) :
		OSDL::MouseKeyData(key, x, y) {
}

OSDL::MouseKeyPressedData* OSDL::MouseKeyPressedData::createCopy() const {
	return new OSDL::MouseKeyPressedData(*this);
}

OSDL::EventType OSDL::MouseKeyPressedData::getEventType() const {
	return OSDL::EventType::MOUSE_KEY_PRESSED;
}
