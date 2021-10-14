/*
 * MouseKeyReleasedData.hpp
 *
 *  Created on: 27 août 2021
 *      Author: Kierann
 */

#ifndef SRC_OSDL_EVENT_EVENTDATA_MOUSEKEYDATA_MOUSEKEYRELEASEDDATA_HPP_
#define SRC_OSDL_EVENT_EVENTDATA_MOUSEKEYDATA_MOUSEKEYRELEASEDDATA_HPP_

#include "../MouseKeyData.hpp"

namespace OSDL {
class MouseKeyReleasedData: public OSDL::MouseKeyData {
public:
	MouseKeyReleasedData() = delete;
	MouseKeyReleasedData(OSDL::MouseKey key, int x, int y);

	OSDL::MouseKeyReleasedData* createCopy() const;

	OSDL::EventType getEventType() const;
};
}

#endif /* SRC_OSDL_EVENT_EVENTDATA_MOUSEKEYDATA_MOUSEKEYRELEASEDDATA_HPP_ */
