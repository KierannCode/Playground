/*
 * Color.cpp
 *
 *  Created on: 15 sept. 2021
 *      Author: Kierann
 */

#include "Color.hpp"

OSDL::Color::Color() {
	color = 0xffffffff;
}

OSDL::Color::Color(uint8 red, uint8 green, uint8 blue) {
	color = red << 24 | green << 16 | blue << 8 | 0xff;
}

OSDL::Color::Color(uint8 red, uint8 green, uint8 blue, uint8 alpha) {
	color = red << 24 | green << 16 | blue << 8 | alpha;
}

const uint32 OSDL::Color::RMask = 0xff000000;
const uint32 OSDL::Color::GMask = 0x00ff0000;
const uint32 OSDL::Color::BMask = 0x0000ff00;
const uint32 OSDL::Color::AMask = 0x000000ff;
