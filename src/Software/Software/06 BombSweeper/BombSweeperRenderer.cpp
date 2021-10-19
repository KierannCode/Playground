/*
 * BombSweeperRenderer.cpp
 *
 *  Created on: 10 août 2021
 *      Author: Kierann
 */

#include "BombSweeperRenderer.hpp"

#include "../../../OSDL/Resilience/Log.hpp"

#include "../../../OSDL/Video/Surface.hpp"
#include "../../../OSDL/Video/Color.hpp"

BombSweeperRenderer::BombSweeperRenderer(int width, int height, int rupoorCount,
		int bombCount) {
	this->width = width;
	this->height = height;
	this->rupoorCount = rupoorCount;
	this->bombCount = bombCount;

	rupoorsLeft = rupoorCount;
	bombsLeft = bombCount;
	board = new BoxContent[width * height];
	for (int k = 0; k < width * height; ++k) {
		board[k] = HIDDEN;
	}

	probability = new double*[7];
	for (int t = 0; t < 7; ++t) {
		probability[t] = new double[width * height];
		for (int k = 0; k < width * height; ++k) {
			probability[t][k] = 0;
		}
	}

	selectedBox = -1;

	selectedType = HIDDEN;

	contentImage = new OSDL::Surface*[7];

	contentImage[GREEN_RUPEE] = new OSDL::Surface(
			"Ressources\\BombSweeper\\GREEN RUPEE.bmp");
	contentImage[BLUE_RUPEE] = new OSDL::Surface(
			"Ressources\\BombSweeper\\BLUE RUPEE.bmp");
	contentImage[RED_RUPEE] = new OSDL::Surface(
			"Ressources\\BombSweeper\\RED RUPEE.bmp");
	contentImage[SILVER_RUPEE] = new OSDL::Surface(
			"Ressources\\BombSweeper\\SILVER RUPEE.bmp");
	contentImage[GOLDEN_RUPEE] = new OSDL::Surface(
			"Ressources\\BombSweeper\\GOLDEN RUPEE.bmp");
	contentImage[RUPOOR] = new OSDL::Surface(
			"Ressources\\BombSweeper\\RUPOOR.bmp");
	contentImage[BOMB] = new OSDL::Surface("Ressources\\BombSweeper\\BOMB.bmp");

	for (int i = 0; i < 7; i++) {
		contentImage[i]->setAlphaKey(OSDL::Color(0, 255, 0));
	}
}

