
/******************************************
* 83-120-03 
* Ex 2
******************************************/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
void tri(int, int);
void Id(unsigned long int);
void paint1(int);
void paint2(int);
void paint3(int);
int equ(float, float, float);
float positive(float);
int main()
{
	int manu, left, right, w;
	float a, b, c;
	unsigned long int id;
	while (1)
	{
		printf("Choose 1 for triangle, 2 for ID, 3 for carpets, 4 for equation, -1 for exit\n");
		scanf("%d", &manu);
		switch (manu)
		{
			//triangle numbers
		case 1:
			printf("Enter 2 numbers (left and right):\n");
			scanf("%d%d", &left, &right);
			//verify the input correction, no negation and at the same order 
			if (left < 0 || right < 0 || left == 0 || left > right)
			{
				printf("Error input!\n");
			}
			else
				tri(left, right);
			break;
			//ID
		case 2:
			scanf("%lu", &id);
			// The Practicer told us that we need to invalid negative number.
			if (id <= 0)
				printf("Invalid ID number\n");
			else
				Id(id);
			break;
			//Carpets
		case 3:
			//Getting the width and checking for restrictions
			scanf("%d", &w);
			if (w >= 2 && w <= 10)
			{
				paint1(w);
				printf("\n");
				paint2(w);
				if (w % 2 == 0)
				{
					printf("\n");
					paint3(w);
				}
			}
			else
				printf("Error input!\n");
			break;
			//equasion
		case 4:
			//input
			printf("Enter three numbers:\n");
			scanf("%f%f%f", &a, &b, &c);
			//sending varys to the equ function
			equ(a, b, c);
			break;
			//Exit
		case -1:
			return 0;
			//Deal with discorrect input to manu
		default:	printf("No such option!\n");
			break;
		}
	}
}
/************************************************************************* 
Function name: tri		
Input: two limits smaller one calls Left, Bigger is Right.
Output: print all the triangles numbers between the limits given.
The function operation: * building the triangle 
					    * for every loop, add a new line to the triangle
					    * print that new line (and flaggint)
************************************************************************/
void tri(int left, int right)
{
	int flag=0, triNum = 0, i;
	/* For Hityaalut i made the triNum <right, the for loop run only the times it should*/
	for (i = 0; triNum < right; i++)
	{
		triNum = (i*(i + 1) / 2);
		if (triNum >= left && triNum <= right)
		{
			printf("%d\n", triNum);
			flag = 1;
		}
	}
	if (flag == 0)
		printf("None\n");
}
/*************************************************************************
Function name: Id
Input: ID number.
Output: print wether the Id given id Vallid or not,.
The function operation: 
*summing two number at one 'for' loop for faster and easier code
* thr code is laying of the info given from the METARGELIM the the input wont be bigger than 9 digits .
*if we want to allow it to get more than 9 digits the algorithem still will work and check the mathematical correction.
* print In\Valin.
************************************************************************/
void Id(unsigned long int id)
{
	int help1, help2, sum = 0, i;
	/* summing the id integers . each for is summing 2 integers totly summing 10 digits while the last one is 0
	thout that for the question statments it will be more effective than splitint the for loop to two cases *1 &*2*/
	for (i = 1; i <=5; i++)
	{
		//help1=unit of id and that i delete this num fron the id num, and so on...
		help1 = id % 10;
		id = id / 10;
		help2 = (id % 10)*2;
		id = id / 10;
		//deling with special condition, integers*2 is bigger than 10.
		if ((help2) >= 10)
			//summing the units and tens
			help2 = (help2 % 10) + (help2 / 10);
		//suming everything
		sum = sum + help1 + help2;
	}
	//deciding wether the id is valid or not.
	if (sum % 10 == 0)
		printf("Valid ID number\n");
	else
		printf("Invalid ID number\n");
}
/*************************************************************************
Function name: paint1
Input: width of the carpet.
Output: printing the carpent.
The function operation: 
* for odd rows print the pattern XOXO.
* for non odd rows print pattern OXOX.
* of cours every print it by the destriction of th width given.
************************************************************************/
void paint1(int w)
{
	int i, j;
	for (i = 1; i <= w; i++)
	{
		if (i % 2) //For odd rows
		{
			for (j = 1; j <= w; j++)
			{
				//odd coloms
				if (j % 2) 
					printf("X");
				else      //2coloms
					printf("O");
			}
			printf("\n");
		}
		else  //for 2 rows
		{
			for (j = 1; j <= w; j++)
			{
				if (j % 2) //1 coloms
					printf("O");
				else      //2 coloms
					printf("X");
			}
			printf("\n");
		}
	}
}
/*************************************************************************
Function name: paint2
Input: width of the carpet.
Output: printing the carpent.
The function operation:
* 'for' loop is running on the rows 
* thw 'while' loops are runnimg on the colloms and printing the carpet
************************************************************************/
void paint2(int w)
{
	int x, o = 0, i;
	for (i = 0; i <= w; i++)
		{
			o = i;
			//printing first part of the carpet include -O-.
			while (o > 0)
			{
				printf("O");
				--o;
			}
			//printing the lest of the lain.
			x = w - i;
			while (x > 0)
			{
				printf("X");
				--x;
			}
			printf("\n");
		}
}
/*************************************************************************
Function name: paint3
Input: width of the carpet.
Output: printing the carpent.
The function operation:
* firs while print the form XXOO
* seconf main wile is printing the OOXX form
************************************************************************/
void paint3(int w)
{
	int  count1 = 0, count2;
	if (w % 2)
		return ;
	while (count1 < (w / 2))
	{
		count2 = 0;
		while (count2 < (w / 2))
		{
			printf("X");
			++count2;
		}
		while (count2 < w)
		{
			printf("O");
			++count2;

		}
		count1++;
		printf("\n");
	}
	while (count1 < w)
	{
		count2 = 0;
		while (count2 < (w / 2))
		{
			printf("O");
			++count2;
		}
		while (count2 < w)
		{ 
			printf("X");
			++count2;

		}
		count1++;
		printf("\n");
	}
	return ;
}
/*************************************************************************
Function name: equ
Input: a,b,c as Mekadmim Numbers of an equasion.
Output: the equasion the the function is going to solve and the solvation.
The function operation:
* a=0 dealing withe specific option and printing it.
* print the quation of the formation  ax^2+bx+c=0
* solving the quation for regular and Complexed numberes.
************************************************************************/
int equ(float a, float b, float c)
{
	float delta, help1, help2, x1, x2, Re, Im;
	//No solution && Special case.
	if (a == 0)
	{
		if (b == 0)
		{
			if (c == 0)
			{
				printf("%.f = %.f\n", positive(a),positive(b));
				printf("Infinite solution!\n");
			}
			else
				printf("No solusion!\n");
		}
		else//for b!=0 
		{
			switch ((int)b)
			{
			case 1 :
				printf("x");
				break;
			case -1 :
				printf("-x");
				break;
			default:printf("%.0fx", b);
			}
			if (c!=0)
				printf("%+.0f", c);
			printf(" = 0\n");
			if(c!=0)
				printf("x1 = %.2f\n", (-1)*c / b);
			else
				printf("x1 = 0.00\n");
		}
			return 0;			
	}
	//printing the full equ
	if (a != 0)
	{
		switch ((int)a)
		{
		case 1:
			printf("x^2");
			break;
		case -1:
			printf("-x^2");
			break; 
		default:printf("%.0fx^2", a);
		}
		switch ((int)b)
		{
		case 1 :
				printf("+x");
				break;
		case -1:
				printf("-x");
				break;
		case 0:break;
		default :printf("%+.0fx", b);
		}
		switch ((int)c)
		{
		case 0:
			break;
		default: printf("%+.0f", c);
		}
		printf(" = 0\n");
	}
	// ax^2 +/- c = 0 we already know from the first if that a is !=0
	if (b == 0)
	{
		if (c == 0)//the equasion is ax^2=0
		{
			printf("x1 = %.2f\n", positive(c));
			return 0;
		}
		// a & c have the opposite sighn
		if(c<0&&a>0||c>0&&a<0)
		{
			printf("x1 = -%.2f\nx2 = +%.2f\n", sqrt(positive(c/a)), sqrt(positive(c/a)));
		}
		else//both have the same sighn so complex
		{
			printf("x1 = -%.2fi\nx2 = %.2fi\n", sqrt(c / a), sqrt(c / a));
		}
		return 0;
	}
	/*theoratically i dont need to check if b!=0 because i know that if the code got this far it b!=0.
	 I already deal with the other option of a!=0&&b==0*/
	// ax^2+bx=0
	if (c == 0 && b != 0)
	{
		if (a > 0 && b > 0 || a < 0 && b < 0)// have the same sighn
			printf("x1 = %.2f\nx2 = 0.00\n",  (-1)*b/a);
		else//have different sighns
			printf("x1 = 0.00\nx2 = %.2f\n", positive(b / a));
		return 0;
	}
	delta = b*b + (-4) * a * c;
	help1 = ((-1) * b) / (2 * a);
	help2 = (sqrt(positive(delta))) / (2 * a);
	// solving a complex equasion
	if (delta < 0)
	{
		//i use re and Im so it will be easier to see and for not loosing any points ...
		Re = help1;
		Im = positive(help2);
			//printf("\n Merukavim 1 loop\n ");
			printf("x1 = %.2f - %.2fi\n", Re, Im);
			printf("x2 = %.2f + %.2fi\n", Re, Im);
		return 0;
	}
	//normal
	if (delta > 0)
	{
		x1 = help1 + help2;
		x2 = help1 - help2;
		if (x1 < x2)
		{
			//printf("\n Normal loop1 ");
			printf("x1 = %.2f\n", x1);
			printf("x2 = %.2f\n", x2);
			return 0;
		}
		else
		{
			//printf("\n Normal loop2 ");
			printf("x1 = %.2f\n", x2);
			printf("x2 = %.2f\n", x1);
			return 0;
		}
	}
	if (delta == 0)
	{
		printf("x1 = %.2f\n", help1);
		return 0;
	}
	return 0;
}
/*************************************************************************
Function name: positive
Input: and float number.
Output: the positive option of the number inputed.
The function operation:
* checkin if the input is negative , return (-1)*Input.
************************************************************************/
float positive(float a)
{
	if (a < 0||a==-0)
		return (a*(-1));
	else
		return a;
}