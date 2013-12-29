#include <stdio.h>
#include "sudoku.h"

bool finished = false;

bool is_a_solution(int a[], int k, boardtype *board)
{
	if(board->freecount==0) return true;
	else return false;
}

void process_solution(int a[], int k, boardtype *board)
{
	for (int i = 0; i!=9; i++)
	{
		for (int j = 0; j!=9; j++)
		{
			printf("%d ",board->m[i][j]);
		}
		printf("\n");
	}
}

void construct_candidates(int a[], int k, boardtype *board, int *c, int *ncandidates)
{
	*ncandidates = 0;
	int i,j;
	for (i = 0; i!=9; i++)
	{
		for (j = 0; j!=9; j++)
			if (board->m[i][j]==0)
			{
				board->move[k].x = i;
				board->move[k].y = j;
				break;
			}
			if(j!=9) break;
	}

	int posible[10] = {0,1,1,1,1,1,1,1,1,1};
	for (int n = 0; n != 9; n++)
	{
		posible[board->m[i][n]] = 0;
		posible[board->m[n][j]] = 0;
	}
	i = i - i%3;
	j = j - j%3;
	for (int n = i; n!= i+3; n++)
	{
		for (int m = j; m!= j+3; m++)
			posible[board->m[n][m]] = 0;
	}

	for (i = 1; i!=10; i++)
	{
		if(posible[i])
		{
			c[*ncandidates] = i;
			(*ncandidates) ++;
		}
	}
}

void make_move(int a[], int k, boardtype* board)
{
	int i = board->move[k].x;
	int j = board->move[k].y;
	board->m[i][j] = a[k];
	board->freecount --;
}

void unmake_move(int a[], int k, boardtype* board)
{
	int i = board->move[k].x;
	int j = board->move[k].y;
	board->m[i][j] = 0;
	board->freecount ++;
}

void sudoku_backtrack(int a[], int k, boardtype *board)
{
	int c[9];
	int ncandidates;
	int i;

	if (is_a_solution(a,k,board))
	{
		process_solution(a,k,board);
		finished = true;
	}
	else
	{
		k++;
		construct_candidates(a, k, board, c, &ncandidates);
		for (i=0; i<ncandidates; i++)
		{
			a[k] = c[i];
			make_move(a,k,board);
			sudoku_backtrack(a,k,board);
			unmake_move(a,k,board);

			if(finished) return;
		}
	}
}