/******************************************

* 83-120-03
* Ex 4
******************************************/
#define _CRT_SECURE_NO_WARNINGS
#include "ex4.h"
/*************************************************************************
Function name: DiffersInNChars
Input: pointer to two strings , and n - the number of differences between the string
Output: NONE.
The function operation: * checking if the diferences are equal to n or not.
printing yes if it's
no if not.
************************************************************************/
void DiffersInNChars(char s1[], char s2[], int n)
{	// if one of the string lenges is 0 (stopping condition)
	if (strlen(s1) == 0 || strlen(s2) == 0)
	{
		if (strlen(s1) == strlen(s2))
		{
			if (n == 0)
				puts("yes");
			else
				puts("no");
			return;
		}
		else
		{// if n=s1-s2
			if ((strlen(s1) > strlen(s2)) && n == strlen(s1))
				puts("yes");
			else
				puts("no");
			return;
		}
		if ((strlen(s1) < strlen(s2)) && n == strlen(s2))
			puts("yes");
		else
			puts("no");
		return;
	}
	//if the values are different ,sending to check next cell and doing n-1.
	if (s1[0] != s2[0])
		 DiffersInNChars(s1 + 1, s2 + 1, n - 1);
	else 
		//else - they are equal - goint to the next cells and dont chang n
		DiffersInNChars(s1 + 1, s2 + 1, n);
}