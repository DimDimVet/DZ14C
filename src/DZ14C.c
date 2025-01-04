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

	PrintConsoleGraph(size, originalSinus, "Base SinusArr");
	PrintConsoleGraph(size, noiseSinusOne, "Noise SinusArr x1 Measur");


	//
	double **noiseSinus = Creat2Arr(size, MAX_Measurements);
	FillArrNoiseSinus(size, MAX_Measurements, originalSinus, noiseSinus);

	PrintConsole2Arr(size, MAX_Measurements, noiseSinus,
			"Noise SinusArr x10 Measur");


	//PrintConsoleGraph2(size, MAX_Measurements, noiseSinus,"Noise SinusArr x10 Measur");

	double *filterSinus = malloc(size * sizeof(double));
	//FillArrFilterSinus(size, MAX_Measurements, filterSinus, noiseSinus);

	PrintConsole(size, noiseSinusOne, "Filter SinusArr");

	//PrintConsoleGraph(size, filterSinus, "Filter SinusArr");

//
	free(originalSinus);
	free(noiseSinusOne);
	Free2Arr(noiseSinus, MAX_Measurements);

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

double** Creat2Arr(int size, int measurement)
{

	double **tempArr = malloc(measurement * sizeof(double));

	for (int i = 0; i < measurement; i++)
	{
		tempArr[i] = malloc(size * sizeof(int));
	}
	return tempArr;
}

void Free2Arr(double **noiseArr, int measurement)
{

	for (int i = 0; i < measurement; i++)
	{
		free(noiseArr[i]);
	}
	free(noiseArr);
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

void FillArrNoiseSinus(int size, int measurement, double *arr,
		double **noiseArr)
{
	double noiseTemp;

	for (int rows = 0; rows < measurement; rows++)
	{
		for (int cols = 0; cols < size; cols++)
		{
			noiseTemp = (1 + rand() % (10 - 1)) * 0.02;
			noiseArr[rows][cols] = arr[cols] + noiseTemp;
		}
	}
}

//
void FillArrFilterSinus(int size, int measurement, double *arr,
		double **noiseArr)
{
	//double noiseTemp;
	arr=noiseArr[0];
	for (int cols = 0; cols < size; cols++)
	{
		for (int rows = 0; rows < measurement; rows++)
		{
			//arr[cols] = Median(noiseArr[rows], rows);
		}
	}
}

double Median(double *arr, int count)
{
	double median;
	//float *trArr = transformArr(journalWork, count);

	double *tempArr = SequenceData(arr, count);

	if (count % 2 == 0)
	{
		median = (tempArr[count / 2] + arr[count / 2 + 1]) / 2;
	}
	else
	{
		median = tempArr[count / 2 + 1];
	}
	return median;
}

double* SequenceData(double *arr, int count)
{
	int temp;

	for (int i = 0; i < count - 1; i++)
	{
		for (int j = 0; j < count - i - 1; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
	return arr;
}
