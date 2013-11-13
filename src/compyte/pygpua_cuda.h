/*
 * This file isn't recommanded. Using it make your code not able to work on OpenCL.
 *
 * But it allow faster conversion to this new library of existing code
 */
#include "extension.h"
#ifndef COMPYTE_BUFFER_CUDA_H
#define COMPYTE_BUFFER_CUDA_H
CUdeviceptr (*cuda_get_ptr)(gpudata *g) = (CUdeviceptr (*)(gpudata *g))compyte_get_extension("cuda_get_ptr");

int PyGpuArray_NDIM(PyGpuArrayObject *arr) {
  return arr->ga.nd;
}
size_t *PyGpuArray_DIMS(PyGpuArrayObject *arr) {
  return arr->ga.dimensions;
}
//void *PyGpuArray_DATA(PyGpuArrayObject *arr)
char *PyGpuArray_BYTES(PyGpuArrayObject *arr){
  return ((char*) cuda_get_ptr(arr->ga.data)) + arr->ga.offset;
}

ssize_t *PyGpuArray_STRIDES(PyGpuArrayObject* arr) {
  return arr->ga.strides;
}
size_t PyGpuArray_DIM(PyGpuArrayObject* arr, int n) {
  return arr->ga.dimensions[n];
}
ssize_t PyGpuArray_STRIDE(PyGpuArrayObject* arr, int n) {
  return arr->ga.strides[n];
}
//int PyGpuArray_ITEMSIZE(PyGpuArrayObject* arr)
size_t PyGpuArray_SIZE(PyGpuArrayObject* arr) {
  size_t size = 1;
  for(int i=0; i< arr->ga.nd; i++) {
    size *= arr->ga.dimensions[i];
  }
  return size;
}

#endif
