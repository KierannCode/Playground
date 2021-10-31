/*
 * SDLException.hpp
 *
 *  Created on: 14 juil. 2021
 *      Author: Kierann
 */

#ifndef OSDL_SDLEXCEPTION
#define OSDL_SDLEXCEPTION

#include "Exception.hpp"

namespace OSDL {
class SDLException: public OSDL::Exception {
public:
	SDLException();
};
}

#endif /* OSDL_SDLEXCEPTION */
