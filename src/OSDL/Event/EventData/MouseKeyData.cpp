/*
 * MouseKeyData.cpp
 *
 *  Created on: 8 août 2021
 *      Author: Kierann
 */

#include "MouseKeyData.hpp"

OSDL::MouseKeyData::MouseKeyData(OSDL::MouseKey key, int x, int y) {
	this->key = key;
	this->x = x;
	this->y = y;
}
OSDL::MouseKey OSDL::MouseKeyData::getKey() {
	return key;
}
int OSDL::MouseKeyData::getX() {
	return x;
}
int OSDL::MouseKeyData::getY() {
	return y;
}