void BombSweeperRenderer::render(OSDL::Surface *surface) {
	OSDL::Size surfaceWidth = surface->getWidth();
	OSDL::Size surfaceHeight = surface->getHeight();
	surface->fill(OSDL::Color(58, 67, 71));
	double min = 1;
	for (int i = 0; i < width; ++i) {
		for (int j = 0; j < height; ++j) {
			if (board[i + j * width] == HIDDEN) {
				if (probability[BOMB][i + j * width] < min) {
					min = probability[BOMB][i + j * width];
				}
			}
		}
	}
	double *expected = new double[width * height];
	double maxExpected = 0;
	double bestExpected = 0;
	for (int j = 0; j < height; ++j) {
		for (int i = 0; i < width; ++i) {
			if (board[i + j * width] == HIDDEN) {
				expected[i + j * width] =
						probability[GREEN_RUPEE][i + j * width]
								+ 5 * probability[BLUE_RUPEE][i + j * width]
								+ 20 * probability[RED_RUPEE][i + j * width]
								+ 100 * probability[SILVER_RUPEE][i + j * width]
								+ 300 * probability[GOLDEN_RUPEE][i + j * width]
								- 10 * probability[RUPOOR][i + j * width];
				if (expected[i + j * width] > maxExpected) {
					maxExpected = expected[i + j * width];
				}
				if (probability[BOMB][i + j * width] <= min + 0.01
						&& expected[i + j * width] > bestExpected) {
					bestExpected = expected[i + j * width];
				}
			}
		}
	}
	for (int i = 0; i < width; ++i) {
		float x = 4 * (2 * i + 1) * surfaceWidth / (9.0 * width) - 32;
		for (int j = 0; j < height; ++j) {
			float y = (2 * j + 1) * surfaceHeight / (2.0 * (height + 2)) - 32;
			double p = probability[BOMB][i + j * width];
			if (board[i + j * width] == HIDDEN) {
				if (p <= min + 0.01
						&& expected[i + j * width] / bestExpected >= 0.95) {
					surface->fillRect(x, y, 64, 64, OSDL::Color(255, 255, 255));
				} else {
					surface->fillRect(x, y, 64, 64,
							getExpectancyColor(
									expected[i + j * width] / maxExpected));
				}
				surface->fillDisk(x + 22, y + 32, 20, OSDL::Color(0, 0, 0));
				if (rupoorsLeft + bombsLeft > 0) {
					surface->fillDisk(x + 22, y + 32,
							20 * p,
							getRiskColor(p));
				}
				surface->fillRect(x + 46, y + 2, 16, 60, OSDL::Color(0, 0, 0));
				float minibarX = x + 49;
				float minibarY = y + 5;
				for (BoxContent type = GOLDEN_RUPEE; type >= GREEN_RUPEE;
						--(int&) type) {
					float minibarHeight = 54 * probability[type][i + j * width];
					surface->fillRect(minibarX, minibarY, 10, minibarHeight,
							getRupeeColor(type));
					minibarY += minibarHeight;
				}
			} else {
				surface->fillRect(x, y, 64, 64, OSDL::Color(100, 200, 100));
				contentImage[board[i + j * width]]->blit(surface, x, y);
			}
		}
	}
	float y = (2 * height + 3) * surfaceHeight / (2.0 * (height + 2)) - 32;
	for (int type = 0; type < 8; ++type) {
		float x = (2 * type + 1) * surfaceWidth / 18.0 - 32;
		if (type == selectedType) {
			surface->fillRect(x, y, 64, 64, OSDL::Color(100, 100, 255));
		} else {
			surface->fillRect(x, y, 64, 64, OSDL::Color(100, 200, 100));
		}
		if (type < HIDDEN) {
			contentImage[type]->blit(surface, x, y);
		}
	}
	delete expected;
	surface->fillRect(8.5 * surfaceWidth / 9 - 16, 12, 40, surfaceHeight - 26,
			OSDL::Color(0, 0, 0));
	if (selectedBox >= 0 && selectedBox < width * height) {
		float barX = 8.5 * surfaceWidth / 9 - 12;
		float barY = 16;
		int totalHeight = surfaceHeight - 32;
		for (BoxContent type = GOLDEN_RUPEE; type >= GREEN_RUPEE;
				--(int&) type) {
			float barHeight = totalHeight * probability[type][selectedBox];
			surface->fillRect(barX, barY, 32, barHeight, getRupeeColor(type));
			barY += barHeight;
		}
		float barHeight = totalHeight * probability[RUPOOR][selectedBox];
		surface->fillRect(barX, barY, 32, barHeight, getRupeeColor(RUPOOR));
	}
}

BombSweeperRenderer::~BombSweeperRenderer() {
	for (int t = 0; t < 7; ++t) {
		delete contentImage[t];
	}
	delete[] contentImage;

	for (int t = 0; t < 7; ++t) {
		delete[] probability[t];
	}
	delete[] probability;

	delete[] board;
}

OSDL::Color BombSweeperRenderer::getRupeeColor(BoxContent type) {
	switch (type) {
	case GREEN_RUPEE:
		return OSDL::Color(0, 255, 0);
		break;
	case BLUE_RUPEE:
		return OSDL::Color(0, 0, 255);
		break;
	case RED_RUPEE:
		return OSDL::Color(255, 0, 0);
		break;
	case SILVER_RUPEE:
		return OSDL::Color(192, 192, 192);
		break;
	case GOLDEN_RUPEE:
		return OSDL::Color(255, 192, 0);
		break;
	case RUPOOR:
		return OSDL::Color(32, 32, 32);
		break;
	}
	return OSDL::Color(255, 255, 255);
}

OSDL::Color BombSweeperRenderer::getRiskColor(double probability) {
	if (probability < 0.5) {
		return OSDL::Color(probability * 510, (1 - probability) * 255, 0);
	}
	return OSDL::Color(255, (1 - probability) * 255, 0);
}
OSDL::Color BombSweeperRenderer::getExpectancyColor(double rate) {
	if (rate <= 0) {
		return OSDL::Color(0, 0, 0);
	}
	if (rate <= 0.2) {
		return OSDL::Color(0, rate * 1275, 0);
	} else if (rate <= 0.4) {
		return OSDL::Color(0, 510 - rate * 1275, (rate - 0.2) * 1275);
	} else if (rate <= 0.6) {
		return OSDL::Color((rate - 0.4) * 1275, 0, 765 - rate * 1275);
	} else if (rate <= 0.8) {
		return OSDL::Color(444 - 315 * rate, 960 * rate - 576, 960 * rate - 576);
	} else if (rate <= 1) {
		return OSDL::Color(315 * rate - 60, 192, 960 - 960 * rate);
	} else {
		return OSDL::Color(255, 192, 0);
	}
}
