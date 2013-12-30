
#include "sudoku.h"

void main()
{
	int data[][9] = {
		{1,0,0, 4,0,0, 0,0,0},
		{0,5,0, 0,0,0, 0,2,0},
		{0,0,0, 0,9,0, 0,0,0},

		{0,0,0, 0,0,0, 0,0,0},
		{0,0,0, 0,0,0, 0,0,0},
		{0,6,0, 0,0,0, 0,0,0},

		{0,0,0, 0,0,0, 0,0,0},
		{0,0,0, 0,0,0, 0,0,0},
		{0,0,0, 0,0,0, 0,0,0}
	};
	boardtype board;
	board.m = data;
	board.freecount = 0;

	for (int i = 0; i!=9; i++)
	{
		for (int j = 0; j!=9; j++)
			if(board.m[i][j] == 0) board.freecount ++;
	}

	int a[81];
	int k = -1;
	sudoku_backtrack(a,k,&board);
}
