#include<stdio.h>
#include<stdbool.h>
#include<string.h>
// #include<conio.h>

void fillLPS(char string[20], int lps[20])
{
    int n = strlen(string);
    int len = 0;
    lps[0] = 0;
    int i = 1;
    while(i < n)
    {
        if(string[i] == string[len])
        {
            len++;
            lps[i] = len;
            i++;
        }
        else
        {
            if(len != 0) {len = lps[len - 1];}
            else {lps[i] = 0; i++;}
        }
    }  
}

void kmp(char pattern[20], char text[40])
{
    int m = strlen(pattern);
    int n = strlen(text);
    int lps[m];
    fillLPS(pattern, lps);
    int i = 0, j = 0;
    while(i < n)
    {
        if(pattern[j] == text[i]) {i++; j++;}
        if(j == m)
        {
            printf("Pattern found at index %d\n", i - j);
            j = lps[j - 1];
        }
        else if(i < n && pattern[j] != text[i])
        {
            if(j != 0) {j = lps[j - 1];}
            else {i++;}
        }
    }
}

int main()
{
    char text[40], pattern[20];
    // clrscr();
    printf("Enter the text: ");
    scanf("%s", text);
    printf("Enter the pattern: ");
    scanf("%s", pattern);
    kmp(pattern, text);
    //getch();
    return 0;
}

/*
Output:
Enter the text: ababcabcabababd
Enter the pattern: ababd
Pattern found at index 10
*/