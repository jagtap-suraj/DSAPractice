// AOA Practical Exam Q1

// Implementation of Selection sort and its analysis.

#include <stdio.h>
#include <conio.h>

int pass = 0, comp = 0, swap = 0;

void selectionSort(int a[], int n)
{
    int i, j, k, temp;

    for (i = 0; i < n; i++)
    {
        //pass++;
        for (j = k = i; j < n; j++)
        {
            comp++;
            if (a[j] < a[k])
                k = j;
        }
        temp = a[k];
        a[k] = a[i];
        a[i] = temp;
        swap++;
    }
}


int main()
{
        int i, n, a[50];
    //clrscr();
    printf("\nEnter the total no. of elements: ");
    scanf("%d", &n);
    printf("Enter the array elements: ");
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);

    selectionSort(a, n);

    printf("\nSorted Array:\n");
    for (i = 0; i < n; i++)
        printf("%d ", a[i]);

    //printf("\n\nNumber of passes: %d\n", pass);
    printf("\n\nNumber of comparisons: %d\n", comp);
    printf("Number of swaps: %d\n", swap);

    //getch();
    return 0;
}