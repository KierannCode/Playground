/*
 * WindowClosedData.hpp
 *
 *  Created on: 29 août 2021
 *      Author: Kierann
 */

#ifndef SRC_OSDL_EVENT_EVENTDATA_WINDOWCLOSEDDATA_HPP_
#define SRC_OSDL_EVENT_EVENTDATA_WINDOWCLOSEDDATA_HPP_

#include "../EventData.hpp"

namespace OSDL {
class WindowClosedData: public OSDL::EventData {
public:
	WindowClosedData();

	OSDL::WindowClosedData* createCopy() const;

	OSDL::EventType getEventType() const;
};
}

#endif /* SRC_OSDL_EVENT_EVENTDATA_WINDOWCLOSEDDATA_HPP_ */
