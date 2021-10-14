/*
 * Menu.cpp
 *
 *  Created on: 11 juil. 2021
 *      Author: Kierann
 */

#include "Menu.hpp"

#include "MenuRenderer.hpp"

#include "../../OSDL/Video/Surface.hpp"
#include "../../OSDL/Video/Color.hpp"

Menu::Menu() {
	renderer = new MenuRenderer();

	selectedSoftware = -1;
}

void Menu::updateRenderingData() {
	renderer->selectedSoftware = selectedSoftware;
}
SoftwareRenderer* Menu::getSoftwareRenderer() const {
	return renderer;
}

Menu::~Menu() {
	delete renderer;
}

void Menu::onMouseMotion(int x, int y) {
	selectedSoftware = 10 * x / windowWidth + 10 * (10 * y / windowHeight);
}
void Menu::onMouseKeyReleased(OSDL::MouseKey key, int x, int y) {
	switch (key) {
	case OSDL::MouseKey::LEFT:
		selectedSoftware = 10 * x / windowWidth + 10 * (10 * y / windowHeight);
		if (selectedSoftware >= 0 && selectedSoftware <= 99) {
			exitValue = selectedSoftware;
			over = true;
		}
		break;
	}
}
