// AOA Practical Exam Q5

// Implementation of Merge sort and its analysis.

#include<stdio.h>
#include<stdlib.h>

void sort(int profit[], int weight[], int n)
{
    int i, j, temp;
    float ratio[50];

    for(i = 0; i < n; i++)
        ratio[i] = (float)profit[i] / weight[i];

    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n - i - 1; j++)
        {
            if(ratio[j+1] > ratio[j])
            {
                temp = ratio[j+1];
                ratio[j+1] = ratio[j];
                ratio[j] = temp;

                temp = profit[j+1];
                profit[j+1] = profit[j];
                profit[j] = temp;

                temp = weight[j+1];
                weight[j+1] = weight[j];
                weight[j] = temp;
            }
        }
    }
}

float greedyKnapsack(int profit[], int weight[], int n, int capacity)
{
    float maxProfit = 0.0;
    int i;

    for(i = 0; i < n; i++)
    {
        if(weight[i] <= capacity)
        {
            maxProfit = maxProfit + profit[i];
            capacity = capacity - weight[i];
        }
        else
        {
            maxProfit = maxProfit + (float)profit[i] * capacity / weight[i];
            break;
        }
    }

    return maxProfit;
}

//Following function can be excluded
void displayTable(int profit[], int weight[], int n)
{
    int i;

    printf("\nItem\tProfit\tWeight\n");
    for(i = 0; i < n; i++)
    {
        printf("%d\t%d\t%d\n", i+1, profit[i], weight[i]);
    }
}

int main()
{
    int i, n, capacity, profit[n], weight[n];
    //clrscr();

    printf("\nEnter the number of items: ");
    scanf("%d", &n);

    printf("\nEnter the profit and weight of each item:\n");
    for(i = 0; i < n; i++)
        scanf("%d %d", &profit[i], &weight[i]);

    printf("\nEnter the total capacity of the knapsack: ");
    scanf("%d", &capacity);

    displayTable(profit, weight, n); //this line can be excluded

    sort(profit, weight, n);

    printf("\nMaximum profit: %.2f", greedyKnapsack(profit, weight, n, capacity));

    //getch();
    return 0;
}

/*
Enter the number of items: 3

Enter the profit and weight of each item: 
120 30
100 20
60 10

Enter the capacity of the knapsack: 50*/