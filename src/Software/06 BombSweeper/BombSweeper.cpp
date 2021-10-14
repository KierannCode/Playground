/*
 * BombSweeper.cpp
 *
 *  Created on: 20 juil. 2021
 *      Author: Kierann
 */

#include "BombSweeper.hpp"

#include "BombSweeperRenderer.hpp"

#include "../../Event/EventManager.hpp"

#include "../../OSDL/Resilience/Log.hpp"

#include "../../OSDL/Video/Surface.hpp"
#include "../../OSDL/Video/Color.hpp"

BombSweeper::BombSweeper() {

	width = 8;
	height = 5;
	rupoorCount = 8;
	bombCount = 8;

	renderer = new BombSweeperRenderer(width, height, rupoorCount, bombCount);

	rupoorsLeft = rupoorCount;
	bombsLeft = bombCount;
	visibleBoard = new BoxContent[width * height];
	for (int k = 0; k < width * height; ++k) {
		visibleBoard[k] = HIDDEN;
	}

	availableBox = new int[width * height];
	for (int k = 0; k < width * height; ++k) {
		availableBox[k] = k;
	}
	availableBoxCount = width * height;

	hiddenBoard = tryBoardCompletion(visibleBoard, width, height, rupoorsLeft,
			bombsLeft);

	attemptsPerFrame = 100;
	total = 0;

	probability = new double*[7];
	for (int t = 0; t < 7; ++t) {
		probability[t] = new double[width * height];
		for (int k = 0; k < width * height; ++k) {
			probability[t][k] = 0;
		}
	}

	selectedBox = -1;

	selectedType = HIDDEN;

	fillMode = false;
	clearMode = false;

	boxCount = new int*[7];
	for (int type = GREEN_RUPEE; type < HIDDEN; ++type) {
		boxCount[type] = new int[width * height];
	}
}

void BombSweeper::updateFrame() {
	for (int t = 0; t < 7; ++t) {
		for (int k = 0; k < width * height; ++k) {
			boxCount[t][k] = 0;
		}
	}
	int count = 0;
	for (int i = 0; i < attemptsPerFrame; ++i) {
		BoxContent *completedBoard = tryBoardCompletion(visibleBoard, width,
				height, rupoorsLeft, bombsLeft);
		if (completedBoard != nullptr) {
			for (int k = 0; k < width * height; ++k) {
				++boxCount[completedBoard[k]][k];
			}
			delete completedBoard;
			++count;
		}
	}
	total += count;
	if (total >= 1) {
		for (int t = 0; t < 7; ++t) {
			for (int k = 0; k < width * height; ++k) {
				probability[t][k] *= total - count;
				probability[t][k] += boxCount[t][k];
				probability[t][k] /= total;
			}
		}
	}
}

void BombSweeper::updateRenderingData() {
	if (renderer->width != width || renderer->height != height) {
		delete[] renderer->board;
		renderer->board = new BoxContent[width * height];
		for (int t = 0; t < 7; ++t) {
			delete[] renderer->probability[t];
			renderer->probability[t] = new double[width * height];
		}
	}
	renderer->width = width;
	renderer->height = height;
	renderer->rupoorCount = rupoorCount;
	renderer->bombCount = bombCount;

	renderer->rupoorsLeft = rupoorsLeft;
	renderer->bombsLeft = bombsLeft;
	for (int k = 0; k < width * height; ++k) {
		renderer->board[k] = visibleBoard[k];
	}

	for (int t = 0; t < 7; ++t) {
		for (int k = 0; k < width * height; ++k) {
			renderer->probability[t][k] = probability[t][k];
		}
	}

	renderer->selectedBox = selectedBox;

	renderer->selectedType = selectedType;
}
SoftwareRenderer* BombSweeper::getSoftwareRenderer() const {
	return renderer;
}

