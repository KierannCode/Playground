/*
 * BombSweeperRenderer.hpp
 *
 *  Created on: 10 août 2021
 *      Author: Kierann
 */

#ifndef SRC_SOFTWARE_06_BOMBSWEEPER_BOMBSWEEPERRENDERER_HPP_
#define SRC_SOFTWARE_06_BOMBSWEEPER_BOMBSWEEPERRENDERER_HPP_

#include "../../../OSDL/Types.hpp"
#include "BombSweeperTypes.hpp"
#include "../../SoftwareRenderer.hpp"

namespace OSDL {
class Color;
}

class BombSweeperRenderer: public SoftwareRenderer {
public:
	BombSweeperRenderer(int width, int height, int rupoorCount, int bombCount);

	void render(OSDL::Surface *surface);

	~BombSweeperRenderer();
private:
	OSDL::Color getRupeeColor(BoxContent type);
	OSDL::Color getRiskColor(double probability);
	OSDL::Color getExpectancyColor(double rate);

	int width;
	int height;
	int rupoorCount;
	int bombCount;

	int rupoorsLeft;
	int bombsLeft;
	BoxContent *board;

	double **probability;

	int selectedBox;

	BoxContent selectedType;

	OSDL::Surface **contentImage;

	friend class BombSweeper;
};

#endif /* SRC_SOFTWARE_06_BOMBSWEEPER_BOMBSWEEPERRENDERER_HPP_ */
