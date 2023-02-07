#include<stdio.h>
#include<stdlib.h>

int queens(int**, int , int);
void display(int**, int);
int isSafe(int**, int, int, int);
int min(int, int);

int main()
{
    int n = 4, i, j;
    // printf("Enter the No. of Queens: ");
    // scanf("%d", &n);
    //create a 2D array of size n*n
    int** board = (int**)malloc(n * sizeof(int*));
    for(i = 0; i < n; i++)
    {
        board[i] = (int*)malloc(n * sizeof(int));
    }
   printf("%d", queens(board, n, 0));
}

int queens(int** board, int n, int row)
{
    int col;
    if(row == n)
    {
        display(board, n);
        return 1;
    }

    int count = 0;

    //here we are placing the queen and checking for every row and column
    for(col = 0; col < n; col++)
    {
        //place the queen if it is safe
        if (isSafe(board, n, row, col))
        {
            board[row][col] = 1;
            count += queens(board, n, row + 1);
            board[row][col] = 0;
        }
    }

    return count;
}

int isSafe(int** board, int n, int row, int col)
{
    //check vertical row
    int i;
    for(i = 0; i < row; i++)
    {
        if(board[i][col] == 1)
            return 0;
    }

    //diagonal left
    int maxLeft = min(row, col);
    for(i = 1; i < maxLeft; i++)
    {
        if(board[row - i][col - i] == 1)
            return 0;
    }

    //diagonal right
    int maxRight = min(row, n - col - 1);
    for(i = 1; i < maxRight; i++)
    {
        if(board[row - i][col + i] == 1)
            return 0;
    }

    return 1;
}

void display(int** board, int n)
{
    int row, col;
    for(row = 0; row < n; row++)
    {
        for(col = 0; col < n; col++)
        {
            if(board[row][col] == 1)
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