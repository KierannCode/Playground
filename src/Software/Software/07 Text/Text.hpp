/*
 * Text.hpp
 *
 *  Created on: 5 sept. 2021
 *      Author: Kierann
 */

#ifndef PLAYGROUND_TEXT
#define PLAYGROUND_TEXT

#include "../../Software.hpp"

class TextRenderer;

class Text: public Software {
public:
	Text();

	SoftwareRenderer *getSoftwareRenderer() const;

	~Text();
private:
	void onMouseKeyPressed(OSDL::MouseKey key, int x, int y);
	void onMouseMotion(int x, int y);
	void onMouseKeyReleased(OSDL::MouseKey key, int x, int y);

	TextRenderer *renderer;
};

#endif /* PLAYGROUND_TEXT */
