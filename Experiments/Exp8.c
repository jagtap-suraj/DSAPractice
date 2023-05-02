// AOA Experiment No. 08

#include <stdio.h>
#include <limits.h>
#define MAX_N 16

int n;
int graph[MAX_N][MAX_N];
int all_sets;
int memo[1 << MAX_N][MAX_N];

int tsp_dp(int curr, int visited)
{
    if (visited == all_sets)
    {
        return graph[curr][0];
    }
    if (memo[visited][curr] != -1)
    {
        return memo[visited][curr];
    }
    int min_cost = INT_MAX;
    for (int city = 0; city < n; city++)
    {
        if (!(visited & (1 << city)))
        {
            int cost = graph[curr][city] + tsp_dp(city, visited | (1 << city));
            min_cost = (cost < min_cost) ? cost : min_cost;
        }
    }
    memo[visited][curr] = min_cost;
    return min_cost;
}

int main()
{
    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter the adjacency matrix:\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &graph[i][j]);
        }
    }

    all_sets = (1 << n) - 1;
    for (int i = 0; i < (1 << MAX_N); i++)
    {
        for (int j = 0; j < MAX_N; j++)
        {
            memo[i][j] = -1;
        }
    }

    int min_cost = tsp_dp(0, 1);

    printf("Minimum cost of the Travelling Salesperson Problem: %d\n", min_cost);

    return 0;
}