BombSweeper::~BombSweeper() {
	for (int t = 0; t < 7; ++t) {
		delete[] boxCount[t];
	}
	delete[] boxCount;

	for (int t = 0; t < 7; ++t) {
		delete[] probability[t];
	}
	delete[] probability;

	delete[] hiddenBoard;

	delete availableBox;

	delete[] visibleBoard;

	delete renderer;
}

void BombSweeper::onMouseKeyPressed(OSDL::MouseKey key, int x, int y) {
	if (key == OSDL::MouseKey::LEFT && !clearMode) {
		fillMode = true;
		fill();
	}
	if (key == OSDL::MouseKey::RIGHT && !fillMode) {
		clearMode = true;
		clear();
	}
}
void BombSweeper::onMouseMotion(int x, int y) {
	if (x >= 0 && x < 8 * windowWidth / 9 && y >= 0
			&& y < height * windowHeight / (height + 2)) {
		selectedBox = 9 * width * x / (8 * windowWidth)
				+ width * ((height + 2) * y / windowHeight);
	} else if (x >= 0 && x < 8 * windowWidth / 9 && y >= (height + 1) * windowHeight / (height + 2) && y < windowHeight) {
		selectedBox = width * height + 9 * x / windowWidth;
	} else {
		selectedBox = -1;
	}
	if (fillMode) {
		fill();
	}
	if (clearMode) {
		clear();
	}
}
void BombSweeper::onMouseKeyReleased(OSDL::MouseKey key, int x, int y) {
	if (key == OSDL::MouseKey::LEFT) {
		fillMode = false;
	}
	if (key == OSDL::MouseKey::RIGHT) {
		clearMode = false;
	}
}
void BombSweeper::onKeyboardKeyPressed(OSDL::KeyboardKey key) {
	switch (key) {
	case OSDL::KeyboardKey::PAD_PLUS:
		if (bombCount + rupoorCount < availableBoxCount) {
			BoxContent *newHiddenBoard;
			if (selectedType == RUPOOR) {
				newHiddenBoard = tryBoardCompletion(visibleBoard, width, height,
						rupoorsLeft + 1, bombsLeft);
				if (newHiddenBoard != nullptr) {
					++rupoorCount;
					++rupoorsLeft;
					total = 0;
					delete[] hiddenBoard;
					hiddenBoard = newHiddenBoard;
				}
			} else if (selectedType == BOMB) {
				newHiddenBoard = tryBoardCompletion(visibleBoard, width, height,
						rupoorsLeft, bombsLeft + 1);
				if (newHiddenBoard != nullptr) {
					++bombCount;
					++bombsLeft;
					total = 0;
					delete[] hiddenBoard;
					hiddenBoard = newHiddenBoard;
				}
				availableBoxCount = width * height;
			}
		}
		break;
	case OSDL::KeyboardKey::PAD_MINUS:
		BoxContent *newHiddenBoard;
		if (selectedType == RUPOOR && rupoorsLeft > 0) {
			newHiddenBoard = tryBoardCompletion(visibleBoard, width, height,
					rupoorsLeft - 1, bombsLeft);
			if (newHiddenBoard != nullptr) {
				--rupoorCount;
				--rupoorsLeft;
				total = 0;
				delete[] hiddenBoard;
				hiddenBoard = newHiddenBoard;
			}
		} else if (selectedType == BOMB && bombsLeft > 0) {
			newHiddenBoard = tryBoardCompletion(visibleBoard, width, height,
					rupoorsLeft, bombsLeft - 1);
			if (newHiddenBoard != nullptr) {
				--bombCount;
				--bombsLeft;
				total = 0;
				delete[] hiddenBoard;
				hiddenBoard = newHiddenBoard;
			}
		}
		break;
	case OSDL::KeyboardKey::DOWN:
		resetBoard(width, height + 1);
		break;
	case OSDL::KeyboardKey::RIGHT:
		resetBoard(width + 1, height);
		break;
	case OSDL::KeyboardKey::UP:
		if (width * (height - 1) >= bombCount + rupoorCount) {
			resetBoard(width, height - 1);
		}
		break;
	case OSDL::KeyboardKey::LEFT:
		if ((width - 1) * height >= bombCount + rupoorCount) {
			resetBoard(width - 1, height);
		}
		break;
	case OSDL::KeyboardKey::R:
		resetBoard(width, height);
		break;
	case OSDL::KeyboardKey::ESCAPE:
		over = true;
		break;
	}
}

