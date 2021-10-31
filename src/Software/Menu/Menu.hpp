/*
 * Menu.hpp
 *
 *  Created on: 9 juil. 2021
 *      Author: Kierann
 */

#ifndef PLAYGROUND_MENU
#define PLAYGROUND_MENU

#include "../Software.hpp"

class MenuRenderer;

class Menu: public Software {
public:
	Menu();

	void updateRenderingData();
	SoftwareRenderer* getSoftwareRenderer() const;

	~Menu();
private:
	void onMouseMotion(int x, int y);
	void onMouseKeyReleased(OSDL::MouseKey key, int x, int y);

	MenuRenderer *renderer;

	int selectedSoftware;
};

#endif /* PLAYGROUND_MENU */
