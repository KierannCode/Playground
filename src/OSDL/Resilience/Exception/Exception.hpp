/*
 * Exception.hpp
 *
 *  Created on: 1 sept. 2021
 *      Author: Kierann
 */

#ifndef OSDL_EXCEPTION
#define OSDL_EXCEPTION

#include <exception>

#include <string>

namespace OSDL {
class Exception: public std::exception {
public:
	Exception();

	const char* what() const;
protected:
	std::string message;
};
}

#endif /* OSDL_EXCEPTION */
