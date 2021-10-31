/*
 * Event.hpp
 *
 *  Created on: 28 août 2021
 *      Author: Kierann
 */

#ifndef OSDL_EVENT
#define OSDL_EVENT

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

#endif /* OSDL_EVENT */
