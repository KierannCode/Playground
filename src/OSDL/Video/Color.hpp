/*
 * Color.hpp
 *
 *  Created on: 11 sept. 2021
 *      Author: Kierann
 */

#ifndef OSDL_COLOR
#define OSDL_COLOR

#include "../Types.hpp"

namespace OSDL {
class Surface;
class Window;

class Color {
public:
	Color();
	Color(uint8 red, uint8 green, uint8 blue);
	Color(uint8 red, uint8 green, uint8 blue, uint8 alpha);
private:
	uint32 color;

	const static uint32 RMask;
	const static uint32 GMask;
	const static uint32 BMask;
	const static uint32 AMask;

	friend class OSDL::Surface;
};
}

#endif /* OSDL_COLOR */
