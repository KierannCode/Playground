/*
 * WindowClosedData.hpp
 *
 *  Created on: 29 août 2021
 *      Author: Kierann
 */

#ifndef OSDL_WINDOWCLOSEDDATA
#define OSDL_WINDOWCLOSEDDATA

#include "../EventData.hpp"

namespace OSDL {
class WindowClosedData: public OSDL::EventData {
public:
	WindowClosedData();

	OSDL::WindowClosedData* createCopy() const;

	OSDL::EventType getEventType() const;
};
}

#endif /* OSDL_WINDOWCLOSEDDATA */
