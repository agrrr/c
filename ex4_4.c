/******************************************

* 83-120-03
* Ex 4
******************************************/
#define _CRT_SECURE_NO_WARNINGS
#include "ex4.h"
/*************************************************************************
Function name : Calculating
Input: pointer to an array
Output: NONE.
The function operation: *balancing the string by the following order 
if it contain 1 and the next is 1 =>making the first one squal to 0 and the sec=2 (shakul to 1+1=2)
"  "   "      "  "    " 	"	2=>"	"	"	"	"	"	"	" 0  "	"	"  =0 (shakul for 1+2=3)3 is devided by 3 ..
and so on ////
************************************************************************/
void Calculating(char arr[])
{
	if (strlen(arr) == 1)
		return;
		if ((arr[0] == '1'&&arr[1] == '2') || (arr[0] == '2'&&arr[1] == '1') || (arr[0] == '3'&&arr[1] == '3'))
		{
			//balancing the cells according to math laws..arr[1] contain the SHEERIT
			arr[0] = '0';
			arr[1] = '0';
			//checking for the next cell-jumping by 2 because the next cell already '0'.
			Calculating(arr + 2);
			return;
		}
		else if ((arr[0] == '1'&&arr[1] == '1') || (arr[0] == '2'&&arr[1] == '3')||(arr[0]=='3'&&arr[1]=='2'))
		{
			//balancing the cells according to math laws.. arr[1] contain the SHEERIT.
			arr[0] = '0';
			arr[1] = '2';
		}
		else if ((arr[0] == '1'&&arr[1] == '3') || (arr[0] == '2'&&arr[1] == '2')||(arr[0]=='3'&&arr[1]=='1'))
		{
			arr[0] = '0';
			arr[1] = '1';
		}
		//checking for the next cell
		Calculating(arr + 1);
		return;
}
/*************************************************************************
Function name: DividedBy3
Input: pointer to an array
Output: return  0 - itsnt devided by 3.
				1 - if the num is devided by 3
The function operation: * calling the calculating function , then check if the last cell conteing anything
than '0' or 3(treating a one init string that contain only 3).
if it contain 0 - than the string num is devided by 3 and return 1 to main function
else itsnt good -return 0.
************************************************************************/
int DividedBy3(char str[])
{
	int n = strlen(str);
	char* tempStr = (char*) malloc(n * sizeof(char));
	strcpy(tempStr, str);

	Calculating(tempStr);
	//checking the last cell
	if (tempStr[n - 1] != '0'&&tempStr[n - 1]!='3')
	{	
		free(tempStr);
		return 0;
	}
		free(tempStr);
		return 1;
}