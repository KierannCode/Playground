/*
 * TextRenderer.hpp
 *
 *  Created on: 5 sept. 2021
 *      Author: Kierann
 */

#ifndef PLAYGROUND_TEXTRENDERER
#define PLAYGROUND_TEXTRENDERER

#include "../../SoftwareRenderer.hpp"

namespace OSDL {
class Surface;
}

class TextRenderer: public SoftwareRenderer {
private:
	int size;
	int *x;
	int *y;

	friend class Text;
public:
	TextRenderer();

	void render(OSDL::Surface *surface);

	~TextRenderer();
};

#endif /* PLAYGROUND_TEXTRENDERER */
