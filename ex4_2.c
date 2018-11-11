/******************************************

* 83-120-03
* Ex 4
******************************************/
#include "ex4.h"
//Sorry for the kadder- but the main length is explenations..
/*************************************************************************
Function name: lookforward
Input: adresses to -an arry & the last cell of it. & a subject(number)to check
Output: the next relevant location.
The function operation: * getting a number and looking for the next address that contain a bigger number.
return this location.
************************************************************************/
int* lookForward(int* arr,int* end, int subject)
{
	//if got to the end than there is no such address
	if (arr > end)
		return NULL;
	if (subject < arr[0])
		return arr;
	return lookForward(arr + 1, end,subject);
}
/*************************************************************************
Function name: lookBack
Input: adresses to -an arry & counter that is filled withe the length of the last series untill now & a subject(number),
Output: a new counter that represent the lengthof the last series with him inside ,without the outfitting numbers.
The function operation: * getting a number and looking for the last series he could fit in.
*looking for the last cell that contain a number that is smaller than the subject , and chenging the counter accordingly.
************************************************************************/
int lookBack(int arr[], int count, int subject)
{	//stopping situations
	if (count > 0)
	{
		if (arr[-1] >= subject)
		{
			count--;
			return lookBack(arr-1, count, subject);
		}
		else
			return count;
	}
	return count;
}
/*************************************************************************
Function name: calculating
Input: adresses to -an arry & the end of it- the maxNumber that is in the series so far.pointer to a maxSeries(integer)that contain the longest num of series,the 
Output: None - just changing the pMax(the longest series).
The function operation: * getting a number and looking for the last series he could fit in.
*looking for the last cell that contain a number that is smaller than the subject , and chenging the counter accordingly.
************************************************************************/
void calculating(int arr[], int * pEnd, int maxN, int* pMaxS, int serLength)
{
	int* pTemp=NULL;
	//stopping condition
	if (arr > pEnd)
	{
		if (serLength > *pMaxS)
		{
			*pMaxS = serLength;
		}
		return;
	}
	if (arr[0] > maxN)
	{
		calculating(arr + 1, pEnd,arr[0], pMaxS, serLength + 1);
		return;
	}
	//if the current number isnt bigger that the max one.
	else
	{
		//splitting the checking , making a new series with the smaller number
		if(arr[0]<maxN&&arr<pEnd)
		{
			//making the current number-the maxN(umber)-and checking the series for him
			//lookBack checking the current series and deciding how long should be the initial length of the new series.
			calculating(arr + 1, pEnd,arr[0], pMaxS, lookBack(arr, serLength, arr[0])+1);
			//Camming back from(recurion) the last series, and continuing from where stopped- now checking what should be the next cell in the series.
			//Why? for smaller runing time, and because it work..
			//lookforward - returning the adress of the next appropriat cell(apropriate to the root series(previouse),before spliting) 
			if ((pTemp = lookForward(arr + 1, pEnd, maxN)) == NULL)
			{
				if (serLength > *pMaxS)
					*pMaxS = serLength;
				return;
			}	 
			arr = pTemp;
			serLength++;
		}
		calculating(arr + 1, pEnd, maxN, pMaxS, serLength);
	}
	return;
}
/*************************************************************************
Function name: MaxSet
Input: adresses to -an arry & size of the arry
Output: None.
The function operation: * managing  the checking , and printing the max series.
************************************************************************/
void MaxSet(int arr[], int size)
{
	int maxS = 0;
	calculating(arr, arr + size - 1, arr[0], &maxS, 1);
	printf("%d\n", maxS);
}
void main()
{
	int arr[] = { 8,1,2,4,45,40,2,5 };
	MaxSet(arr, 8);
}