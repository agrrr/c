/******************************************

* 83-120-03
* Ex 4
******************************************/
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<malloc.h>
#include "ex4.h"
/*************************************************************************
Function name: PrintStrings
Input: char array
Output: NONE.
The function operation: * print the string.
************************************************************************/
void PrintStrings(const char str[])
{
	puts(str);
}
/*************************************************************************
Function name: reverseStrings
Input: pointer to an chrs array && 'two boders'
Output: NONE.
The function operation: * swapping all the signals-in the array-beween those two borders.
************************************************************************/
void reverseStrings(char string[], int initial, int end)
{
	char temp;
	// inital!=end for 2 numbers of cells(that are devided good with 2).
	// initial<end - made for odd number of cells.
	while (initial != end&&initial < end)
	{
		temp = string[initial];
		string[initial] = string[end];
		string[end] = temp;
		initial++;
		end--;
	}
}
/*************************************************************************
Function name: ReverseStringsManager
Input: pointer to an array.
Output: NONE.
The function operation: * managing the string swapping
* first swapping every word inside the string.
* Then swappint all the string ,and vwalla...done! ;)
************************************************************************/
void ReverseStringsManager(char str[])
{
	int i = 0, initWord = 0;
	// prining the initial string.
	printf("The word list: ");
	puts(str);
	while (str[i] != '\0')
	{
		if (str[i] == ',')
		{
			reverseStrings(str, initWord, i - 1);
			initWord = i + 1;
		}
		//verifying the input correction.
		else if ((str[i] < 'a' || str[i] > 'z') && (str[i] < 'A' || str[i] > 'Z'))
		{
			puts("The list is illegal!");
			return;
		}
		i++;
	}
	//flipping the last word that isnt included in the loop before - (done that way for easier reading) ;
	reverseStrings(str, initWord, i - 1);
	reverseStrings(str, 0, i - 1);
	// prining the final revered string.
	printf("Reverse: ");
	puts(str);
	return;
}