void BombSweeper::fill() {
	if (selectedBox >= 0 && selectedBox < width * height) {
		if (selectedType == HIDDEN && visibleBoard[selectedBox] == HIDDEN) {
			OSDL::Log::debug("Trying to uncover hidden box");
			BoxContent hiddenType = hiddenBoard[selectedBox];
			OSDL::Log::debug("Hidden box uncovered");
			visibleBoard[selectedBox] = hiddenType;
			int index = 0;
			while (index < availableBoxCount
					&& availableBox[index] != selectedBox) {
				++index;
			}
			--availableBoxCount;
			availableBox[index] = availableBox[availableBoxCount];
			if (hiddenType == RUPOOR) {
				--rupoorsLeft;
			}
			if (hiddenType == BOMB) {
				--bombsLeft;
			}
			total = 0;
		} else if (selectedType != HIDDEN
				&& selectedType != visibleBoard[selectedBox]) {
			if (visibleBoard[selectedBox] == RUPOOR) {
				++rupoorsLeft;
			} else if (visibleBoard[selectedBox] == BOMB) {
				++bombsLeft;
			} else if (visibleBoard[selectedBox] == HIDDEN) {
				int index = 0;
				while (availableBox[index] != selectedBox) {
					++index;
				}
				availableBox[index] = availableBox[availableBoxCount - 1];
				--availableBoxCount;
			}
			if (selectedType == RUPOOR) {
				--rupoorsLeft;
			} else if (selectedType == BOMB) {
				--bombsLeft;
			}
			visibleBoard[selectedBox] = selectedType;
			total = 0;
		}
	} else if (selectedBox >= width * height
			&& selectedBox < width * height + 8) {
		selectedType = (BoxContent) (selectedBox - width * height);
	}
}
void BombSweeper::clear() {
	if (selectedBox >= 0 && selectedBox < width * height) {
		if (visibleBoard[selectedBox] != HIDDEN) {
			++availableBoxCount;
			availableBox[availableBoxCount - 1] = selectedBox;
			if (visibleBoard[selectedBox] == RUPOOR) {
				++rupoorsLeft;
			}
			if (visibleBoard[selectedBox] == BOMB) {
				++bombsLeft;
			}
			visibleBoard[selectedBox] = HIDDEN;
			total = 0;
		}
	}
}

void BombSweeper::resetBoard(int width, int height) {
	this->width = width;
	this->height = height;

	rupoorsLeft = rupoorCount;
	bombsLeft = bombCount;

	delete[] visibleBoard;
	visibleBoard = new BoxContent[width * height];
	for (int k = 0; k < width * height; ++k) {
		visibleBoard[k] = HIDDEN;
	}
	for (int t = 0; t < 7; ++t) {
		delete[] probability[t];
		probability[t] = new double[width * height];
		for (int k = 0; k < width * height; ++k) {
			probability[t][k] = 0;
		}
	}
	total = 0;

	for (int t = 0; t < 7; ++t) {
		delete[] boxCount[t];
		boxCount[t] = new int[width * height];
	}
	delete[] availableBox;
	availableBox = new int[width * height];
	for (int k = 0; k < width * height; ++k) {
		availableBox[k] = k;
	}
	availableBoxCount = width * height;

	delete hiddenBoard;
	hiddenBoard = tryBoardCompletion(visibleBoard, width, height, rupoorCount,
			bombCount);
}

