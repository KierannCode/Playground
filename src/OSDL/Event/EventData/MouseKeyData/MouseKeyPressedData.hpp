/*
 * MouseKeyPressedData.hpp
 *
 *  Created on: 27 août 2021
 *      Author: Kierann
 */

#ifndef OSDL_MOUSEKEYPRESSEDDATA
#define OSDL_MOUSEKEYPRESSEDDATA

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

#endif /* OSDL_MOUSEKEYPRESSEDDATA */
