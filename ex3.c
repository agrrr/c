/******************************************

* 83-120-03
* Ex 2
******************************************/
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#define MAX_HEIGHT_SIZE 70
#define MIN_HEIGHT_SIZE 10
#define MAX_WIDTH_SIZE 70
#define MIN_WIDTH_SIZE 10
#define PLEYER_COLOR 'R'
#define COMPUTER_COLOR 'G'
char InitialBoard(char board[MAX_HEIGHT_SIZE][MAX_WIDTH_SIZE], int*, int*,long int*);
void playGame(char board1[MAX_HEIGHT_SIZE][MAX_WIDTH_SIZE], int, int,long int);
int main()
{
	char board[MAX_HEIGHT_SIZE][MAX_WIDTH_SIZE];
	int width, height;
	long int gen;
	if (InitialBoard(board, &width, &height, &gen) != '+')
		return 0;
	playGame(board, width, height, gen);
}
/*************************************************************************
Function name: printBoard
Input: pointer to array && size of width && height that declared in the main function
Output: NONE .
The function operation: * print the board
************************************************************************/
void printBoard(char board[MAX_HEIGHT_SIZE][MAX_WIDTH_SIZE], int width, int height)
{
	int i, j;
	for (i = 0; i < height; i++)
	{
		for (j = 0; j < width; j++)
		{
			printf("%c", board[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}
/*************************************************************************
Function name: getDimentions
Input: pointers to width && height of the array that declared in the main function
Output: NONE.
The function operation: * scan the width and height from  user.
						* updat the width and height that storage the main function.
************************************************************************/
void getDimentions(int*pwidth, int*pheight)
{
	do
	{
		printf("Enter width (10-70):\n");
		scanf("%d", pwidth);
	} while (*pwidth < 10 || *pwidth>70);
	do
	{
		printf("Enter height (10-70):\n");
		scanf("%d", pheight);
	} while (*pheight < 10 || *pheight>70);
}
/*************************************************************************
Function name: resetBoard
Input: pointer to array &&  size of array = > width && height that declared in the main function
Output: NONE .
The function operation: * reset all the chars in the array to be -.
************************************************************************/
void resetBoard(char board[MAX_HEIGHT_SIZE][MAX_WIDTH_SIZE], int width, int height)
{
	int i, j;
	for (i = 0; i < height; i++)
	{
		for (j = 0; j < width; j++)
		{
			board[i][j]='-';
		}
	}
}
/*************************************************************************
Function name: LivingCells
Input: pointer to array && size --> width && height of the array.
Output: NONE .
The function operation: * getting from the user the number of living cells for players.
						* initial the board with living cells, make the initial state of the board.
************************************************************************/
void LivingCells(char board[MAX_HEIGHT_SIZE][MAX_WIDTH_SIZE], int width, int height)
{
	int countLives,x,y;
	char CellKind;
	do
	{
		printf("Enter number of living cells (0-%d):\n", width*height);
		scanf("%d", &countLives);
		//*if the counLives is valid it will enter the 'if' and proceed ,
		//*else it will skip the if tatement and return to get a new input.
		if (countLives > 0 && countLives < width*height)
		{
			while (countLives != 0)
			{
				printf("Enter x y and color (R/G):\n");
				scanf("%d %d %c", &x, &y, &CellKind);
				// *will Enter If the cell empty.
				// *if not empty ,will skip , and return to while to get a new input.
				// *by checking "if (board[x][y] == '-')" im virtually checking that the -
				// input is correct(i filled only the valide cells with '-').
				if (board[x][y] == '-')
				{
					if (CellKind == 'r' || CellKind == 'R')
					{
						board[x][y] = 'R';
						countLives--;
					}
					else if (CellKind == 'g' || CellKind == 'G')
					{
						board[x][y] = 'G';
						countLives--;
					}
				}
			}
		}
	} while (countLives != 0);
}
/*************************************************************************
Function name: playerMoov.
Input: pointer to array && size --> width && height of the array.
Output: NONE.
The function operation: * getting a moov from user.
						* placing it on the board by the ruls.
************************************************************************/
void playerMoove(char board[MAX_HEIGHT_SIZE][MAX_WIDTH_SIZE],int width,int height)
{
	int x, y;
	do
	{
		printf("R is playing\nx y:\n");
		scanf("%d %d", &x, &y);
	} while (x>height || x<0 || y<0 || y>width);
	//if R already inside break>>>if not placing R
	switch (board[x][y])
	{
	case 'R':
		break;
	default: 
		board[x][y] = 'R';
		break;
	}
}
/*************************************************************************
Function name: neighboars.
Input: pointer to array && size --> width && height of the array&&cooridate of a specific cell for checking&& 3 adresses of ints placing in the calling function.
Output: NONE.
The function operation: * for every coordinate the func get it calculate its neighbors(by defenition).
*************************************************************************/
void neighboars(int width, int height, int i, int j, char board[MAX_HEIGHT_SIZE][MAX_WIDTH_SIZE], int*pcountG, int*pcountR,int*pcountD)
{
	int row, colum;
	*pcountG = 0;
	*pcountR = 0;
	*pcountD = 0;
	for (row = -1; row < 2; row++)
	{
		for (colum = -1; colum < 2; colum++)
		{
			//if it came to the cell itself skipping to the next looop
			if (row == 0 && colum == 0)
				continue;
			//checking the cell value and counting accordinly.
			switch (board[(i + height + row) % height][(j + width + colum) % width])
			{
			case 'R':
				*pcountR = *pcountR + 1;
				break;
			case 'G':
				*pcountG = *pcountG + 1;
				break;
			case '-':
				*pcountD = *pcountD + 1;
				break;
			}
		}
	} //Sorry for those linesV V V when i delete them it jinks my code , dont know why , tried several times..
	/*switch (board[i][j])
	{
	case 'R':
		*countR = *countR - 1;
		break;
	case 'G':
		*countG = *countG -1;
		break;
	case '-':
		*countD = *countD -1;
		break;
	}*/
}
/*************************************************************************
Function name: balancing
Input: pointer to array && size --> width & height of the array && a specific location x,y for calcutating the next gen.
Output: NONE .
The function operation:
 * im getting to the function wto boards from the calling function, the first one is refered as const, whill the other one is
 - refered im this function as garbage at first , and at last its the real board , all the calculations are inputed to it.
 * balancing a specific location by the ruls of the game.
************************************************************************/
void nextGen(int width, int height, char board[MAX_HEIGHT_SIZE][MAX_WIDTH_SIZE], char tempBoard[MAX_HEIGHT_SIZE][MAX_WIDTH_SIZE])
{
	int i, j,countG, countR,countD;
	for (i = 0; i < height; i++)
	{
		for (j = 0; j < width; j++)
		{
			neighboars(width, height, i, j, board, &countG, &countR,&countD);
			if (((countR + countG) >= 4) || ((countR + countG) <= 1))
				tempBoard[i][j] = '-';
			else if ((board[i][j] == '-') && (countR + countG) == 3)
			{
				if (countR > countG)
					tempBoard[i][j] = 'R';
				else
					tempBoard[i][j] = 'G';
			}
			else
				tempBoard[i][j] = board[i][j];
		}
	}
}
/*************************************************************************
Function name: isGameOver
Input: pointer to array && size --> width && height of the array&&number of current generation.
Output: the condition of the gave
if we have a winner:
		R for player
		G for computer
		D if the board is empty- No winners everyone loos.
		= for equal state at the end of game
		+ The game is still on..
		The function operation: * checking who is rulling the board for now
								* && if there is a dermiate condition.
************************************************************************/
char isGameOver(char board[MAX_HEIGHT_SIZE][MAX_WIDTH_SIZE], int width, int height,long int generation)
{
	int countR = 0, countG = 0, countD=0 , i,j;
	for (i = 0; i < height; i++)
	{
		for (j = 0; j < width; j++)
		{
			switch (board[i][j])
			{
			case '-':
				countD++;
				break;
			case'R':
				countR++;
				break;
			case 'G':
				countG++;
				break;
			}
		}
	}
	if (countD == (width*height))
	{
		printBoard(board, width, height);
		printf("Game over! There is no winner :|\n");
		return 'D';
	}
	else if (generation == 0||countG==0||countR==0)
	{
		if (countR > countG)
		{
			printBoard(board, width, height);
			printf("Game over! R is the winner :)\n");
			return 'R';
		}
		else if (countG > countR)
		{
			printBoard(board, width, height);
			printf("Game over! G is the winner :(\n");
			return 'G';
		}
		else
		{
			printBoard(board, width, height);
			printf("Game over! There is no winner :|\n");
			return'=';
		}
	}
	else
		return'+';	
}
/*************************************************************************
Function name: compMoove
Input: pointer to array && size --> width && height of the array.
Output: None- Just changing the board a bit
operation: * choos a cell for placing G by:
	   * first Red with 2||3 neighbors
	   * or - first deadcell with majority of Red neighbors(for 3 or 2 neighbors)
	   * or - The first Red living cell.
************************************************************************/
void compMoove(char board[MAX_HEIGHT_SIZE][MAX_WIDTH_SIZE],int width,int height)
{
	int i, j, countG = 0, countR = 0, countD = 0,choosD=1,choosR=1,dx,dy,rx,ry;
	printf("G is playing\n");
	for (i = 0; i < height; i++)
	{
		for (j = 0; j < width; j++)
		{
			neighboars(width, height, i, j, board, &countG, &countR, &countD);
			if ((board[i][j] == 'R') && ((countR + countG == 2) || (countR + countG == 3)))
			{
				printf("%d %d\n", i, j);
				board[i][j] = 'G';
				return;
			}
			//choos the coordinates for the first dead cell that meat the ruls.for later use if needed...
			if ((choosD == 1 && board[i][j] == '-')&& (countG == 0 || countR + countG == 3) && (countR == 2))
			{
				if ((countG==0 || countR + countG == 3) && (countR==2))
				{
					choosD = 0;
					dx = i;
					dy = j;
				}
			}
			//choos the coordinates for the first Red cell that meat the ruls.for later use if needed...
			else if ((choosR == 1) && (board[i][j] == 'R'))
			{
				choosR = 0;
				rx = i;
				ry = j;
			}
		}
	}
	//if func didnt ended by now , execute plan B >> placing G in the first dead cell that applyed to the ruls given
	if (choosD == 0)
	{
		printf("%d %d\n", dx, dy);
		board[dx][dy] = 'G';
		return;
	}
	//else plan C>>> placing G in the first redcell that meat the ruls of the game
	else
	{
	//	printf(" %d \n",choosD);
		printf("%d %d\n", rx, ry);
		board[rx][ry] = 'G';
		return;
	}
}
/*************************************************************************
Function name: InitialBoard
Input: pointers to array,to size --> width && height of the array && To the generation declared in tha main.
Output: NONE .
The function operation: * initialate the board with with info from user:
* getting dimention.
* getting the start positions from user.
* verified that the board given isent cheeting - isnt red/green only++ if so return - else +
* get the number of gen from user.
************************************************************************/
char InitialBoard(char board[MAX_HEIGHT_SIZE][MAX_WIDTH_SIZE], int* pwidth, int* pheight, long int* pgen)
{
	printf("Welcome to the game of life!\nSettings:\n");
	getDimentions(pwidth, pheight);
	resetBoard(board, *pwidth, *pheight);
	LivingCells(board, *pwidth, *pheight);
	printf("\n");
	if (isGameOver(board, *pwidth, *pheight, 2) != '+')
		return '-';
	printBoard(board, *pwidth, *pheight);
	do
	{
		printf("Enter number of generations(>=0):\n\n");
		scanf("%ld", pgen);
	} while (*pgen < 0);
	return'+';
}
/*************************************************************************
Function name: playGame.
Input: pointers to array,to size --> width && height of the array && To the generation declared in tha main.
Output: NONE .
The function operation: *managing the game first player play 
* checking if there is a game over ,if so end game
* getting the start positions from user.
* verified that the board given isent cheeting - isnt red/green only++ if so return - else +
* get the number of gen from user.
************************************************************************/
void playGame(char board1[MAX_HEIGHT_SIZE][MAX_WIDTH_SIZE], int width, int height,long int generation)
{
	char board2[MAX_HEIGHT_SIZE][MAX_WIDTH_SIZE];
	int assgen = 1;
	char leading;
	nextGen(width, height, board1, board2);
	printf("Welcome to the game of life!\nThis is the initial board:\n");
	if (isGameOver(board2, width, height, generation) != '+')
		return;
	printBoard(board2, width, height);
	while (generation > 0)
	{
		if (assgen % 2 == 1)
		{
			playerMoove(board2,width,height);
			assgen++;
			if (isGameOver(board2, width, height, generation) != '+')
				return;
			nextGen(width, height, board2, board1);
			generation--;
			if (isGameOver(board1, width, height, generation) != '+')
				return;
			printBoard(board1, width, height);
		}
		else
		{
			compMoove(board1,width,height);
			assgen++;
			if (isGameOver(board1, width, height, generation) != '+')
				return;
			nextGen(width, height, board1, board2);
			generation--;
			if (isGameOver(board2, width, height, generation) != '+')
				return;
			printBoard(board2, width, height);
		}
	}
}