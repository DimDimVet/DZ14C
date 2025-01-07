#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define HEIGHT 10

#ifndef Console_Funcion_H_
#define Console_Funcion_H_

void PrintConsole(int size, float *arr, char *str);
void PrintConsoleGraph(int size, float *arr, char *strName);
void PrintConsole2Arr(int size, int measurement, float arr[measurement][size], char *str);
void PrintTxtFile(FILE *file, int size, float *arr, char *strName);
void PrintGrafFile(FILE *file, int size, float *arr, char *strName);
void PrintTxtFile2Arr(FILE *file, int size, int measurement, float arr[measurement][size], char *str);
FILE * OpenFile(char *nameFile);
void CloseFile(char *nameFile,FILE *file);

#endif
