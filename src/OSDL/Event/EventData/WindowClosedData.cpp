/*
 * WindowClosedData.cpp
 *
 *  Created on: 29 août 2021
 *      Author: Kierann
 */

#include "WindowClosedData.hpp"

OSDL::WindowClosedData::WindowClosedData() {
}

OSDL::WindowClosedData* OSDL::WindowClosedData::createCopy() const {
	return new OSDL::WindowClosedData(*this);
}

OSDL::EventType OSDL::WindowClosedData::getEventType() const {
	return OSDL::EventType::WINDOW_CLOSED;
}
