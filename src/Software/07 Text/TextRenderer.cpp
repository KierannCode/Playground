/*
 * TextRenderer.cpp
 *
 *  Created on: 5 sept. 2021
 *      Author: Kierann
 */

#include "TextRenderer.hpp"

#include "../../OSDL/Video/Surface.hpp"
#include "../../OSDL/Video/Color.hpp"

#include "../../OSDL/Time/Timer.hpp"

TextRenderer::TextRenderer() {
	size = 3;
	x = new int[size];
	y = new int[size];
	x[0] = 400;
	y[0] = 400;
	x[1] = x[0];
	y[1] = y[0];
	x[2] = x[0];
	y[2] = y[0];
}

void drawPoint(OSDL::Surface *surface, int x, int y, int radius) {
	for (int k = -radius; k <= radius; ++k) {
		surface->fillDisk(x, y, radius, OSDL::Color(255,0,0));
	}
}

void TextRenderer::render(OSDL::Surface *surface) {
	surface->fill(OSDL::Color(255, 255, 255));
	/*int oldX = x[0];
	int oldY = y[0];
	pixels[oldX + surface->w * oldY] = 0;
	int *binom = new int[size];
	binom[0] = 1;
	for (int i = 1; i < size; ++i) {
		binom[i] = (size - i) * binom[i - 1] / i;
	}
	int *dx = new int[surface->w * surface->h];
	for (int k = 0; k < surface->w * surface->h; ++k) {
		dx[k] = 0;
	}
	int minX = surface->w - 1;
	int maxX = 0;
	int minY = surface->h - 1;
	int maxY = 0;
	double dt = 0.1 / ((size - 1) * maxAbs(x[1] - x[0], y[1] - y[0]));
	double t = dt;
	while (t < 1) {
		double conjTl = 1 - t;
		double xM = 0;
		double yM = 0;
		double dxM = 0;
		double dyM = 0;
		double tc = 1;
		for (int i = 1; i < size; ++i) {
			tc *= conjTl;
		}
		double dtc = -(size - 1) * tc / conjTl;
		for (int i = 0; i < size; ++i) {
			xM += binom[i] * tc * x[i];
			yM += binom[i] * tc * y[i];
			dxM += binom[i] * dtc * x[i];
			dyM += binom[i] * dtc * y[i];
			dtc *= (t / conjTl);
			dtc += tc / (conjTl * conjTl);
			tc *= (t / conjTl);
		}
		if (round2(xM) > oldX) {
			++dx[oldX + surface->w * oldY];
			++dx[round2(xM) + surface->w * round2(yM)];
			for (int i = oldX + 1; i < round2(xM); ++i) {
				dx[i + surface->w * oldY] += 2;
			}
		} else if (round2(xM) < oldX) {
			--dx[oldX + surface->w * oldY];
			--dx[round2(xM) + surface->w * round2(yM)];
			for (int i = round2(xM) + 1; i < oldX; ++i) {
				dx[i + surface->w * oldY] -= 2;
			}
		}
		for (int i = floor2(xM); i <= ceil2(xM); ++i) {
			for (int j = floor2(yM); j <= ceil2(yM); ++j) {
				unsigned int delta = ((int) (256 * (1 - abs2(xM - i))
						* (1 - abs2(yM - j)))) * (1 + 256 + 256 * 256);
				if (pixels[i + surface->w * j] >= delta) {
					pixels[i + surface->w * j] -= delta;
				} else {
					pixels[i + surface->w * j] = 0;
				}
			}
		}
		oldX = round2(xM);
		oldY = round2(yM);
		if (xM < minX) {
			minX = xM;
		}
		if (xM > maxX) {
			maxX = xM;
		}
		if (yM < minY) {
			minY = yM;
		}
		if (yM > maxY) {
			maxY = yM;
		}
		t += min2(dt, 0.1 / maxAbs(dxM, dyM));
		dt = 0.1 / maxAbs(dxM, dyM);
	}

	double xM = x[size - 1];
	double yM = y[size - 1];
	if (round2(xM) > oldX) {
		++dx[oldX + surface->w * oldY];
		++dx[round2(xM) + surface->w * round2(yM)];
		for (int i = oldX + 1; i < round2(xM); ++i) {
			dx[i + surface->w * oldY] += 2;
		}
	} else if (round2(xM) < oldX) {
		--dx[oldX + surface->w * oldY];
		--dx[round2(xM) + surface->w * round2(yM)];
		for (int i = round2(xM) + 1; i < oldX; ++i) {
			dx[i + surface->w * oldY] -= 2;
		}
	}
	for (int i = floor2(xM); i <= ceil2(xM); ++i) {
		for (int j = floor2(yM); j <= ceil2(yM); ++j) {
			unsigned int delta = ((int) (256 * (1 - abs2(xM - i))
					* (1 - abs2(yM - j)))) * (1 + 256 + 256 * 256);
			if (pixels[i + surface->w * j] >= delta) {
				pixels[i + surface->w * j] -= delta;
			} else {
				pixels[i + surface->w * j] = 0;
			}
		}
	}
	if (xM < minX) {
		minX = xM;
	}
	if (xM > maxX) {
		maxX = xM;
	}
	if (yM < minY) {
		minY = yM;
	}
	if (yM > maxY) {
		maxY = yM;
	}
	for (int i = minX; i <= maxX; ++i) {
		int cdx = 0;
		for (int j = minY; j <= maxY; ++j) {
			if (dx[i + surface->w * j] == 0) {
				if (cdx != 0) {
					if (cdx % 2 == 0) {
						int R = floor2(cdx * 13.41) % 256;
						int G = floor2(cdx * 451.421) % 256;
						int B = floor2(cdx * 51.421) % 256;
						pixels[i + surface->w * j] = B + 256 * G
								+ 256 * 256 * R;
					} else {
						pixels[i + surface->w * j] = 0;
					}
				}
			} else {
				cdx += dx[i + surface->w * j];
				pixels[i + surface->w * j] = 0;
			}
		}
	}
	delete dx;
	delete binom;
	for (int i = 0; i < size - 1; ++i) {
		drawPoint(surface, x[i], y[i], 5);
	}*/
}

TextRenderer::~TextRenderer() {
	delete y;
	delete x;
}
