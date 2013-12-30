#ifndef SUDOKU_H
#define SUDOKU_H

typedef struct
{
	int x,y;
}point;

typedef struct
{
	int (*m)[9];
	int freecount;
	point move[81];
}boardtype;

extern bool is_a_solution           (int a[], int k, boardtype *board);
extern void process_solution        (int a[], int k, boardtype *board);
extern void construct_candidates    (int a[], int k, boardtype *board, int *c, int *ncandidates);	            
extern void make_move               (int a[], int k, boardtype* board);	      					            
extern void unmake_move             (int a[], int k, boardtype* board);
extern void sudoku_backtrack        (int a[], int k, boardtype *board);

#endif