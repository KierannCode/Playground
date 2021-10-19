/*
 * GPUMandelbrot.cpp
 *
 *  Created on: 12 juil. 2021
 *      Author: Kierann
 */

#include "GPUMandelbrot.hpp"

#include "../../../Event/EventManager.hpp"
#include "CUDA/CUDAMandelbrot.cuh"

GPUMandelbrot::GPUMandelbrot() {
	Ox = 0;
	Oy = 0;
	scalePerPixel = 0.005;
	d_complex = NULL;
	d_index = NULL;
	h_index = NULL;
	iteration = 0;
}

void GPUMandelbrot::computeNextFrame() {
	/*if (inputs->leftClickDown) {
		Ox += scalePerPixel * (inputs->relativeMouseX - surface->w / 2) * 0.2;
		Oy += scalePerPixel * (surface->h / 2 - inputs->relativeMouseY) * 0.2;
		scalePerPixel *= 0.8;
		initializeDeviceAttributes(d_complex, d_index, surface->w, surface->h);
		iteration = 0;
	}
	if (inputs->rightClickDown) {
		scalePerPixel /= 0.8;
		Ox -= scalePerPixel * (inputs->relativeMouseX - surface->w / 2) * 0.2;
		Oy -= scalePerPixel * (surface->h / 2 - inputs->relativeMouseY) * 0.2;
		initializeDeviceAttributes(d_complex, d_index, surface->w, surface->h);
		iteration = 0;
	}
	computeNextIteration(d_complex, d_index, surface->w, surface->h, Ox, Oy,
			scalePerPixel);
	++iteration;
	*/
}
void GPUMandelbrot::renderCurrentFrame() {
	/*if (iteration >= 20) {
		updateHostIndex(d_index, h_index, surface->w, surface->h);
		for (int j = 0; j < surface->h; j++) {
			for (int i = 0; i < surface->w; i++) {
				*((Uint32*) surface->pixels + j * surface->w + i) = SDL_MapRGB(
						surface->format,
						255 - 10 * (h_index[j * surface->w + i] % 25), 0, 0);
				if (h_index[j * surface->w + i] >= iteration - 2) {
					*((Uint32*) surface->pixels + j * surface->w + i) =
							SDL_MapRGB(surface->format, 0, 0, 0);
				}
			}
		}
	}*/
}

GPUMandelbrot::~GPUMandelbrot() {

}
