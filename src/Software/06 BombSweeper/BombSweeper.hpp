/*
 * BombSweeper.hpp
 *
 *  Created on: 19 juil. 2021
 *      Author: Kierann
 */

#ifndef SRC_SOFTWARE_06_BOMBSWEEPER_BOMBSWEEPER_HPP_
#define SRC_SOFTWARE_06_BOMBSWEEPER_BOMBSWEEPER_HPP_

#include "../Software.hpp"

#include "BombSweeperTypes.hpp"

class BombSweeperRenderer;

class BombSweeper: public Software {
public:
	BombSweeper();

	void updateFrame();

	void updateRenderingData();
	SoftwareRenderer* getSoftwareRenderer() const;

	~BombSweeper();
private:
	void onMouseKeyPressed(OSDL::MouseKey key, int x, int y);
	void onMouseMotion(int x, int y);
	void onMouseKeyReleased(OSDL::MouseKey key, int x, int y);
	void onKeyboardKeyPressed(OSDL::KeyboardKey key);

	void fill();
	void clear();

	void resetBoard(int width, int height);

	bool checkSolvedBoard(BoxContent *board, int width, int height);
	void completeSolvedBoard(BoxContent *board, int width, int height);
	BoxContent* tryBoardCompletion(BoxContent *board, int width, int height,
			int rupoorsLeft, int bombsLeft);

	int width;
	int height;
	int rupoorCount;
	int bombCount;

	BombSweeperRenderer *renderer;

	int rupoorsLeft;
	int bombsLeft;
	BoxContent *visibleBoard;

	int *availableBox;
	int availableBoxCount;

	BoxContent *hiddenBoard;

	int attemptsPerFrame;
	int total;
	double **probability;

	int selectedBox;

	BoxContent selectedType;

	bool fillMode;
	bool clearMode;

	int **boxCount;
};

#endif /* SRC_SOFTWARE_06_BOMBSWEEPER_BOMBSWEEPER_HPP_ */
