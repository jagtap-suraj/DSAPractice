// AOA Practical Exam Q4

// Implementation of Quick sort and its analysis.

#include <stdio.h>
//#include <conio.h>

void quickSort(int a[], int l, int h)
{
    if (l < h)
    {
        int i = l, j = h, pivot = a[l], temp;
        do
        {
            do {i++;} while (a[i] <= pivot);
            do {j--;} while (a[j] > pivot);
            if (i < j)
            {
                temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        } while (i < j);
        temp = a[l];
        a[l] = a[j];
        a[j] = temp;
        quickSort(a, l, j);
        quickSort(a, j + 1, h);
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

    quickSort(a, 0, n);

    printf("\nSorted Array:\n");
    for (i = 0; i < n; i++)
        printf("%d ", a[i]);

    //getch();
    return 0;
}

