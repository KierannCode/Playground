/*
 * KeyBoardKeyData.cpp
 *
 *  Created on: 30 août 2021
 *      Author: Kierann
 */

#include "KeyBoardKeyData.hpp"


OSDL::KeyboardKeyData::KeyboardKeyData(OSDL::KeyboardKey key) {
	this->key = key;
}
OSDL::KeyboardKey OSDL::KeyboardKeyData::getKey() {
	return key;
}
