#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define HEIGHT 10

#ifndef Console_Funcion_H_
#define Console_Funcion_H_

void PrintConsole(int size, float *arr, char *str);
void PrintConsoleGraph(int size, float *arr, char *strName);
void PrintConsole2Arr(int size, int measurement, float arr[measurement][size], char *str);

#endif
