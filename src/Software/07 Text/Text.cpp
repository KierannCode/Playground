/*
 * Text.cpp
 *
 *  Created on: 5 sept. 2021
 *      Author: Kierann
 */

#include "Text.hpp"

#include "TextRenderer.hpp"

Text::Text() {
	renderer = new TextRenderer();
}

SoftwareRenderer* Text::getSoftwareRenderer() const {
	return renderer;
}

Text::~Text() {
	delete renderer;
}

void Text::onMouseKeyPressed(OSDL::MouseKey key, int x, int y) {
}
void Text::onMouseMotion(int x, int y) {
}
void Text::onMouseKeyReleased(OSDL::MouseKey key, int x, int y) {
}
