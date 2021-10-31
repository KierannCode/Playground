/*
 * CUDAComplex.cuh
 *
 *  Created on: 12 juil. 2021
 *      Author: Kierann
 */

#ifndef PLAYGROUND_CUDACOMPLEX
#define PLAYGROUND_CUDACOMPLEX

#include <device_launch_parameters.h>

class CUDAComplex {
private:
	double re;
	double im;
public:
	__device__ CUDAComplex();
	__device__ CUDAComplex(double re, double im);
	__device__ CUDAComplex(const CUDAComplex &z);
	__device__ CUDAComplex& operator=(const CUDAComplex &z);

	__device__ CUDAComplex operator+(const CUDAComplex &z) const;
	__device__ CUDAComplex& operator+=(const CUDAComplex &z);

	__device__ CUDAComplex operator-(const CUDAComplex &z) const;
	__device__ CUDAComplex& operator-=(const CUDAComplex &z);

	__device__ CUDAComplex operator*(const CUDAComplex &z) const;
	__device__ CUDAComplex& operator*=(const CUDAComplex &z);

	__device__ double mod2() const;
};

#endif /* PLAYGROUND_CUDACOMPLEX */
