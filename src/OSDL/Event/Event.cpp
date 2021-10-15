/*
 * Event.cpp
 *
 *  Created on: 29 août 2021
 *      Author: Kierann
 */

#include "Event.hpp"

#include "EventData/WindowClosedData.hpp"
#include "EventData/WindowResizedData.hpp"
#include "EventData/MouseKeyData/MouseKeyPressedData.hpp"
#include "EventData/MouseMotionData.hpp"
#include "EventData/MouseKeyData/MouseKeyReleasedData.hpp"
#include "EventData/KeyboardKeyData/KeyboardKeyPressedData.hpp"
#include "EventData/KeyboardKeyData/KeyboardKeyReleasedData.hpp"

#include "../Resilience/Log.hpp"
#include "../Resilience/Exception/SDLException.hpp"

#include <SDL_events.h>

OSDL::Event::Event() {
	event = new SDL_Event;
	eventData = nullptr;
}

void OSDL::Event::wait() {
	if (SDL_WaitEvent(event) == 0) {
		throw OSDL::SDLException();
	}
	updateEventData();
}
bool OSDL::Event::poll() {
	if (SDL_PollEvent(event) == 1) {
		updateEventData();
		return true;
	}
	return false;
}

OSDL::EventData* OSDL::Event::getEventData() const {
	return eventData;
}

OSDL::Event::~Event() {
	if (eventData != nullptr) {
		delete eventData;
	}
	delete event;
}

void OSDL::Event::updateEventData() {
	if (eventData != nullptr) {
		delete eventData;
		eventData = nullptr;
	}
	switch (event->type) {
	case SDL_WINDOWEVENT:
		switch (event->window.event) {
		case SDL_WINDOWEVENT_CLOSE:
			eventData = new OSDL::WindowClosedData();
			break;
		case SDL_WINDOWEVENT_SIZE_CHANGED:
			eventData = new OSDL::WindowResizedData(event->window.data1,
					event->window.data2);
			break;
		case SDL_WINDOWEVENT_FOCUS_GAINED:
			if (SDL_CaptureMouse(SDL_TRUE) == -1) {
				OSDL::Log::startInfo() << OSDL::SDLException().what()
						<< OSDL::Log::end;
			}
			break;
		}
		break;
	case SDL_MOUSEBUTTONDOWN:
		eventData = new MouseKeyPressedData(
				(OSDL::MouseKey) (event->button.button), event->button.x,
				event->button.y);
		break;
	case SDL_MOUSEMOTION:
		eventData = new MouseMotionData(event->motion.x, event->motion.y);
		break;
	case SDL_MOUSEBUTTONUP:
		eventData = new MouseKeyReleasedData(
				(OSDL::MouseKey) (event->button.button), event->button.x,
				event->button.y);
		break;
	case SDL_KEYDOWN:
		eventData = new KeyboardKeyPressedData(
				(OSDL::KeyboardKey) (event->key.keysym.scancode));
		break;
	case SDL_KEYUP:
		eventData = new KeyboardKeyReleasedData(
				(OSDL::KeyboardKey) (event->key.keysym.scancode));
		break;
	}
}
