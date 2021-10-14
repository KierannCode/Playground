/*
 * WindowResizedData.cpp
 *
 *  Created on: 25 août 2021
 *      Author: Kierann
 */

#include "WindowResizedData.hpp"

OSDL::WindowResizedData::WindowResizedData(OSDL::Size width,
		OSDL::Size height) {
	this->width = width;
	this->height = height;
}

OSDL::WindowResizedData* OSDL::WindowResizedData::createCopy() const {
	return new OSDL::WindowResizedData(*this);
}

OSDL::EventType OSDL::WindowResizedData::getEventType() const {
	return OSDL::EventType::WINDOW_RESIZED;
}

OSDL::Size OSDL::WindowResizedData::getWidth() {
	return width;
}
OSDL::Size OSDL::WindowResizedData::getHeight() {
	return height;
}
