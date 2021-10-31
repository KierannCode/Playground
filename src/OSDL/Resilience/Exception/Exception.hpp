/*
 * Exception.hpp
 *
 *  Created on: 1 sept. 2021
 *      Author: Kierann
 */

#ifndef SRC_OSDL_RESILIENCE_EXCEPTION_EXCEPTION_HPP_
#define SRC_OSDL_RESILIENCE_EXCEPTION_EXCEPTION_HPP_

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

#endif /* SRC_OSDL_RESILIENCE_EXCEPTION_EXCEPTION_HPP_ */
