/*
 * EventData.hpp
 *
 *  Created on: 7 août 2021
 *      Author: Kierann
 */

#ifndef OSDL_EVENTDATA
#define OSDL_EVENTDATA

#include "../Data/Data.hpp"

#include "EventTypes.hpp"

#include "../Types.hpp"

namespace OSDL {
class EventData : public OSDL::Data {
public:
	EventData();

	OSDL::Time getTimestamp() const;

	virtual OSDL::EventType getEventType() const = 0;

	virtual ~EventData();
private:
	OSDL::Time timestamp;
};
}

#endif /* OSDL_EVENTDATA */
