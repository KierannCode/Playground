/*
 * CUDAMandelbrot.cuh
 *
 *  Created on: 12 juil. 2021
 *      Author: Kierann
 */

#ifndef PLAYGROUND_CUDAMANDELBROT
#define PLAYGROUND_CUDAMANDELBROT

#include <cstdint>
#include "../../../Software/04 GPUMandelbrot/CUDA/CUDAComplex.cuh"

void allocateDeviceAttributes(CUDAComplex **d_complex, size_t **d_index, int w, int h);
void freeDeviceAttributes(CUDAComplex *d_complex, size_t *d_index);

int initializeDeviceAttributes(CUDAComplex *d_complex, size_t *d_index, int w, int h);
__global__ void initializeAttributes(CUDAComplex *d_complex, size_t *d_index, int w, int h);

int computeNextIteration(CUDAComplex *d_complex, size_t *d_index, int w, int h, double Ox, double Oy, double scalePerPixel);
__global__ void computeIteration(CUDAComplex *d_complex, size_t *d_index, int w, int h, double Ox, double Oy, double scalePerPixel);

void updateHostIndex(size_t *d_index, size_t *h_index, int w, int h);

#endif /* PLAYGROUND_CUDAMANDELBROT */
