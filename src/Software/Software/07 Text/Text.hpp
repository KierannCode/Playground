/*
 * Text.hpp
 *
 *  Created on: 5 sept. 2021
 *      Author: Kierann
 */

#ifndef SRC_SOFTWARE_07_Text_Text_HPP_
#define SRC_SOFTWARE_07_Text_Text_HPP_

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

#endif /* SRC_SOFTWARE_07_Text_Text_HPP_ */
