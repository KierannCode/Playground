/*
 * Event.hpp
 *
 *  Created on: 28 août 2021
 *      Author: Kierann
 */

#ifndef SRC_OSDL_EVENT_EVENT_HPP_
#define SRC_OSDL_EVENT_EVENT_HPP_

#include "EventTypes.hpp"

union SDL_Event;

namespace OSDL {
class EventData;

class Event {
public:
	Event();

	void wait();
	bool poll();

	OSDL::EventData* getEventData() const;

	~Event();
private:
	SDL_Event *event;

	OSDL::EventData *eventData;

	void updateEventData();
};
}

#endif /* SRC_OSDL_EVENT_EVENT_HPP_ */
