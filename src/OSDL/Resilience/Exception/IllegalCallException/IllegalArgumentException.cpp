/*
 * IllegalArgumentException.cpp
 *
 *  Created on: 2 sept. 2021
 *      Author: Kierann
 */

#include "IllegalArgumentException.hpp"

OSDL::IllegalArgumentException::IllegalArgumentException(const char *message) {
	this->message += "Illegal argument : ";
	this->message += message;
}
