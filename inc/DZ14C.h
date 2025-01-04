#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <string.h>
#include <stdbool.h>
#include "ConsoleFuncion.h"

#ifndef DZ14C_H_
#define DZ14C_H_

#define MAX_Measurements 2

int WriteSize();
void FillArrSinus(int size, double *arr);
void FillArrNoiseSinusOne(int size, double *arr, double *noiseArr);
double ** Creat2Arr(int size, int measurement);
void FillArrNoiseSinus(int size, int measurement,double *arr,double **noiseArr);

#endif
