/*
 * MenuRenderer.hpp
 *
 *  Created on: 4 sept. 2021
 *      Author: Kierann
 */

#ifndef PLAYGROUND_MENURENDERER
#define PLAYGROUND_MENURENDERER

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

#endif /* PLAYGROUND_MENURENDERER */
