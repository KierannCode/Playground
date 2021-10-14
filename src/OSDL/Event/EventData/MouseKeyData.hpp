/*
 * MouseKeyData.hpp
 *
 *  Created on: 8 août 2021
 *      Author: Kierann
 */

#ifndef SRC_OSDL_EVENT_EVENTDATA_MOUSEKEYDATA_HPP_
#define SRC_OSDL_EVENT_EVENTDATA_MOUSEKEYDATA_HPP_

#include "../EventData.hpp"

#include "../EventTypes.hpp"

namespace OSDL {
class MouseKeyData: public OSDL::EventData {
public:
	MouseKeyData(OSDL::MouseKey key, int x, int y);

	OSDL::MouseKey getKey();
	int getX();
	int getY();
private:
	OSDL::MouseKey key;
	int x;
	int y;
};
}

#endif /* SRC_OSDL_EVENT_EVENTDATA_MOUSEKEYDATA_HPP_ */
