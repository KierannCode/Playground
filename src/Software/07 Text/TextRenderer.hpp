/*
 * TextRenderer.hpp
 *
 *  Created on: 5 sept. 2021
 *      Author: Kierann
 */

#ifndef SRC_SOFTWARE_07_TEXT_TEXTRENDERER_HPP_
#define SRC_SOFTWARE_07_TEXT_TEXTRENDERER_HPP_

#include "../SoftwareRenderer.hpp"

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

#endif /* SRC_SOFTWARE_07_TEXT_TEXTRENDERER_HPP_ */
