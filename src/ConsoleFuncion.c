#include "ConsoleFuncion.h"

void PrintConsole(int size, float *arr, char *str)
{
    if (str == NULL)
    {
        str = "NoStr";
    }
    printf("\nArr: %s\n", str);

    for (int i = 0; i < size; i++)
    {
        printf("%f\n", arr[i]);
    }
}

void PrintConsole2Arr(int size, int measurement, float arr[measurement][size], char *str)
{
    if (str == NULL)
    {
        str = "NoStr";
    }
    printf("\nArr: %s\n", str);

    for (int rows = 0; rows < measurement; rows++)
    {
        for (int cols = 0; cols < size; cols++)
        {
            printf("[%f]", arr[rows][cols]);
        }
        printf("\n\n");
    }
}

void PrintConsoleGraph(int size, float *arr, char *strName)
{
    printf("\n");
    if (strName == NULL)
    {
        strName = "NoName";
    }
    printf(" %s\n", strName);

    bool isX = true, isY = true;
    int t = size / 2;

    for (int y = HEIGHT; y >= -HEIGHT; y--)
    {
        for (int x = 0; x <= size; x++)
        {
            if (y == (int)(arr[x] * HEIGHT))
            {
                printf("+");
            }
            else if (y == 0)
            {
                if (isX) // X
                {
                    printf("X");
                    isX = !isX;
                }
                else
                {
                    printf("-");
                }
            }
            else if (x == t) // Y
            {
                if (isY)
                {
                    printf("Y");
                    isY = !isY;
                }
                else
                {
                    printf("|");
                }
            }
            else
            {
                printf(" ");
            }
        }
        printf("\n");
    }
}

FILE * OpenFile(char *nameFile)
{
    FILE * file;
    file = fopen(nameFile, "w");
    return file;
}

void CloseFile(char *nameFile,FILE *file)
{
    fclose(file);
    printf("Data write file: %s\n", nameFile);
}

void PrintTxtFile(FILE *file, int size, float *arr, char *strName)
{
    if (file == NULL)
    {
        printf("Error open file!\n");
        return;
    }

    if (strName == NULL)
    {
        strName = "NoStr";
    }
    fprintf(file, "\nArr: %s\n", strName);

    for (int i = 0; i < size; i++)
    {
        fprintf(file, "%f\n", arr[i]);
    }
}

void PrintGrafFile(FILE *file, int size, float *arr, char *strName)
{
 printf("\n");
    if (strName == NULL)
    {
        strName = "NoName";
    }
    fprintf(file, " %s\n", strName);

    bool isX = true, isY = true;
    int t = size / 2;

    for (int y = HEIGHT; y >= -HEIGHT; y--)
    {
        for (int x = 0; x <= size; x++)
        {
            if (y == (int)(arr[x] * HEIGHT))
            {
                fprintf(file, "+");
            }
            else if (y == 0)
            {
                if (isX) // X
                {
                    fprintf(file, "X");
                    isX = !isX;
                }
                else
                {
                    fprintf(file, "-");
                }
            }
            else if (x == t) // Y
            {
                if (isY)
                {
                    fprintf(file, "Y");
                    isY = !isY;
                }
                else
                {
                    fprintf(file, "|");
                }
            }
            else
            {
                fprintf(file, " ");
            }
        }
        fprintf(file, "\n");
    }
}

void PrintTxtFile2Arr(FILE *file, int size, int measurement, float arr[measurement][size], char *str)
{
    if (str == NULL)
    {
        str = "NoStr";
    }
    printf("\nArr: %s\n", str);

    for (int rows = 0; rows < measurement; rows++)
    {
        for (int cols = 0; cols < size; cols++)
        {
            fprintf(file, "[%f]", arr[rows][cols]);
        }
        fprintf(file, "\n\n");
    }
}

