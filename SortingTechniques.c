#include <stdio.h>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void bubbleSort(int a[], int n)
{
    int i, j, flag = 0;
    for(i = 0; i < n - 1; i++)
    {
        for(j = 0; j < n - 1 - i; j++)
        {
            if(a[j] > a[j+1])
            {
                swap(&a[j], &a[j+1]);
                flag = 1;
            }
        }
        if(flag == 0)
            return;
    }
}

void insertionSort(int a[], int n)
{
    int i, j, x;
    for(i = 1; i < n; i++)
    {
        x = a[i];
        for(j = i - 1; a[j] > x && j > -1; j--)
        {
            a[j+1] = a[j];
        }
        a[j+1] = x;
    }
}

int main() {
    int a[] = {11, 13, 7, 2, 6, 9, 4, 5, 10, 3}, n = 10, i;
    
    bubbleSort(a, n);
    for(i = 0; i < n; i++)
        printf("%d ", a[i]);

    return 0;
}