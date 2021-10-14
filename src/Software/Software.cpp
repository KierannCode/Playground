/*
 * Software.cpp
 *
 *  Created on: 10 août 2021
 *      Author: Kierann
 */

#include "Software.hpp"

#include "../OSDL/Data/Atomic/AtomicBoolean.hpp"
#include "../OSDL/Data/Atomic/AtomicQueue.hpp"

#include "../OSDL/Event/EventData/WindowResizedData.hpp"
#include "../OSDL/Event/EventData/MouseKeyData/MouseKeyPressedData.hpp"
#include "../OSDL/Event/EventData/MouseMotionData.hpp"
#include "../OSDL/Event/EventData/MouseKeyData/MouseKeyReleasedData.hpp"
#include "../OSDL/Event/EventData/KeyboardKeyData/KeyboardKeyPressedData.hpp"
#include "../OSDL/Event/EventData/KeyboardKeyData/KeyboardKeyReleasedData.hpp"

#include "../OSDL/Resilience/Log.hpp"

#include "../OSDL/Time/Timer.hpp"

#include "../OSDL/Video/Surface.hpp"

#include "../OSDL/Thread/Mutex.hpp"

#include <stdexcept>

Software::Software() {
	windowWidth = 0;
	windowHeight = 0;

	over = false;
	exitValue = -1;
}

void Software::setWindowSize(OSDL::Size width, OSDL::Size height) {
	windowWidth = width;
	windowHeight = height;
}
void Software::importWindowSize(Software *software) {
	windowWidth = software->windowWidth;
	windowHeight = software->windowHeight;
}

void Software::manageEvents(OSDL::AtomicQueue *eventQueue) {
	OSDL::Time timestamp = OSDL::Timer::getTicks();
	OSDL::EventData *data = (OSDL::EventData*) (eventQueue->pop());
	while (data && data->getTimestamp() < timestamp) {
		switch (data->getEventType()) {
		case OSDL::EventType::WINDOW_RESIZED: {
			OSDL::WindowResizedData *resizeData =
					(OSDL::WindowResizedData*) (data);
			setWindowSize(resizeData->getWidth(),
					resizeData->getHeight());
			onWindowResized(resizeData->getWidth(),
					resizeData->getHeight());
			break;
		}
		case OSDL::EventType::MOUSE_KEY_PRESSED: {
			OSDL::MouseKeyPressedData *keyData =
					(OSDL::MouseKeyPressedData*) (data);
			onMouseKeyPressed(keyData->getKey(), keyData->getX(),
					keyData->getY());
			break;
		}
		case OSDL::EventType::MOUSE_MOTION: {
			OSDL::MouseMotionData *motionData = (OSDL::MouseMotionData*) (data);
			onMouseMotion(motionData->getX(), motionData->getY());
			break;
		}
		case OSDL::EventType::MOUSE_KEY_RELEASED: {
			OSDL::MouseKeyReleasedData *keyData =
					(OSDL::MouseKeyReleasedData*) (data);
			onMouseKeyReleased(keyData->getKey(), keyData->getX(),
					keyData->getY());
			break;
		}
		case OSDL::EventType::KEYBOARD_KEY_PRESSED: {
			OSDL::KeyboardKeyPressedData *keyData =
					(OSDL::KeyboardKeyPressedData*) (data);
			onKeyboardKeyPressed(keyData->getKey());
			break;
		}
		case OSDL::EventType::KEYBOARD_KEY_RELEASED: {
			OSDL::KeyboardKeyReleasedData *keyData =
					(OSDL::KeyboardKeyReleasedData*) (data);
			onKeyboardKeyReleased(keyData->getKey());
			break;
		}
		}
		data = (OSDL::EventData*) (eventQueue->pop());
	}
	if (data && data->getTimestamp() >= timestamp) {
		eventQueue->unPop();
	}
}

void Software::updateFrame() {
}

void Software::updateRenderingData() {
}

bool Software::isOver() const {
	return over;
}
int Software::getExitValue() const {
	return exitValue;
}

Software::~Software() {
}

void Software::onWindowResized(OSDL::Size width, OSDL::Size height) {
}
void Software::onMouseKeyPressed(OSDL::MouseKey key, int x, int y) {
}
void Software::onMouseMotion(int x, int y) {
}
void Software::onMouseKeyReleased(OSDL::MouseKey key, int x, int y) {
}
void Software::onKeyboardKeyPressed(OSDL::KeyboardKey key) {
}
void Software::onKeyboardKeyReleased(OSDL::KeyboardKey key) {
}
