#include "ConsoleFuncion.h"

void PrintConsole(int size, double *arr, char *str)
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

void PrintConsole2Arr(int size, int measurement, double **arr, char *str)
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
			printf("\n");
		}
}

void PrintConsoleGraph(int size, double *arr, char *strName)
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
			if (y == (int) (arr[x] * HEIGHT))
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

void PrintConsoleGraph2(int size, int measurement, double **arr, char *strName)
{
	//printf("\n");
	if (strName == NULL)
	{
		strName = "NoName";
	}
	printf(" %s\n", strName);

	//bool isX = true, isY = true;
	int t = size / 2;


		for (int y = HEIGHT; y >= -HEIGHT; y--)
			{
			for (int rows = 0; rows < measurement; rows++)
			{
				for (int x = 0; x <= size; x++  )
								{
									if (y == (int) (arr[ rows][x] * HEIGHT))
									{
										printf("+");
									}
									else if (y == 0)
									{
										/*if (isX) // X
										{
											printf("X");
											isX = !isX;
										}
										else
										{
											printf("-");
										}*/
									}
									else if (x == t) // Y
									{
										/*if (isY)
										{
											printf("Y");
											isY = !isY;
										}
										else
										{
											printf("|");
										}*/
									}
									else
									{
										printf(" ");
									}
								}
			}

				printf("\n");
			}

}

