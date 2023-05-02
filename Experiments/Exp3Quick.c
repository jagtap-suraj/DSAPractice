// AOA Experiment No. 03

// Quick Sort

#include <stdio.h>
#include <conio.h>

int itr = 0, comp = 0;

void initialise(int a[], int n);
void display(int a[], int n);
void swap(int *x, int *y);
int partition(int a[], int l, int h);
void QuickSort(int A[], int l, int h);

int main()
{
    int i, a[50], n = 1;
    printf("Enter the no. of elements: ");
    scanf("%d", &n);
    initialise(a, n);
    QuickSort(a, 0, n - 1);
    printf("Sorted Array:\n");
    display(a, n);
    int basic_ops = comp + 2 * itr;
    printf("\nEstimated Time Complexity: O(n log_n)\n");
    printf("Actual Time Complexity: %d", basic_ops);
    return 0;
}

void initialise(int a[], int n)
{
    int i;
    printf("Enter the elements:\n");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
}

void display(int a[], int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
}

void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

int partition(int a[], int l, int h)
{
    int pivot = a[l];
    int i = l, j = h;
    do
    {
        do
        {
            i++;
        } while (a[i] < pivot);
        do
        {
            j--;
        } while (a[j] > pivot);
        if (i < j)
        {
            swap(&a[i], &a[j]);
        }
    } while (i < j);

    swap(&a[l], &a[j]);
    return j; //
}

void QuickSort(int A[], int l, int h)
{
    int j;
    if (l < h)
    {
        j = partition(A, l, h);
        QuickSort(A, l, j);
        QuickSort(A, j + 1, h);
    }
}
