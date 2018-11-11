/******************************************

* 83-120-03
* Ex 5
******************************************/
// you will notice that made a free to NULL pointers, matan told me (after finishing the task) it isnt valid but it is..
//-> http://www.tutorialspoint.com/c_standard_library/c_function_free.htm
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<malloc.h>
#include<string.h>
#include<stdlib.h>
struct warrier
{
	int id;
	char* name;
	struct warrier* next;
	int nChilds;
	char** childList;
}; 
typedef struct warrier warrier;
/*************************************************************************
Function name: initSerKill
Input: 2 pointers , first the pinter to the current cell, the second is the pointer to the first cell
Output: 0 if done correctly . 1 if there is no memory to alocate.
The function operation: * fillint a vary (warrier type) with data from the player.
using dinamic allocating memory.
*At the the end asking if user want to make another vary,(int more warrier to the circle) if he want , the func is allocating memory for it and send 
it back by recurtion for filling with data.
************************************************************************/
int initSerKill(warrier* head,warrier*first)
{
	char name[80];//a temp char arry iwill use for getting a string from user.any time i will shredd on it.
	int count = 1, choose;
	puts("name:");
	scanf("%s", name);
	//for correctly freeing if mallocs fails
	head->childList = head->name = head->next = NULL;
	//getting the parameters from user and save them on the memory at the right place
	if ((head->name = (char*)malloc((strlen(name)+1) * sizeof(char))) != NULL)
	{
		strcpy(head->name, name);
		puts("id:");
		scanf("%d", &(head->id));
		puts("num of kids:");
		scanf("%d", &(head->nChilds));
		//allocating a memoryspace for 'childList' if player want 0 childs 
		if ((head->childList = (char**)malloc((head->nChilds+1) * sizeof(char*))) == NULL)
			return 1;
		//if malloc succeed than keep going
	}
	else//if malloc return NULL
		return 1;
	//getting the childrens nameses if there are any
	while (count <= head->nChilds)
	{
		printf("kid number %d name:\n", count);
		scanf("%s", name);
		//alocating memory using malloc, if return NULL than the func end and return 1.
		if ((head->childList[count - 1] = (char*)malloc((strlen(name) + 1) * sizeof(char))) == NULL)
		{
			//for evoiding problemes when freeing 
			head->nChilds = count - 1;
			return 1;
		}
		//coppying the temp string to the permanent memory that we allocate
		strcpy(head->childList[count - 1], name);
		count++;
	}
	//asking if there is a willing to add another person 
	puts("Add a person to the game? 1 for yes, 0 for no");
	scanf("%d", &choose);
	if (choose == 1)
	{//entring the next adrees that malloc return to the current person at thee filed next
		if ((head->next = (warrier*)malloc(1 * sizeof(warrier))) == NULL)
			return 1;
		else
			return initSerKill(head->next,first);//filling the next cell
	}
	else//making the last one pointer -to point the adreess of the first person ,(like a circle)
		head->next = first;
	return 0;
}
/*************************************************************************
Function name: deleteAll
Input: pointer to the first person;
Output: none.
The function operation: *deleting all the persons in the game (using free)

************************************************************************/
void deleteAll(warrier*firstInList)
{
	warrier* next;
	//freeing the childs name arrys
	while (firstInList->nChilds>0)
	{
		 free(firstInList->childList[firstInList->nChilds - 1]);
		 firstInList->nChilds--;
	}
	//freeing the list that contain the child nams arrys
	free(firstInList->childList);
	//freeing the warrier name
	free(firstInList->name);
	//backaping the next address
	next = firstInList->next;
	//freeing the current struct
	free(firstInList);
	//stopping condition to the recurtion
	if (next==firstInList||next==NULL)
		return;
	//recurtion , now nor the  next cell in the linked linst
	deleteAll(next);
	return ;
}
/*************************************************************************
Function name: kill
Input: pointer to the a person that i want to kiil;
Output: the pointer to the person after the deadly one.
The function operation: *delete a specific person and returning the adress he had in field next.
************************************************************************/
warrier* kill(warrier* goHeaven)
{
	warrier* next;
	int count = 0;
	//printing the name as asked
	printf("%s ", goHeaven->name);
	free(goHeaven->name);
	while (goHeaven->nChilds>count)
	{//printing the name of the killed child
		printf("and %s ", goHeaven->childList[count]);
		free(goHeaven->childList[count]);
		count++;
	}
	printf("\n");
	free(goHeaven->childList);
	next = goHeaven->next;
	free(goHeaven);
	return next;
}
/*************************************************************************
Function name: playFunc
Input:2 pointers , first the pinter to the current cell, the second is the pointer to the first cell
Output: none.
The function operation: *managing the 'killing zone'.
************************************************************************/
void playFunc(warrier* alive, warrier*head)
{
	//we end the game , there is no more player that this one last.
	if (alive == alive->next)
	{
		printf("%s stayin alive!!\n", alive->name);
		deleteAll(alive);
		return;
	}
	printf("%s kills ", alive->name);
	//killing the next
	alive->next = kill(alive->next);
	//recursing for the new next
	playFunc(alive->next, head);
	return;
}
/*************************************************************************
Function name: manageGame
Input:none.
Output: none.
The function operation: *managing the game :
*
************************************************************************/
void manageGame()
{
	int choose;
	warrier* pHead;
	puts("Add a person to the game? 1 for yes, 0 for no");
	scanf("%d", &choose);
	if (choose == 1)
	{
		//making the first warrier(making sure malloc isnt NULL)>>> and sending him forfilling...
		if ((pHead = (warrier*)malloc(sizeof(warrier))) == NULL)//if Null no need to free because there is nothing to free
			exit(1);
		//in case somthing with alloccating memory(of first warrier or the following ones) went wrong enter the if .
		if(initSerKill(pHead, pHead) == 1)
		{
			deleteAll(pHead);
			exit(1);
		}
		//''playing the game''
		playFunc(pHead, pHead);
		exit(1);
	}
	else
		exit(1);
}
void main()
{
	manageGame();
}