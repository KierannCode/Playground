/*
 * MouseKeyPressedData.hpp
 *
 *  Created on: 27 août 2021
 *      Author: Kierann
 */

#ifndef SRC_EVENT_EVENTDATA_MOUSEKEYDATA_MOUSEKEYPRESSEDDATA_HPP_
#define SRC_EVENT_EVENTDATA_MOUSEKEYDATA_MOUSEKEYPRESSEDDATA_HPP_

#include "../MouseKeyData.hpp"

namespace OSDL {
class MouseKeyPressedData: public OSDL::MouseKeyData {
public:
	MouseKeyPressedData() = delete;
	MouseKeyPressedData(OSDL::MouseKey key, int x, int y);

	OSDL::MouseKeyPressedData* createCopy() const;

	OSDL::EventType getEventType() const;
};
}

#endif /* SRC_EVENT_EVENTDATA_MOUSEKEYDATA_MOUSEKEYPRESSEDDATA_HPP_ */
