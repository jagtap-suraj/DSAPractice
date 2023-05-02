// AOA Experiment No. 09

#include <stdio.h>
#include <string.h>

#define MAX_LEN 100

void lcs(char *s1, char *s2, char *result)
{
    int m = strlen(s1);
    int n = strlen(s2);

    int lcs_matrix[m + 1][n + 1];
    for (int i = 0; i <= m; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            if (i == 0 || j == 0)
            {
                lcs_matrix[i][j] = 0;
            }
            else if (s1[i - 1] == s2[j - 1])
            {
                lcs_matrix[i][j] = lcs_matrix[i - 1][j - 1] + 1;
            }
            else
            {
                lcs_matrix[i][j] = (lcs_matrix[i - 1][j] > lcs_matrix[i][j - 1]) ? lcs_matrix[i - 1][j] : lcs_matrix[i][j - 1];
            }
        }
    }

    int lcs_length = lcs_matrix[m][n];
    int i = m, j = n;
    while (i > 0 && j > 0)
    {
        if (s1[i - 1] == s2[j - 1])
        {
            result[--lcs_length] = s1[i - 1];
            i--;
            j--;
        }
        else if (lcs_matrix[i - 1][j] > lcs_matrix[i][j - 1])
        {
            i--;
        }
        else
        {
            j--;
        }
    }
}

int main()
{
    char s1[MAX_LEN], s2[MAX_LEN], result[MAX_LEN];
    printf("Enter the first string: ");
    scanf("%s", s1);
    printf("Enter the second string: ");
    scanf("%s", s2);
    lcs(s1, s2, result);
    printf("The longest common subsequence is: %s\n", result);
    return 0;
}
