/*
 * MouseMotionData.hpp
 *
 *  Created on: 7 août 2021
 *      Author: Kierann
 */

#ifndef OSDL_MOUSEMOTIONDATA
#define OSDL_MOUSEMOTIONDATA

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

#endif /* OSDL_MOUSEMOTIONDATA */
