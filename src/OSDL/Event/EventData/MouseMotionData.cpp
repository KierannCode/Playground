/*
 * MouseMotionData.cpp
 *
 *  Created on: 7 août 2021
 *      Author: Kierann
 */

#include "MouseMotionData.hpp"

OSDL::MouseMotionData::MouseMotionData(int x, int y) {
	this->x = x;
	this->y = y;
}

OSDL::MouseMotionData* OSDL::MouseMotionData::createCopy() const {
	return new OSDL::MouseMotionData(*this);
}

OSDL::EventType OSDL::MouseMotionData::getEventType() const {
	return OSDL::EventType::MOUSE_MOTION;
}

int OSDL::MouseMotionData::getX() {
	return x;
}

int OSDL::MouseMotionData::getY() {
	return y;
}
