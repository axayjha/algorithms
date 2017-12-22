#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAXSIZE 10

bool place(int board[], int row, int column);
void print(int board[], int N);
unsigned nqueen(int row, int N);

int main()
{
	int N;
	printf("Enter N: ");
	scanf("%d", &N);

	int nSols = nqueen(1,N);
	printf("Total solutions= %d\n", nSols);
}



bool place(int board[], int row, int column)
{
	for(int i = 1; i < row; i++)
	{
		if( (board[i] == column) || \	// if column is same
			abs(board[i]-column) == abs(i-row) )	// if present diagonally
			return false;		// can't be placed!
	}
	return true;	// if no comflict, can be placed.
}

void print(int board[], int N)
{
	for(int i = 0; i < N; i++)
		printf("%d ", board[i]);
	printf("\n");
}

unsigned nqueen(int row, int N)
{
	static unsigned nSolutions = 0;
	static unsigned board[MAXSIZE];
	for(int column = 1; column <= N; column++)
	{
		if(place(board, row, column))
		{
			board[row]=column;	// place it if can be placed
			if(row == N)		// if all rows filled, print the solution
			{
				print(board, N);
				nSolutions++;
			}
			else
				nqueen(row+1, N); // otherwise backtrack
		}	
		
	}
	return nSolutions;
}