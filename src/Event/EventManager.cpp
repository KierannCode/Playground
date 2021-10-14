/*
 * EventManager.cpp
 *
 *  Created on: 9 juil. 2021
 *      Author: Kierann
 */

#include "EventManager.hpp"

#include "../OSDL/Data/Atomic/AtomicQueue.hpp"

#include "../OSDL/Event/Event.hpp"
#include "../OSDL/Event/EventData/WindowResizedData.hpp"
#include "../OSDL/Event/EventData/MouseKeyData/MouseKeyPressedData.hpp"
#include "../OSDL/Event/EventData/MouseMotionData.hpp"
#include "../OSDL/Event/EventData/MouseKeyData/MouseKeyReleasedData.hpp"

#include "../OSDL/Resilience/Log.hpp"

#include "../OSDL/Thread/Semaphore.hpp"
#include "../OSDL/Time/Timer.hpp"

#include "../Video/Renderer.hpp"
#include "../Core/Core.hpp"

EventManager::EventManager(Renderer &renderer, Core &core) {
	this->renderer = &renderer;

	event = new OSDL::Event;
	eventQueue = new OSDL::AtomicQueue;

	running = true;

	core.setEventQueue(eventQueue);
}

OSDL::AtomicQueue* EventManager::getEventQueue() const {
	return eventQueue;
}

void EventManager::start() {
	while (running) {
		event->wait();
		OSDL::EventData *eventData = event->getEventData();
		if (eventData != nullptr) {
			eventQueue->push(*eventData);
			switch (eventData->getEventType()) {
			case OSDL::EventType::WINDOW_CLOSED:
				OSDL::Log::info("Close request");
				running = false;
				break;
			case OSDL::EventType::WINDOW_RESIZED:
				renderer->requestSurfaceResizing();
				break;
			}
		}
	}
}

EventManager::~EventManager() {
	delete eventQueue;
	delete event;
}
