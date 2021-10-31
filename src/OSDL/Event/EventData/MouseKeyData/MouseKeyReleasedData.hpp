/*
 * MouseKeyReleasedData.hpp
 *
 *  Created on: 27 août 2021
 *      Author: Kierann
 */

#ifndef OSDL_MOUSEKEYRELEASEDDATA
#define OSDL_MOUSEKEYRELEASEDDATA

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

#endif /* OSDL_MOUSEKEYRELEASEDDATA */
