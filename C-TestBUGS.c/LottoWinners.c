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
void checkLotNum(int);
void releaseTheList();

int main()
{
	char userResponses=NULL;
	int lotNum;
	lottoData();

	while (userResponses != 'Q')
	{
		printf("Dear user, there is options for you:\n1 N-Enter the number of the lottery you want to see his date\n2 q-Quit\n");
		scanf(" %c", &userResponses);

		switch (userResponses)
		{
		case'N':
			printf("Please enter the lottery number:");
			scanf("%d", &lotNum);
			checkLotNum(lotNum);
			break;
		case'Q':
			releaseTheList();
			break;
		default:
			printf("Wrong selection, pls be more sharp");
			break;
		}

	}


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

void checkLotNum(int lotNum)
{
	lotto* curr = head;
	while (curr)
	{
		if (lotNum == curr->lotteryNum)
		{
			printf("Lottery date you asked for: %s\n", curr->lotteryDate);
			return;
		}
		curr = curr->next;
	}
	printf("There is no lottery number founded");
}
void releaseTheList() {
	struct item* freeTheList;
	while (head) {
		freeTheList = head;
		head = head->next;
		free(freeTheList);
	}
}
