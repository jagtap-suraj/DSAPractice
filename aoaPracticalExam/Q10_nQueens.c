#include <stdio.h>
#include <stdbool.h>
// #include <conio.h>

int board[20][20];

void printMatrix(int board[20][20], int n) {
    int i, j;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

int isSafe(int row, int col, int n) {
    int i, j;
    // Check this row on left side
    for (i = 0; i < col; i++) {
        if (board[row][i]) {
            return 0;
        }
    }

    // Check upper diagonal on left side
    for (i = row, j = col; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j]) {
            return 0;
        }
    }

    // Check lower diagonal on left side
    for (i = row, j = col; j >= 0 && i < n; i++, j--) {
        if (board[i][j]) {
            return 0;
        }
    }

    return 1;
}

int solveRec(int col, int n, int* count) {
    if (col >= n) {
        // Found a solution, print it and increment the counter
        printMatrix(board, n);
        (*count)++;
        return 1;
    }
    int found_solution = 0;
    for (int i = 0; i < n; i++) {
        if (isSafe(i, col, n)) {
            board[i][col] = 1;
            found_solution |= solveRec(col + 1, n, count);
            board[i][col] = 0;
        }
    }
    return found_solution;
}

int solve(int n) {
    int count = 0;
    if (solveRec(0, n, &count) == 0) {
        printf("Solution does not exist\n");
        return 0;
    }
    printf("Number of solutions: %d\n", count);
    return 1;
}

int main() {
    int n;
    // clrscr();
    printf("Enter the value of N: ");
    scanf("%d", &n);
    solve(n);
    // getch();
    return 0;
}
