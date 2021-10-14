/*
 * EventData.hpp
 *
 *  Created on: 7 août 2021
 *      Author: Kierann
 */

#ifndef SRC_OSDL_EVENT_EVENTDATA_HPP_
#define SRC_OSDL_EVENT_EVENTDATA_HPP_

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

#endif /* SRC_OSDL_EVENT_EVENTDATA_HPP_ */
