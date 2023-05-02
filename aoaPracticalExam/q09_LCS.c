// Longest Common Subsequence using Dynamic Programming

#include <stdio.h>
#include <string.h>
//#include <conio.h>

int max(int a, int b)
{
    return (a > b) ? a : b;
}

int lcs(char S1[20], char S2[20], char S3[20]) //s3 to store the lcs
{
    int m = strlen(S1);
    int n = strlen(S2);
    int db[30][30];
    int i, j, index; //index to store the length of lcs

    for (i = 0; i <= m; i++)
        db[i][0] = 0; //initializing first column with 0

    for (j = 0; j <= n; j++)
        db[0][j] = 0; //initializing first row with 0

    // fill remaining values in the bottom-up manner using recursion
    for (i = 1; i <= m; i++) // we begin with 2nd row and go column by column
        for (j = 1; j <= n; j++)
            if (S1[i - 1] == S2[j - 1])
                db[i][j] = db[i - 1][j - 1] + 1;
            else
                db[i][j] = max(db[i - 1][j], db[i][j - 1]);
    
    // printing the lcs
    index = db[m][n];
    S3[index] = '\0'; //setting the terminating character
    i = m;
    j = n;
    while (i > 0 && j > 0)
    {
        if (S1[i - 1] == S2[j - 1])
        {
            S3[index - 1] = S1[i - 1];
            i--;
            j--;
            index--;
        }
        else if (db[i - 1][j] > db[i][j - 1])
            i--;
        else
            j--;
    }
    printf("Sequence is: %s\n", S3);
    return db[m][n];
}

int main()
{
    char S1[20], S2[20], S3[20];
    //clrscr();
    printf("Enter 1st sequence:");
    scanf("%s", S1);
    printf("Enter 2nd sequence:");
    scanf("%s", S2);

    printf("\nThe Longest Common Subsequence is %d", lcs(S1, S2, S3));
    //getch();
    return 0;
}

/*
Output:
Enter 1st sequence:abcbdab
Enter 2nd sequence:bdcaba

The Longest Common Subsequence is 4
*/
