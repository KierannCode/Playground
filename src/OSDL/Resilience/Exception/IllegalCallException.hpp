/*
 * IllegalCallException.hpp
 *
 *  Created on: 2 sept. 2021
 *      Author: Kierann
 */

#ifndef SRC_OSDL_RESILIENCE_EXCEPTION_ILLEGALCALLEXCEPTION_HPP_
#define SRC_OSDL_RESILIENCE_EXCEPTION_ILLEGALCALLEXCEPTION_HPP_

#include "../Exception.hpp"

namespace OSDL {
class IllegalCallException: public OSDL::Exception {
public:
	IllegalCallException();
	IllegalCallException(const char *message);
};
}

#endif /* SRC_OSDL_RESILIENCE_EXCEPTION_ILLEGALCALLEXCEPTION_HPP_ */
