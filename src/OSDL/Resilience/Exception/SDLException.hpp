/*
 * SDLException.hpp
 *
 *  Created on: 14 juil. 2021
 *      Author: Kierann
 */

#ifndef SRC_OSDL_RESILIENCE_EXCEPTION_SDLEXCEPTION_HPP_
#define SRC_OSDL_RESILIENCE_EXCEPTION_SDLEXCEPTION_HPP_

#include "../Exception.hpp"

namespace OSDL {
class SDLException: public OSDL::Exception {
public:
	SDLException();
	SDLException(const char *adviceMessage);
};
}

#endif /* SRC_OSDL_RESILIENCE_EXCEPTION_SDLEXCEPTION_HPP_ */
