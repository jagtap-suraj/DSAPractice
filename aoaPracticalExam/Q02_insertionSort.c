// AOA Practical Exam Q2

// Implementation of Insertion sort and its analysis.

#include <stdio.h>
//#include <conio.h>

int pass = 0, comp = 0, swap = 0;

void insertionSort(int a[], int n)
{
    int i, j, x;
    for (i = 1; i < n; i++)
    {
        x = a[i];
        j = i - 1;
        pass++;
        while (j > -1 && a[j] > x)
        {
            comp++;
            swap++;
            a[j + 1] = a[j];
            j--;
        }
        comp++;
        a[j + 1] = x;
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

    insertionSort(a, n);

    printf("\nSorted Array:\n");
    for (i = 0; i < n; i++)
        printf("%d ", a[i]);

    printf("\n\nNumber of passes: %d\n", pass);
    printf("Number of comparisons: %d\n", comp);
    printf("Number of swaps: %d\n", swap);

    //getch();
    return 0;
}
