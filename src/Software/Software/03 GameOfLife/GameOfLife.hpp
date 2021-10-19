/*
 * GameOfLife.hpp
 *
 *  Created on: 9 juil. 2021
 *      Author: Kierann
 */

#ifndef SRC_SOFTWARE_03_GAMEOFLIFE_GAMEOFLIFE_HPP_
#define SRC_SOFTWARE_03_GAMEOFLIFE_GAMEOFLIFE_HPP_

#include "../../Software.hpp"

struct BoardState {
	bool *cellState;
};

class GameOfLife: public Software {
private:
	int width;
	int height;
	int generation;
	float speed;

	BoardState *currentBoardState;
	BoardState *nextBoardState;
	int *neighboursCount;
public:
	GameOfLife();

	void prepareNextFrame();
	void updateCurrentFrame();

	void renderCurrentFrame();

	~GameOfLife();
};

#endif /* SRC_SOFTWARE_03_GAMEOFLIFE_GAMEOFLIFE_HPP_ */
