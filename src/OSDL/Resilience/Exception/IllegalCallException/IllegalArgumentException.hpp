/*
 * IllegalArgumentException.hpp
 *
 *  Created on: 2 sept. 2021
 *      Author: Kierann
 */

#ifndef SRC_OSDL_RESILIENCE_EXCEPTION_ILLEGALCALLEXCEPTION_ILLEGALARGUMENTEXCEPTION_HPP_
#define SRC_OSDL_RESILIENCE_EXCEPTION_ILLEGALCALLEXCEPTION_ILLEGALARGUMENTEXCEPTION_HPP_

#include "../IllegalCallException.hpp"

namespace OSDL {
class IllegalArgumentException: public IllegalCallException {
public:
	IllegalArgumentException(const char *message);
};
}

#endif /* SRC_OSDL_RESILIENCE_EXCEPTION_ILLEGALCALLEXCEPTION_ILLEGALARGUMENTEXCEPTION_HPP_ */
