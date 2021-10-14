/*
 * EventManager.hpp
 *
 *  Created on: 9 juil. 2021
 *      Author: Kierann
 */

#ifndef SRC_EVENT_EVENTMANAGER_HPP_
#define SRC_EVENT_EVENTMANAGER_HPP_

class Renderer;
class Core;

namespace OSDL {
class Event;
class AtomicQueue;
}

class EventManager {
public:
	EventManager(Renderer &renderer, Core &core);

	OSDL::AtomicQueue* getEventQueue() const;

	void start();

	~EventManager();
private:
	Renderer *renderer;

	OSDL::Event *event;
	OSDL::AtomicQueue *eventQueue;

	bool running;
};

#endif /* SRC_EVENT_EVENTMANAGER_HPP_ */
