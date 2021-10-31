/*
 * Timer.hpp
 *
 *  Created on: 7 août 2021
 *      Author: Kierann
 */

#ifndef OSDL_TIMER
#define OSDL_TIMER

#include "../Types.hpp"

namespace OSDL {
class Timer {
public:
	static Time getTicks();
	static void delay(Time milliseconds);
};
}

#endif /* OSDL_TIMER */
