// AOA Experiment No. 03

//Merge Sort

#include <stdio.h>
#include <conio.h>

int itr = 0, comp = 0;

void initialise(int a[], int n);
void display(int a[], int n);
void merge(int a[], int l, int mid, int h);
void mergeSort(int a[], int l, int h);

int main()
{
    int a[50], n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    initialise(a, n);
    mergeSort(a, 0, n - 1);
    printf("Sorted Array:\n");
    display(a, n);
    printf("\nTime Complexity: %d", itr + comp);
    getch();
    return 0;
}

void initialise(int a[], int n)
{
    int i;
    printf("Enter the elements:\n");
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);
}

void display(int a[], int n)
{
    int i;
    for (i = 0; i < n; i++)
        printf("%d ", a[i]);
}

void merge(int a[], int l, int mid, int h)
{
    int b[100];
    int i = l, j = mid + 1, k = l;
    while (i <= mid && j <= h)
    {
        if (a[i] < a[j])
            b[k++] = a[i++];
        else
            b[k++] = a[j++];
        comp++;
    }
    for (; i <= mid; i++)
        b[k++] = a[i];
    for (; j <= h; j++)
        b[k++] = a[j];
    for (i = l; i <= h; i++)
        a[i] = b[i];
}

void mergeSort(int a[], int l, int h)
{
    int mid;
    if (l < h)
    {
        itr++;
        mid = (l + h) / 2;
        mergeSort(a, l, mid);
        mergeSort(a, mid + 1, h);
        merge(a, l, mid, h);
    }
}
