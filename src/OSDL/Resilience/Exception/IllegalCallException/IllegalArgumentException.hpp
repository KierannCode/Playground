/*
 * IllegalArgumentException.hpp
 *
 *  Created on: 2 sept. 2021
 *      Author: Kierann
 */

#ifndef OSDL_ILLEGALARGUMENTEXCEPTION
#define OSDL_ILLEGALARGUMENTEXCEPTION

#include "IllegalCallException.hpp"

namespace OSDL {
class IllegalArgumentException: public IllegalCallException {
public:
	IllegalArgumentException(const char *message);
};
}

#endif /* OSDL_ILLEGALARGUMENTEXCEPTION */
