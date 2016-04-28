/*
Write a program to generate elements of a matrix in spiral order.
Store the generated elements in single dimensional array and return that array.

Directions for Spiral are : Go Right ,Go Down ,Go Left, Go Up
Ex:

Matrix:
1	2	3
4	5	6
7	8	9

Spiral order:
1	2	3	6	9	8	7	4	5

Given matrix is a two dimensional array(input_array) with dimensions rows, columns.
If rows, columns are invalid then return NULL.
If input_array is NULL then return NULL.

Example Input :
int board[2][3]={
				 {4,6,7},
				 {1,3,8}
				};
spiral(2,2,(int **)board); // Rows followed by columns followed by board

Example Output : Return an array consisting of {4,6,7,8,3,1};

Note : Check the function Parameters ,Its a double pointer .

*/


#include "stdafx.h"
#include<stdlib.h>

int lr = 0, td = 1, rl = 2, bt = 3;
void spiralMatrix(int **mat, int ir, int fr, int ic, int fc, int te, int v, int dir)
{

	if (v != te)
	{


		int c = 0;
		switch (dir)
		{
		case 0:
			for (int col = ic; col <= fc; col++)
			{
				c++;
			}
			spiralMatrix(mat, ir + 1, fr, ic, fc, te, v + c, td);
			break;
		case 1:
			for (int row = ir; row<fr; row++)
			{
				printf("%d ", mat[row][fc]);
				c++;
			}
			spiralMatrix(mat, ir, fr, ic, fc - 1, te, v + c, rl);
			break;
		case 2:
			for (int col = fc; col >= ic; col--)
			{
				printf("%d ", mat[fr][col]);
				c++;
			}
			spiralMatrix(mat, ir + 1, fr - 1, ic, fc, te, v + c, bt);
			break;
		case 3:
			for (int row = fr; row >= ir; row--)
			{
				c++;
			}
			spiralMatrix(mat, ir, fr, ic + 1, fc, te, v, td);
			break;
		}
	}
}


int *spiral(int rows, int columns, int **input_array)
{


	int ir = 0, ic = 0, fr = rows - 1, fc = columns - 1, te = rows*columns, dir = 0, v = 0;
	spiralMatrix((int**)input_array, ir, fr, ic, fc, te, v, dir);
	return *(input_array);
}