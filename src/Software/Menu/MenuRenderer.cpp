/*
 * MenuRenderer.cpp
 *
 *  Created on: 4 sept. 2021
 *      Author: Kierann
 */

#include "MenuRenderer.hpp"

#include "../../OSDL/Resilience/Log.hpp"

#include "../../OSDL/Video/Surface.hpp"
#include "../../OSDL/Video/Color.hpp"

MenuRenderer::MenuRenderer() {
	softwareIcon = new OSDL::Surface*[100];
	std::string iconName("Ressources\\Menu\\XX.bmp");
	for (int d = 0; d < 10; ++d) {
		iconName[16] = '0' + d;
		for (int u = 0; u < 10; ++u) {
			iconName[17] = '0' + u;
			softwareIcon[10 * d + u] = new OSDL::Surface(iconName.c_str());
		}
	}

	selectedSoftware = -1;
}

void MenuRenderer::render(OSDL::Surface *surface) {
	surface->fill(OSDL::Color(64, 32, 156));
	OSDL::Size width = surface->getWidth();
	OSDL::Size height = surface->getHeight();
	int k = 0;
	for (int j = 0; j < 10; ++j) {
		for (int i = 0; i < 10; ++i) {
			softwareIcon[k]->blit(surface, (2 * i + 1) * width / 20 - 31,
					(2 * j + 1) * height / 20 - 31);
			if (k == selectedSoftware) {
				OSDL::Surface(62, 62, OSDL::Color(255, 255, 255, 128)).blit(
						surface, (2 * i + 1) * width / 20 - 31,
						(2 * j + 1) * height / 20 - 31);
			}
			++k;
		}
	}
}

MenuRenderer::~MenuRenderer() {
	for (int k = 0; k < 100; ++k) {
		delete softwareIcon[k];
	}
	delete[] softwareIcon;
}
