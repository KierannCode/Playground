/*
 * Math.hpp
 *
 *  Created on: 22 sept. 2021
 *      Author: Kierann
 */

#ifndef SRC_OSDL_MATH_MATH_HPP_
#define SRC_OSDL_MATH_MATH_HPP_

namespace OSDL {
class Math {
public:
	static float min(float a, float b);
	static float max(float a, float b);

	static int floor(float x);
	static int ceil(float y);
};
}

#endif /* SRC_OSDL_MATH_MATH_HPP_ */
