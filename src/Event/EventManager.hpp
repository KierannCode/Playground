/*
 * EventManager.hpp
 *
 *  Created on: 9 juil. 2021
 *      Author: Kierann
 */

#ifndef SRC_EVENT_EVENTMANAGER_HPP_
#define SRC_EVENT_EVENTMANAGER_HPP_

class RenderingThread;
class CoreThread;

namespace OSDL {
class Event;
class AtomicQueue;
}

class EventManager {
public:
	EventManager(RenderingThread &renderingThread, CoreThread &coreThread);

	OSDL::AtomicQueue* getEventQueue() const;

	void start();

	~EventManager();
private:
	RenderingThread *renderingThread;

	OSDL::Event *event;
	OSDL::AtomicQueue *eventQueue;

	bool running;
};

#endif /* SRC_EVENT_EVENTMANAGER_HPP_ */
