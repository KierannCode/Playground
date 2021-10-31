/*
 * WindowResizedData.hpp
 *
 *  Created on: 25 août 2021
 *      Author: Kierann
 */

#ifndef OSDL_WINDOWRESIZEDDATA
#define OSDL_WINDOWRESIZEDDATA

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

#endif /* OSDL_WINDOWRESIZEDDATA */
