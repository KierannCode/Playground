/*
 * MouseKeyReleasedData.cpp
 *
 *  Created on: 27 août 2021
 *      Author: Kierann
 */

#include "MouseKeyReleasedData.hpp"

OSDL::MouseKeyReleasedData::MouseKeyReleasedData(OSDL::MouseKey key, int x, int y) :
		OSDL::MouseKeyData(key, x, y) {
}

OSDL::MouseKeyReleasedData* OSDL::MouseKeyReleasedData::createCopy() const {
	return new OSDL::MouseKeyReleasedData(*this);
}

OSDL::EventType OSDL::MouseKeyReleasedData::getEventType() const {
	return OSDL::EventType::MOUSE_KEY_RELEASED;
}
