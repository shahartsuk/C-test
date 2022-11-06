#include <stdio.h>
#include <stdlib.h>
// bug missing pragma
#pragma warning (disable:4996)

int main_1_3()
{
	int x=10, y=5;
	int nums[6];
	int* arrPtr;

	// Section A - Print the variables
	puts("***** Section A *****");

	
	// bug x have no value fix x=10 
	printf(" Base = %d\n", x);

	// bug y have no value fix y=5
	printf(" Height = %d\n", y);

	// The account operation is incorrect area=x*y/2 
	printf(" Area = %d\n", x * y/2);


	// Section B - Print the static array "nums".


	puts("***** Section B *****");
	// bug loop dont give value, fix nums[i]=i
	// bug infinity loop fix-i++;
	
	int i = 0;
	while (i < 6)
	{
		nums[i] = i+1;
		printf(" nums[%d] = %d\n", i, nums[i]);
		i++;
	}
	
	// Section C - Print allocated array.
	puts("***** Section C *****");

	// bug array need to be with 6 places and wrong writing  fix-6*sizeof(int)
	// malloc return void need to give him the size i use fix-(int*)malloc
	arrPtr = (int*)malloc(6*sizeof(int));
	if (arrPtr) {
		// bug loop dont give value, fix arrPtr[i] = i + 1;

		for (i = 0; i < 6; i++) {
			arrPtr[i] = i + 1;
			printf(" array[%d] = %d\n", i, arrPtr[i]);
		}
	}
	else {
		printf("Error Allocating Memory!\n");
		// bug miss ; 
		exit(1);
	}
	// bug missing free, fix-free(arrPtr)
	free(arrPtr);
	return 0;
}