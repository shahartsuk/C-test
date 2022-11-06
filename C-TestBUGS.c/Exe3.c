#include <stdio.h>
#include <stdlib.h>
// missing include string.h for some functions
#include<string.h>
#pragma warning(disable:4996)
// struct to collect counting info about english letters found in a text file.
// bug missing pointers next and prev
typedef struct letter {
	char small;
	char big;
	int counter;
	struct letter* next;
	struct letter* prev;
}letter;
//Function to free linked list
void freeList(letter* head) {
	letter* releaseItem;
	letter* runItem = head;
	while (runItem != NULL) {
		releaseItem = runItem;
		runItem = runItem->next;
		free(releaseItem);
	}
}
int main_1_4()
{
	//Next two string represents all the english alphabets (small and capital)
	char* smallAlpha = "abcdefghijklmnopqrstuvwxyz";
	char* bigAlpha = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	int lettersCountArr[20] = { 0 };
	char readChar, ch;
	FILE* f;
	f = fopen("C:\\Users\\97254\\source\\repos\\C-TestBUGS.c\\myFile.txt", "r");
	// bug missing condition for Memory allocation error fix-add if
	if (!f)
	{
		printf("file cant open");
		return 1;
	}

	// Dis[lay the content of myFile.txt and count letters
	printf("the content of myFile.txt :\n");

	//fgetc returns -1 in end of file
	while ((readChar = fgetc(f)) != - 1) 
	{
		printf("%c", readChar);
		for (int i = 0; i < strlen(smallAlpha); ++i) 
		{
			if (readChar == smallAlpha[i] || readChar == bigAlpha[i])
			{
				lettersCountArr[i]++;
				break; // if the letter has been found, break
			}
		}
	}
	fclose(f);

	// Build Linked list from file content
	// Every node represent English letter (small and big).
	letter* HEAD = NULL;
	letter* TAIL = NULL;
	for (int j = 0; j < strlen(smallAlpha); ++j) 
	{
		letter* letterItem = (letter*)malloc(sizeof(letter));
		if (!letterItem) {
			puts("Error Allocating Memory!");
			exit(1);
		}

		letterItem->small = 'a' + j;
		letterItem->big = 'A' + j;
		letterItem->counter = lettersCountArr[j];
		letterItem->next = letterItem->prev = NULL;
		// Creating the linked list
		// missing give the first item to head
		if (!HEAD)
		{
			HEAD = TAIL = letterItem;
		}
		else 
		{
			letterItem->prev = TAIL;
			TAIL->next = letterItem;
			TAIL = letterItem;
		}
	}
	// missing free for the list
	freeList(HEAD);
	return 0;
}