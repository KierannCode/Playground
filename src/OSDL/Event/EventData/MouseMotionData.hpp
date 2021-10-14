/*
 * MouseMotionData.hpp
 *
 *  Created on: 7 août 2021
 *      Author: Kierann
 */

#ifndef SRC_OSDL_EVENT_EVENTDATA_MOUSEMOTIONDATA_HPP_
#define SRC_OSDL_EVENT_EVENTDATA_MOUSEMOTIONDATA_HPP_

#include "../EventData.hpp"

namespace OSDL {
class MouseMotionData: public OSDL::EventData {
public:
	MouseMotionData() = delete;
	MouseMotionData(int x, int y);

	OSDL::MouseMotionData* createCopy() const;

	OSDL::EventType getEventType() const;

	int getX();
	int getY();
private:
	int x;
	int y;
};
}

#endif /* SRC_OSDL_EVENT_EVENTDATA_MOUSEMOTIONDATA_HPP_ */
