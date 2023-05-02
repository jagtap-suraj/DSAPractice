// AOA Experiment No. 01

#include <stdio.h>

int itr = 0, comp = 0;

void initialise(int a[], int n);
void display(int a[], int n);
void swap(int *x, int *y);
void selectionSort(int a[], int n);
void insertionSort(int a[], int n);

int main()
{
    int a[100], n, ch;
    printf("\nEnter the number of elements: ");
    scanf("%d", &n);
    initialise(a, n);
    printf("1. Selection Sort\n2. Insertion Sort\nEnter your choice: ");
    scanf("%d", &ch);
    switch (ch)
    {
    case 1:
        selectionSort(a, n);
        break;
    case 2:
        insertionSort(a, n);
        break;
    default:
        printf("Invalid choice!\n");
    }
    printf("\nSorted array:\n");
    display(a, n);
    printf("\nNumber of iterations: %d\nNumber of comparisons: %d\n", itr, comp);
    printf("Time Complexity: %d", itr + comp);
    printf("\n ");
    return 0;
}

void initialise(int a[], int n)
{
    int i;
    printf("Enter the elements: ");
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);
}

void display(int a[], int n)
{
    int i;
    for (i = 0; i < n; i++)
        printf("%d ", a[i]);
    printf("\n");
}

void swap(int *x, int *y)
{
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

void selectionSort(int a[], int n)
{
    int i, j, k;
    for (i = 0; i < n - 1; i++)
    {
        itr++;
        for (j = k = i; j < n; j++)
        {
            if (a[j] < a[k])
                k = j;
            comp++;
        }
        swap(&a[i], &a[k]);
    }
}

void insertionSort(int a[], int n)
{
    int i, x, j;
    for (i = 0; i < n; i++)
    {
        x = a[i];
        itr++;
        for (j = i - 1; j > -1 && a[j] > x; j--)
        {
            a[j + 1] = a[j];
            comp++;
        }
        a[j + 1] = x;
    }
}
