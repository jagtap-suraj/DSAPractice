// AOA Practical Exam Q3

// Implementation of Merge sort and its analysis.

#include <stdio.h>
//#include <conio.h>

void mergeSort(int a[], int l, int h)
{
    if (l < h)
    {
        int mid = (l + h) / 2;
        mergeSort(a, l, mid);
        mergeSort(a, mid + 1, h);
        int i = l, j = mid + 1, k = l, b[50];
        while (i <= mid && j <= h)
        {
            if (a[i] < a[j])
                b[k++] = a[i++];
            else
                b[k++] = a[j++];
        }

        for (; i <= mid; i++)
            b[k++] = a[i];
        for (; j <= h; j++)
            b[k++] = a[j];
        for (i = l; i <= h; i++)
            a[i] = b[i];
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

    mergeSort(a, 0, n-1);

    printf("\nSorted Array:\n");
    for (i = 0; i < n; i++)
        printf("%d ", a[i]);

    //getch();
    return 0;
}
