/*
 * IllegalCallException.cpp
 *
 *  Created on: 2 sept. 2021
 *      Author: Kierann
 */

#include "IllegalCallException.hpp"

OSDL::IllegalCallException::IllegalCallException() {
	message = "Illegal call : ";
}

OSDL::IllegalCallException::IllegalCallException(const char *message) {
	this->message += "Illegal call : ";
	this->message += std::string(message);
}