bool BombSweeper::checkSolvedBoard(BoxContent *board, int width, int height) {
	for (int j = 0; j < height; j++) {
		for (int i = 0; i < width; i++) {
			int badNeighboursCount = 0;
			for (int j2 = j - 1; j2 <= j + 1; ++j2) {
				for (int i2 = i - 1; i2 <= i + 1; ++i2) {
					if (i2 >= 0 && i2 < width && j2 >= 0 && j2 < height) {
						if (board[i2 + j2 * width] == RUPOOR
								|| board[i2 + j2 * width] == BOMB) {
							++badNeighboursCount;
						}
					}
				}
			}
			switch (board[i + j * width]) {
			case GREEN_RUPEE:
				if (badNeighboursCount > 0) {
					return false;
				}
				break;
			case BLUE_RUPEE:
				if (badNeighboursCount > 2 || badNeighboursCount < 1) {
					return false;
				}
				break;
			case RED_RUPEE:
				if (badNeighboursCount > 4 || badNeighboursCount < 3) {
					return false;
				}
				break;
			case SILVER_RUPEE:
				if (badNeighboursCount > 6 || badNeighboursCount < 5) {
					return false;
				}
				break;
			case GOLDEN_RUPEE:
				if (badNeighboursCount < 7) {
					return false;
				}
				break;
			}
		}
	}
	return true;
}

void BombSweeper::completeSolvedBoard(BoxContent *board, int width,
		int height) {
	for (int j = 0; j < height; j++) {
		for (int i = 0; i < width; i++) {
			if (board[i + j * width] == HIDDEN) {
				int badNeighboursCount = 0;
				for (int j2 = j - 1; j2 <= j + 1; ++j2) {
					for (int i2 = i - 1; i2 <= i + 1; ++i2) {
						if (i2 >= 0 && i2 < width && j2 >= 0 && j2 < height) {
							if (board[i2 + j2 * width] == RUPOOR
									|| board[i2 + j2 * width] == BOMB) {
								++badNeighboursCount;
							}
						}
					}
				}
				switch (badNeighboursCount) {
				case 0:
					board[i + j * width] = GREEN_RUPEE;
					break;
				case 1:
					board[i + j * width] = BLUE_RUPEE;
					break;
				case 2:
					board[i + j * width] = BLUE_RUPEE;
					break;
				case 3:
					board[i + j * width] = RED_RUPEE;
					break;
				case 4:
					board[i + j * width] = RED_RUPEE;
					break;
				case 5:
					board[i + j * width] = SILVER_RUPEE;
					break;
				case 6:
					board[i + j * width] = SILVER_RUPEE;
					break;
				case 7:
					board[i + j * width] = GOLDEN_RUPEE;
					break;
				case 8:
					board[i + j * width] = GOLDEN_RUPEE;
					break;
				}
			}
		}
	}
}

BoxContent* BombSweeper::tryBoardCompletion(BoxContent *board, int width,
		int height, int rupoorsLeft, int bombsLeft) {
	if (availableBoxCount < rupoorsLeft + bombsLeft || rupoorsLeft < 0
			|| bombsLeft < 0) {
		return nullptr;
	}
	BoxContent *solvedBoard = new BoxContent[width * height];
	int availableCount = availableBoxCount;
	for (int k = 0; k < width * height; ++k) {
		solvedBoard[k] = board[k];
	}
	for (int n = 0; n < rupoorsLeft; ++n) {
		int i = rand() % availableCount;
		solvedBoard[availableBox[i]] = RUPOOR;
		int save = availableBox[i];
		availableBox[i] = availableBox[availableCount - 1];
		availableBox[availableCount - 1] = save;
		--availableCount;
	}
	for (int n = 0; n < bombsLeft; ++n) {
		int i = rand() % availableCount;
		solvedBoard[availableBox[i]] = BOMB;
		int save = availableBox[i];
		availableBox[i] = availableBox[availableCount - 1];
		availableBox[availableCount - 1] = save;
		--availableCount;
	}
	if (checkSolvedBoard(solvedBoard, width, height)) {
		completeSolvedBoard(solvedBoard, width, height);
		return solvedBoard;
	}
	delete solvedBoard;
	return nullptr;
}
