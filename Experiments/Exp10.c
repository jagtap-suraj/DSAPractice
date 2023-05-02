// AOA Experiment No. 10

#include <stdio.h>
#include <string.h>

int kmp(char pattern[], char text[])
{
    int m = strlen(pattern);
    int n = strlen(text);
    if (m == 0)
    {
        return 0;
    }
    int prefix_table[m];
    memset(prefix_table, 0, sizeof(prefix_table));
    int j = 0;
    for (int i = 1; i < m; i++)
    {
        while (j > 0 && pattern[j] != pattern[i])
        {
            j = prefix_table[j - 1];
        }
        if (pattern[j] == pattern[i])
        {
            j++;
        }
        prefix_table[i] = j;
    }
    j = 0;
    for (int i = 0; i < n; i++)
    {
        while (j > 0 && pattern[j] != text[i])
        {
            j = prefix_table[j - 1];
        }
        if (pattern[j] == text[i])
        {
            j++;
        }
        if (j == m)
        {
            return i - m + 1;
        }
    }
    return -1;
}

int main()
{
    char pattern[100];
    char text[1000];
    printf("Enter the pattern to search for: ");
    scanf("%s", pattern);
    printf("Enter the text to search in: ");
    scanf("%s", text);
    int index = kmp(pattern, text);
    if (index == -1)
    {
        printf("The pattern '%s' was not found in the text '%s'.\n", pattern, text);
    }
    else
    {
        printf("The pattern '%s' was found in the text '%s' starting at index %d.\n", pattern, text, index);
    }
    return 0;
}
