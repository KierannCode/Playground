/*
 * GPUMandelbrot.hpp
 *
 *  Created on: 12 juil. 2021
 *      Author: Kierann
 */

#ifndef PLAYGROUND_GPUMANDELBROT
#define PLAYGROUND_GPUMANDELBROT

#include "CUDA/CUDAComplex.cuh"
#include "../../Software.hpp"


class GPUMandelbrot: public Software {
private:
	double Ox; //w/2 sur la surface correspond à Ox
	double Oy; //h/2 sur la surface correspond à Oy
	double scalePerPixel;
	CUDAComplex *d_complex;
	size_t *d_index;
	size_t *h_index;
	size_t iteration;
public:
	GPUMandelbrot();
	void computeNextFrame();
	void renderCurrentFrame();
	~GPUMandelbrot();
};

#endif /* PLAYGROUND_GPUMANDELBROT */
