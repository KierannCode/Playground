/*
 * CUDAComplex.cus
 *
 *  Created on: 18 juil. 2021
 *      Author: Kierann
 */

#ifndef SRC_SOFTWARE_04_GPUMANDELBROT_CUDA_CUDACOMPLEX_CUS_
#define SRC_SOFTWARE_04_GPUMANDELBROT_CUDA_CUDACOMPLEX_CUS_

#include "CUDAComplex.cuh"

__device__ CUDAComplex::CUDAComplex() {
	re = 0;
	im = 0;
}
__device__ CUDAComplex::CUDAComplex(double re, double im) {
	this->re = re;
	this->im = im;
}
__device__ CUDAComplex::CUDAComplex(const CUDAComplex &z) {
	re = z.re;
	im = z.im;
}
__device__ CUDAComplex& CUDAComplex::operator=(const CUDAComplex &z) {
	re = z.re;
	im = z.im;
	return *this;
}

__device__ CUDAComplex CUDAComplex::operator+(const CUDAComplex &z) const {
	CUDAComplex sum;
	sum.re = re + z.re;
	sum.im = im + z.im;
	return sum;
}
__device__ CUDAComplex& CUDAComplex::operator+=(const CUDAComplex &z) {
	re += z.re;
	im += z.im;
	return *this;
}

__device__ CUDAComplex CUDAComplex::operator-(const CUDAComplex &z) const {
	CUDAComplex difference;
	difference.re = re - z.re;
	difference.im = im - z.im;
	return difference;
}
__device__ CUDAComplex& CUDAComplex::operator-=(const CUDAComplex &z) {
	re -= z.re;
	im -= z.im;
	return *this;
}

__device__ CUDAComplex CUDAComplex::operator*(const CUDAComplex &z) const {
	CUDAComplex product;
	product.re = re * z.re - im * z.im;
	product.im = re * z.im + z.re * im;
	return product;
}
__device__ CUDAComplex& CUDAComplex::operator*=(const CUDAComplex &z) {
	*this = *this * z;
	return *this;
}

__device__ double CUDAComplex::mod2() const {
	return re * re + im * im;
}

#endif /* SRC_SOFTWARE_04_GPUMANDELBROT_CUDA_CUDACOMPLEX_CUS_ */
