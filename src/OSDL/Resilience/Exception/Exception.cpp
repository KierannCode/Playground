/*
 * Exception.cpp
 *
 *  Created on: 2 sept. 2021
 *      Author: Kierann
 */

#include "Exception.hpp"

OSDL::Exception::Exception() {
	this->message = "OSDL exception : ";
}

const char* OSDL::Exception::what() const {
	return message.c_str();
}
