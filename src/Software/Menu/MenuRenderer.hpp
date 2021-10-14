/*
 * MenuRenderer.hpp
 *
 *  Created on: 4 sept. 2021
 *      Author: Kierann
 */

#ifndef SRC_SOFTWARE_MENU_MENURENDERER_HPP_
#define SRC_SOFTWARE_MENU_MENURENDERER_HPP_

#include "../SoftwareRenderer.hpp"

namespace OSDL {
class Surface;
}

class MenuRenderer: public SoftwareRenderer {
public:
	MenuRenderer();

	void render(OSDL::Surface *surface);

	~MenuRenderer();
private:
	OSDL::Surface **softwareIcon;

	int selectedSoftware;

	friend class Menu;
};

#endif /* SRC_SOFTWARE_MENU_MENURENDERER_HPP_ */
