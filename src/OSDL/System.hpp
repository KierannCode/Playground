/*
 * System.hpp
 *
 *  Created on: 12 sept. 2021
 *      Author: Kierann
 */

#ifndef SRC_OSDL_SYSTEM_HPP_
#define SRC_OSDL_SYSTEM_HPP_

#include "Types.hpp"

namespace OSDL {
class System {
public:
	static void initialize();
	static void quit();
};
}

#endif /* SRC_OSDL_SYSTEM_HPP_ */
