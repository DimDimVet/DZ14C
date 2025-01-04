#include "DZ14C.h"

int main()
{
	int size = WriteSize();

	double *originalSinus = malloc(size * sizeof(double));

	FillArrSinus(size, originalSinus);

	srand(time(0));

	double *noiseSinusOne = malloc(size * sizeof(double));

	FillArrNoiseSinusOne(size, originalSinus, noiseSinusOne);
//
	PrintConsole(size, originalSinus, "Base SinusArr");
	PrintConsole(size, noiseSinusOne, "Noise SinusArr x1 Measur");

	PrintConsoleGraph(size, originalSinus,"Base SinusArr");
	PrintConsoleGraph(size, noiseSinusOne,"Noise SinusArr x1 Measur");

	free(originalSinus);
	free(noiseSinusOne);
	//
	double **noiseSinus=Creat2Arr(size, MAX_Measurements);
	FillArrNoiseSinus(size, MAX_Measurements,originalSinus,noiseSinus);

	PrintConsole2Arr(size, MAX_Measurements, noiseSinus, "Noise SinusArr x10 Measur");
	PrintConsoleGraph2(size, MAX_Measurements, noiseSinus, "Noise SinusArr x10 Measur");
	return 0;
}

int WriteSize()
{
	int tempSize;
	printf("Write size arr: ");
	scanf("%d", &tempSize);

	if (tempSize <= 0)
	{
		printf("Error size arr\n ");
		WriteSize();
	}

	return tempSize;
}

double ** Creat2Arr(int size, int measurement)
{

		double **tempArr = malloc(measurement * sizeof(double));

		for (int i = 0; i < measurement; i++)
		{
			tempArr[i] = malloc(size * sizeof(int));
		}
		return tempArr;
}

void FillArrSinus(int size, double *arr)
{
	double temp;
	for (int i = 0; i < size; i++)
	{
		temp = (double) i / size * 2 * M_PI;
		arr[i] = sin(temp);
	}
}

void FillArrNoiseSinusOne(int size, double *arr, double *noiseArrOne)
{
	double noiseTemp;
	for (int i = 0; i < size; i++)
	{
		noiseTemp = (1 + rand() % (10 - 1)) * 0.02;
		noiseArrOne[i] = arr[i] + noiseTemp;
	}
}

void FillArrNoiseSinus(int size, int measurement,double *arr,double **noiseArr)
{
	for (int i = 0; i < MAX_Measurements; i++)
		{
			FillArrNoiseSinusOne(size, arr, noiseArr[i]);
		}
}
