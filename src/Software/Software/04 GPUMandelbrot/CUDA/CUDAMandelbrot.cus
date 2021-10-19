/*
 * CUDAMandelbrot.cus
 *
 *  Created on: 18 juil. 2021
 *      Author: Kierann
 */

#ifndef SRC_SOFTWARE_04_GPUMANDELBROT_CUDA_CUDAMANDELBROT_CUS_
#define SRC_SOFTWARE_04_GPUMANDELBROT_CUDA_CUDAMANDELBROT_CUS_

#include "CUDAMandelbrot.cuh"

#include <cuda_runtime.h>

void allocateDeviceAttributes(CUDAComplex **d_complex, size_t **d_index, int w,
		int h) {
	cudaMalloc(d_complex, w * h * sizeof(CUDAComplex));
	cudaMalloc(d_index, w * h * sizeof(size_t));
}

void freeDeviceAttributes(CUDAComplex *d_complex, size_t *d_index) {
	cudaFree(d_complex);
	cudaFree(d_index);
}

int initializeDeviceAttributes(CUDAComplex *d_complex, size_t *d_index, int w,
		int h) {
	size_t block_size = 16;
	dim3 threads(block_size, block_size);
	dim3 grid((w + block_size - 1) / block_size,
			(h + block_size - 1) / block_size);
	initializeAttributes<<<grid, threads>>>(d_complex, d_index, w, h);
	return 0;
}

__global__ void initializeAttributes(CUDAComplex *d_complex, size_t *d_index,
		int w, int h) {
	int i = blockDim.x * blockIdx.x + threadIdx.x;
	int j = blockDim.y * blockIdx.y + threadIdx.y;
	if (i < w && j < h) {
		d_complex[i + j * w] = CUDAComplex(0, 0);
		d_index[i + j * w] = 0;
	}
}

int computeNextIteration(CUDAComplex *d_complex, size_t *d_index, int w, int h,
		double Ox, double Oy, double scalePerPixel) {
	size_t block_size = 16;
	dim3 threads(block_size, block_size);
	dim3 grid((w + block_size - 1) / block_size,
			(h + block_size - 1) / block_size);
	computeIteration<<<grid, threads>>>(d_complex, d_index, w, h, Ox, Oy, scalePerPixel);
	return 0;
}
__global__ void computeIteration(CUDAComplex *d_complex, size_t *d_index, int w,
		int h, double Ox, double Oy, double scalePerPixel) {
	int i = blockDim.x * blockIdx.x + threadIdx.x;
	int j = blockDim.y * blockIdx.y + threadIdx.y;
	if (i < w && j < h && d_complex[i + j * w].mod2() <= 4) {
		CUDAComplex c((i - 1.0 * w / 2) * scalePerPixel + Ox,
				(1.0 * h / 2 - j) * scalePerPixel + Oy);
		d_complex[i + j * w] = d_complex[i + j * w] * d_complex[i + j * w] + c;
		d_index[i + j * w]++;
	}
}

void updateHostIndex(size_t *d_index, size_t *h_index, int w, int h) {
	cudaMemcpy(h_index, d_index, w * h * sizeof(size_t),
			cudaMemcpyDeviceToHost);
}

#endif /* SRC_SOFTWARE_04_GPUMANDELBROT_CUDA_CUDAMANDELBROT_CUS_ */
