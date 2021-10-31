/*
 * Math.hpp
 *
 *  Created on: 22 sept. 2021
 *      Author: Kierann
 */

#ifndef OSDL_MATH
#define OSDL_MATH

namespace OSDL {
class Math {
public:
	static float min(float a, float b);
	static float max(float a, float b);

	static int floor(float x);
	static int ceil(float y);
};
}

#endif /* OSDL_MATH */
