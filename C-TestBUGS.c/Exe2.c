#include <stdio.h>
#include<string.h>
#include<stdlib.h>
#pragma warning (disable:4996)

void triangleArea();
void staticNumArray();
void dynamicNumArray();

int main_1_2()
{
	triangleArea();
	staticNumArray();
	dynamicNumArray();
	
}
void triangleArea()
{
	int baseTri = 8, heightTri = 10;
	printf("Base triangular = %d,\nheight triangular = %d\n", baseTri, heightTri);

	printf("Triangle Area is Base-%d X height-%d:2=%d\n", baseTri, heightTri, baseTri * heightTri / 2);

}
void staticNumArray()
{
	 unsigned int array[6] = { 1,2,3,4,5,6 };

	for (int i = 0; i < 6; i++)
	{
		printf("Static array %d\n", array[i]);
		
	}
}
void dynamicNumArray()
{
	unsigned int* array;
	array = (int*)malloc(6*sizeof(int));
	if (!array)
	{
		printf("Memory allocation error");
		exit(1);
	}

	for (int i = 0; i < 6; i++)
	{
		array[i] = i+1;
		printf("Dinamic array %d\n", array[i]);
	}
	free(array);
}