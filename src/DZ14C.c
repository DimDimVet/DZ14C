#include "DZ14C.h"

int main()
{
    int size = WriteSize();//получим длинну одном.массива

    float *originalSinus = malloc(size * sizeof(float));//зададим через указатель массив расчетный

    FillArrSinus(size, originalSinus);//наполним массив расчетно

    srand(time(0));

    float *noiseSinusOne = malloc(size * sizeof(float));//зададим через указатель массив рандомный

    FillArrNoiseSinusOne(size, originalSinus, noiseSinusOne);//наполним массив рандомно относительно расчетного

    PrintConsole(size, originalSinus, "Base SinusArr");//покажем
    PrintConsole(size, noiseSinusOne, "Noise SinusArr x1 Measur");//покажем

    PrintConsoleGraph(size, originalSinus, "Base SinusArr");//покажем
    PrintConsoleGraph(size, noiseSinusOne, "Noise SinusArr x1 Measur");//покажем

    float noiseSinus[MAX_Measurements][size];//объявим двумерный массив

    FillArrNoiseSinus(size, MAX_Measurements, originalSinus, noiseSinus);//наполним двумерный массив (количество "измерений") рандомно относительно расчетного

    PrintConsole2Arr(size, MAX_Measurements, noiseSinus, "Noise SinusArr x10 Measur");//покажем

    float *filterSinus = malloc(size * sizeof(float));//зададим через указатель массив отфильтрованого

    FillArrFilterSinus(size, MAX_Measurements, filterSinus, noiseSinus);//наполним массив по средней относительно двумерный массива

    PrintConsole(size, filterSinus, "Filter SinusArr");//покажем
    PrintConsoleGraph(size, filterSinus, "Filter SinusArr");//покажем

    //чистим
    free(originalSinus);
    free(noiseSinusOne);
    Free2Arr(MAX_Measurements, noiseSinus);
    free(filterSinus);

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

void Free2Arr(int measurement, float (*noiseArr)[measurement])
{

    for (int i = 0; i < measurement; i++)
    {
        free(noiseArr[i]);
    }
    free(noiseArr);
}

void FillArrSinus(int size, float *arr)
{
    float temp;
    for (int i = 0; i < size; i++)
    {
        temp = (float)i / size * 2 * M_PI;
        arr[i] = sin(temp);
    }
}

void FillArrNoiseSinusOne(int size, float *arr, float *noiseArrOne)
{
    float noiseTemp;
    for (int i = 0; i < size; i++)
    {
        noiseTemp = (1 + rand() % (10 - 1)) * 0.01;
        noiseArrOne[i] = arr[i] + noiseTemp;
    }
}

void FillArrNoiseSinus(int size, int measurement, float *arr, float noiseArr[measurement][size])
{
    for (int rows = 0; rows < measurement; rows++)
    {
        FillArrNoiseSinusOne(size, arr, noiseArr[rows]);
    }
}

void FillArrFilterSinus(int size, int measurement, float *arr, float noiseArr[measurement][size])
{
    double noiseTemp = 0;

    for (int cols = 0; cols < size; cols++)
    {
        for (int rows = 0; rows < measurement; rows++)
        {
            noiseTemp += noiseArr[rows][cols];
        }

        noiseTemp = (noiseTemp / measurement);
        arr[cols] = noiseTemp;
        noiseTemp = 0;
    }
}
