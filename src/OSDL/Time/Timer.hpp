/*
 * Timer.hpp
 *
 *  Created on: 7 août 2021
 *      Author: Kierann
 */

#ifndef SRC_OSDL_TIME_TIMER_HPP_
#define SRC_OSDL_TIME_TIMER_HPP_

#include "../Types.hpp"

namespace OSDL {
class Timer {
public:
	static Time getTicks();
	static void delay(Time milliseconds);
};
}

#endif /* SRC_OSDL_TIME_TIMER_HPP_ */
