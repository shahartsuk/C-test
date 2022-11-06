#include <stdio.h>
#include<string.h>
#include<stdlib.h>
#pragma warning (disable:4996)

typedef struct lotto {
	int lotteryNum;
	char lotteryDate[100];
	struct lotto* next;
	struct lotto* prev;
}lotto;

lotto* head = NULL;
lotto* tail = NULL;

void lottoData();
void buildList(int,char[]);
void printTheList();

int main()
{
	lottoData();
	//printTheList();
}

void lottoData()
{
	int lNum;
	char lDate[100];
	char* token;
	char currStr[100];
	FILE* f = fopen("C:\\Users\\97254\\source\\repos\\C-TestBUGS.c\\Lotto.txt", "r");
	if (!f)
	{
		printf("File cant open");
		return;
	}

	fgets(currStr, 100, f);
	token = strtok(currStr, ",");

	while (fgets(currStr, 100, f)!=NULL)
	{
		token = strtok(currStr, ",");
		lNum = atoi(token);

		token = strtok(NULL, ",");
		strcpy(lDate, token);
		buildList(lNum, lDate);
	}

}

void buildList(int num, char date[])
{
	lotto* curr = (lotto*)malloc(sizeof(lotto));
	if (!curr)
	{
		printf("Error Allocating Memory!");
		exit(1);
	}
	curr->lotteryNum = num;
	strcpy(curr->lotteryDate,date);
	curr->next = curr->prev = NULL;

	if (!head)
	{
		head = tail = curr;
		return;
	}
	else
	{
		curr->prev = tail;
		tail->next = curr;
		tail = curr;
		return;
	}
	return;
}
void printTheList() {
	lotto* curr = head;
	while (curr) {
		printf("num %d date %s\n", curr->lotteryNum, curr->lotteryDate);
		curr = curr->next;
	}
}