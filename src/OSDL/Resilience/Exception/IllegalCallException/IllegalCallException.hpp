/*
 * IllegalCallException.hpp
 *
 *  Created on: 2 sept. 2021
 *      Author: Kierann
 */

#ifndef OSDL_ILLEGALCALLEXCEPTION
#define OSDL_ILLEGALCALLEXCEPTION

#include "../Exception.hpp"

namespace OSDL {
class IllegalCallException: public OSDL::Exception {
public:
	IllegalCallException();
	IllegalCallException(const char *message);
};
}

#endif /* OSDL_ILLEGALCALLEXCEPTION */
