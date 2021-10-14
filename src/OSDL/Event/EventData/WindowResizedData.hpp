/*
 * WindowResizedData.hpp
 *
 *  Created on: 25 août 2021
 *      Author: Kierann
 */

#ifndef SRC_OSDL_EVENT_EVENTDATA_WINDOWRESIZEDDATA_HPP_
#define SRC_OSDL_EVENT_EVENTDATA_WINDOWRESIZEDDATA_HPP_

#include "../EventData.hpp"

namespace OSDL {
class WindowResizedData: public OSDL::EventData {
public:
	WindowResizedData() = delete;
	WindowResizedData(OSDL::Size width, OSDL::Size height);

	OSDL::WindowResizedData* createCopy() const;

	OSDL::EventType getEventType() const;

	OSDL::Size getWidth();
	OSDL::Size getHeight();
private:
	OSDL::Size width;
	OSDL::Size height;
};
}

#endif /* SRC_OSDL_EVENT_EVENTDATA_WINDOWRESIZEDDATA_HPP_ */
