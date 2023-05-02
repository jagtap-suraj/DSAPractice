// AOA Experiment No. 04

#include <stdio.h>
#include <stdlib.h>

float greedyKnapsack(int n, int m, int profit[], int weight[]);

int main()
{
    int n, m, i;
    float tp;
    printf("Enter the number of objects: ");
    scanf("%d", &n);
    printf("Enter the capacity of knapsack: ");
    scanf("%d", &m);
    int weight[n], profit[n];
    for (i = 0; i < n; i++)
    {
        printf("Enter the weight of object %d: ", i + 1);
        scanf("%d", &weight[i]);
        printf("Enter the profit of object %d: ", i + 1);
        scanf("%d", &profit[i]);
    }
    tp = greedyKnapsack(n, m, profit, weight);
    printf("Maximum profit: %f\n", tp);
    return 0;
}

float greedyKnapsack(int n, int m, int profit[], int weight[])
{
    int i, j;
    float tp = 0.0, u = m, x[n], pbyw[n];
    for (i = 0; i < n; i++)
    {
        pbyw[i] = (float)profit[i] / weight[i];
    }
    for (i = 0; i < n - 1; i++) // n-1 i s
    {
        for (j = 0; j < n - i - 1; j++) // till n-i-1 because last i elements are already in place
        {
            if (pbyw[j] < pbyw[j + 1]) //
            {
                float temp = pbyw[j];
                pbyw[j] = pbyw[j + 1];
                pbyw[j + 1] = temp;
                temp = profit[j];
                profit[j] = profit[j + 1];
                profit[j + 1] = temp;
                temp = weight[j];
                weight[j] = weight[j + 1];
                weight[j + 1] = temp;
            }
        }
    }
    for (i = 0; i < n; i++)
    {
        x[i] = 0.0;
    }
    for (i = 0; i < n; i++)
    {
        if (weight[i] > u)
        {
            break;
        }
        else
        {
            x[i] = 1.0;
            tp += profit[i];
            u -= weight[i];
        }
    }
    if (i < n)
    {
        x[i] = u / weight[i];
    }
    tp += (x[i] * profit[i]);
    return tp;
}
