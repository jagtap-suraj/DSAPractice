//NQueens Problem

#include<stdio.h>
#include<stdlib.h>
#define max 20

int queens(int[][max], int, int);
int isSafe(int[][max], int, int, int);
void display(int[][max], int);
int min(int, int);


int main()
{
    int n, i, j, board[max][max];
    printf("Enter the number of queens: ");
    scanf("%d", &n);
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
        {
            board[i][j] = 0;
        }
    }
    printf("Number of Ways: %d\n", queens(board, n, 0));
    return 0;
}

int queens(int board[][max], int n, int row)
{
    int col, count = 0;
    if(row == n)
    {
        display(board, n);
        return 1;
    }

    for(col = 0; col < n; col++) 
    {
        if(isSafe(board, n, row, col))
        {
            board[row][col] = 1;
            count += queens(board, n, row + 1);
            board[row][col] = 0;
        }
    }
    return count;
}

int isSafe(int board[][max], int n, int row, int col)
{
    int i;
    // column
    for(i = 0; i < row; i++)
    {
        if(board[i][col])
            return 0;
    }

    // diagonal left
    int maxLeft = min(row, col);
    for(i = 1; i <= maxLeft; i++)
    {
        if(board[row - i][col - i])
            return 0;
    }

    // diagonal right
    int maxRight = min(row, n - col - 1);
    for(i = 1; i <= maxRight; i++)  
    {
        if(board[row - i][col + i])
            return 0;
    }
    return 1;
}

void display(int board[][max], int n)
{
    int row, col;
    for(row = 0; row < n; row++)
    {
        for(col = 0; col < n; col++)
        {
            if(board[row][col])
                printf("Q ");
            else
                printf("_ ");
        }
        printf("\n");
    }
    printf("\n");
}

int min(int x, int y)
{
    return (x < y) ? x : y;
}