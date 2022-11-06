#include <stdio.h>
#include<string.h>
#include<stdlib.h>
#pragma warning (disable:4996)

void divideStr(char[]);
char* divideUntillNothing(char[]);

int main_1_5()
{
	char str[100];

	strcpy(str, "hello my name is shahar nice to meet you");
	divideStr(str);
	divideUntillNothing(str);

}
void divideStr(char str[])
{
	int len = strlen(str);
	int halfLen = len / 2;
	char* temp=str;
	char strHalf1[50];
	char strHalf2[50];

	temp = temp + halfLen;
	strncpy(strHalf1, str, halfLen);
	strHalf1[halfLen] = 0;
	
	for (int i = 0; i < halfLen; i++)
	{
		strHalf2[i] = *temp;
		temp++;
	}
	strHalf2[halfLen] = 0;

	printf("%s\n", strHalf1);
	printf("%s\n", strHalf2);
}

// divide the str untill there is nothing to print
char* divideUntillNothing(char str[])
{
	if (strlen(str)<1)
	{
		return;
	}
	int len = strlen(str);
	int halfLen = len / 2;
	char* temp = str;
	char strHalf[50];

	for (int i = 0; i < halfLen; i++)
	{
		strHalf[i] = *temp;
		temp++;
	}
	strHalf[halfLen] = 0;

	printf("%s\n", strHalf);
	divideUntillNothing(strHalf);
}