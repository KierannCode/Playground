/*
 * MouseKeyData.hpp
 *
 *  Created on: 8 août 2021
 *      Author: Kierann
 */

#ifndef OSDL_MOUSEKEYDATA
#define OSDL_MOUSEKEYDATA

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

#endif /* OSDL_MOUSEKEYDATA */
