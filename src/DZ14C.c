#include "DZ14C.h"

int main()
{
	int size = WriteSize();

	double *originalSinus = malloc(size * sizeof(double));

	FillArrSinus(size, originalSinus);

	srand(time(0));

	double *noiseSinus = malloc(size * sizeof(double));

	FillArrNoiseSinus(size, originalSinus, noiseSinus);

	PrintConsole(size, originalSinus, "Base SinusArr");
	PrintConsole(size, noiseSinus, "Noise SinusArr");

	PrintConsoleGraph(size, originalSinus,"Base SinusArr");
	PrintConsoleGraph(size, noiseSinus,"Noise SinusArr");

	free(originalSinus);
	free(noiseSinus);
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

void FillArrSinus(int size, double *arr)
{
	double temp;
	for (int i = 0; i < size; i++)
	{
		temp = (double) i / size * 2 * M_PI;
		arr[i] = sin(temp);
	}
}

void FillArrNoiseSinus(int size, double *arr, double *noiseArr)
{
	double noiseTemp;
	for (int i = 0; i < size; i++)
	{
		noiseTemp = (1 + rand() % (10 - 1)) * 0.02;
		noiseArr[i] = arr[i] + noiseTemp;
	}
}

