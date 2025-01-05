#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <string.h>
#include <stdbool.h>
#include "ConsoleFuncion.h"

#ifndef DZ14C_H_
#define DZ14C_H_

#define MAX_Measurements 10

int WriteSize();
void FillArrSinus(int size, float *arr);
void FillArrNoiseSinusOne(int size, float *arr, float *noiseArr);
void Free2Arr(int measurement, float (*noiseArr)[measurement]);
void FillArrNoiseSinus(int size, int measurement, float *arr, float noiseArr[measurement][size]);
void FillArrFilterSinus(int size, int measurement, float *arr, float noiseArr[measurement][size]);

#endif
