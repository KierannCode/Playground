/*
 * GameOfLife.cpp
 *
 *  Created on: 9 juil. 2021
 *      Author: Kierann
 */

#include "GameOfLife.hpp"

#include <stdlib.h>
#include <time.h>

#include "../../../Event/EventManager.hpp"

GameOfLife::GameOfLife() {
	width = 200;
	height = 125;
	generation = 0;
	speed = 30;
	currentBoardState = new BoardState;
	nextBoardState = new BoardState;
	currentBoardState->cellState = new bool[width * height];
	nextBoardState->cellState = new bool[width * height];
	for (int k = 0; k < width * height; ++k) {
		currentBoardState->cellState[k] = false;
	}
	neighboursCount = new int[width * height];
}

void GameOfLife::prepareNextFrame() {
	/*if (!inputs->windowEvent) {
		for (int k = 0; k < width * height; ++k) {
			nextBoardState->cellState[k] = currentBoardState->cellState[k];
		}
		while (frame * speed >= (generation + 1) * framerate) {
			for (int k = 0; k < width * height; ++k) {
				neighboursCount[k] = 0;
			}
			for (int j = 0; j < height; ++j) {
				for (int i = 0; i < width; ++i) {
					if (nextBoardState->cellState[i + j * width]) {
						for (int j2 = j - 1; j2 <= j + 1; j2++) {
							for (int i2 = i - 1; i2 <= i + 1; i2++) {
								if (i2 >= 0 && i2 < width && j2 >= 0
										&& j2 < height
										&& (i2 != i || j2 != j)) {
									++neighboursCount[i2 + j2 * width];
								}
							}
						}
					}
				}
			}
			for (int j = 0; j < height; ++j) {
				for (int i = 0; i < width; ++i) {
					if (nextBoardState->cellState[i + j * width]) {
						if (neighboursCount[i + j * width] <= 1
								|| neighboursCount[i + j * width] >= 4) {
							nextBoardState->cellState[i + j * width] = false;
						}
					} else {
						if (neighboursCount[i + j * width] == 3) {
							nextBoardState->cellState[i + j * width] = true;
						}
					}
				}
			}
			++generation;
		}
		if (inputs->leftClickDown) {
			int i = width * inputs->relativeMouseX / surface->w;
			int j = height * inputs->relativeMouseY / surface->h;
			for (int j2 = j - 1; j2 <= j + 1; j2++) {
				for (int i2 = i - 1; i2 <= i + 1; i2++) {
					if (i2 >= 0 && i2 < width && j2 >= 0 && j2 < height) {
						nextBoardState->cellState[i2 + j2 * width] = true;
					}
				}
			}
		}
		++frame;
	}*/
}

void GameOfLife::updateCurrentFrame() {
	BoardState *currentState = currentBoardState;
	currentBoardState = nextBoardState;
	nextBoardState = currentState;
}

void GameOfLife::renderCurrentFrame() {
	/*SDL_Rect tile;
	for (int j = 0; j < height; j++) {
		for (int i = 0; i < width; i++) {
			tile.w = ((i + 1) * surface->w / width) - (i * surface->w / width);
			tile.h = ((j + 1) * surface->h / height)
					- (j * surface->h / height);
			tile.x = i * surface->w / width;
			tile.y = j * surface->h / height;
			if (currentBoardState->cellState[i + j * width]) {
				SDL_FillRect(surface, &tile,
						SDL_MapRGB(surface->format, 255, 255, 0));
			} else {
				SDL_FillRect(surface, &tile,
						SDL_MapRGB(surface->format,
								((i + j) % 2) * 100 + ((i + j + 1) % 2) * 120,
								((i + j) % 2) * 100 + ((i + j + 1) % 2) * 120,
								((i + j) % 2) * 100 + ((i + j + 1) % 2) * 120));
			}
		}
	}*/
}

GameOfLife::~GameOfLife() {
	delete neighboursCount;
	delete nextBoardState->cellState;
	delete currentBoardState->cellState;
	delete nextBoardState;
	delete currentBoardState;
}
